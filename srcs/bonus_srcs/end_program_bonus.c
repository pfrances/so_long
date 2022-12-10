/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:47:22 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/10 17:57:22 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_error_messages(char *error_msg)
{
	ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
}

void	free_map(char **map_array)
{
	size_t	i;

	i = 0;
	while (map_array[i] != NULL)
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
}

void	destroy_images(t_data *data, t_error error)
{
	if (error >= FAILED_AT_INIT_WALL_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->wall_img.mlx_img);
	if (error >= FAILED_AT_INIT_PLAYER_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->player_img.mlx_img);
	if (error >= FAILED_AT_INIT_PLAYER_ON_INIT_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->player_on_exit_img.mlx_img);
	if (error >= FAILED_AT_INIT_COLLECTIBLES_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->collectible_img.mlx_img);
	if (error >= FAILED_AT_INIT_EXIT_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->exit_img.mlx_img);
	if (error >= FAILED_AT_INIT_EMPTY_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->empty_img.mlx_img);
	if (error >= FAILED_AT_INIT_ENEMY_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->enemy_img.mlx_img);
	if (error >= FAILED_AT_INIT_ENEMY_ON_EXIT_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->enemy_on_exit_img.mlx_img);
	if (error >= FAILED_AT_INIT_BOTTOM_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->bottom_img.mlx_img);
	if (error >= FAILED_AT_INIT_GAMEOVER_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->game_over_img.mlx_img);
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
	if ((error >= NOT_BORDERED_BY_WALL && error != FAILED_ON_MALLOC_RESET_MAP)
		|| error == NONE)
		free_map(data->map.array);
	if (error >= FAILED_AT_INIT_WALL_IMG || error == NONE)
	{
		destroy_images(data, error);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (error > FAILED_ON_MALLOC_INITIAL_MAP || error == NONE)
		free_map(data->map.initial_map);
	if (error >= FAILED_AT_INIT_WINDOW || error == NONE)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->map.enemies);
	}
	if (error > FAILED_ON_MALLOC_MOVE_COUNT || error == NONE)
		free(data->move_count_str);
	if (error > FAILED_ON_MALLOC_ENEMIES_SPEED || error == NONE)
		free(data->enemies_speed_str);
	exit(error > NONE);
}
