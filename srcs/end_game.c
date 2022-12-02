/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/02 19:49:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

void	destroy_images(t_data *data, t_error error)
{
	if (error >= FAILED_AT_INIT_WALL_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->wall_img.mlx_img);
	if (error >= FAILED_AT_INIT_PLAYER_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->player_img.mlx_img);
	if (error >= FAILED_AT_INIT_COLLECTIBLES_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->collectible_img.mlx_img);
	if (error >= FAILED_AT_INIT_EXIT_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->exit_img.mlx_img);
	if (error >= FAILED_AT_INIT_EMPTY_IMG || error == NONE)
		mlx_destroy_image(data->mlx_ptr, data->empty_img.mlx_img);
}

int	end_game(t_data *data)
{
	free_map(data->map.array);
	destroy_images(data, NONE);
	destroy_window(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

bool	errors_gestion(t_data *data, t_error error, char *error_msg)
{
	if (error != NONE)
		printf("%s\n%s\n", ERROR_MSG, error_msg);
	if (error >= NOT_BORDERED_BY_WALL)
		free_map(data->map.array);
	if (error >= FAILED_AT_INIT_WALL_IMG)
	{
		destroy_images(data, error);
		destroy_window(data);
	}
	if (error >= FAILED_AT_INIT_WINDOW)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(error > NONE);
	return (false);
}
