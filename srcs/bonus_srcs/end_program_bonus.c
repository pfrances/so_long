/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:47:22 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 18:34:47 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_error_messages(char *error_msg)
{
	ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
}

void	destroy_images_from_array(t_data *data, t_img *img, t_error error)
{
	size_t	i;

	i = 0;
	while (img[i].last == false && error > img[i].error)
	{
		mlx_destroy_image(data->mlx_ptr, img[i].mlx_img);
		i++;
	}
	if (error > img[i].error)
		mlx_destroy_image(data->mlx_ptr, img[i].mlx_img);
}

void	destroy_images(t_data *data, t_error error)
{
	if (error >= INIT_WALL1_IMG_FAILED)
		destroy_images_from_array(data, data->wall_img, error);
	if (error >= INIT_PLAYER1_IMG_FAILED)
		destroy_images_from_array(data, data->player_img, error);
	if (error >= INIT_PLAYER_ON_EXIT1_IMG_FAILED)
		destroy_images_from_array(data, data->player_on_exit_img, error);
	if (error >= INIT_COLLECTIBLE_IMG_FAILED)
		destroy_images_from_array(data, data->collectible_img, error);
	if (error >= INIT_EXIT_IMG_FAILED)
		destroy_images_from_array(data, data->exit_img, error);
	if (error >= INIT_EMPTY_IMG_FAILED)
		destroy_images_from_array(data, data->empty_img, error);
	if (error >= INIT_ENEMY1_IMG_FAILED)
		destroy_images_from_array(data, data->enemy_img, error);
	if (error >= INIT_ENEMY_ON_EXIT1_IMG_FAILED)
		destroy_images_from_array(data, data->enemy_on_exit_img, error);
	if (error >= INIT_BOTTOM_IMG_FAILED)
		destroy_images_from_array(data, data->bottom_img, error);
	if (error >= INIT_GAME_OVER_IMG_FAILED)
		destroy_images_from_array(data, data->game_over_img, error);
	free_all_img(data, error);
}

int	cross_button_event(t_data *data)
{
	end_program(data, NONE, NULL);
	return (0);
}

void	end_program(t_data *data, t_error error, char *error_msg)
{
	if (error != NONE)
		print_error_messages(error_msg);
	if (error >= NOT_BORDERED_BY_WALL && error != RESET_MAP_MALLOC_FAILED)
		free_map(data->map.array);
	if (error >= INIT_WALL1_IMG_FAILED)
	{
		destroy_images(data, error);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (error > INITIAL_MAP_MALLOC_FAILED)
		free_map(data->map.initial_map);
	if (error > INIT_MLX_FAILED)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->map.enemies);
	}
	if (error > INFO_BUFF_MALLOC_FAILED)
		free(data->info_value_buff);
	exit(error < NONE);
}
