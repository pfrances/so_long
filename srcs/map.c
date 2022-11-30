/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:02:42 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/30 17:19:02 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.array[y][x] == WALL)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall_img.mlx_img, x * data->bsize, y * data->bsize);
			else if (data->map.array[y][x] == EMPTY
				|| data->map.array[y][x] == PLAYER
				|| data->map.array[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->empty_img.mlx_img, x * data->bsize, y * data->bsize);
			if (data->map.array[y][x] == PLAYER)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->player_img.mlx_img, x * data->bsize, y * data->bsize);
			else if (data->map.array[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->collectible_img.mlx_img,
					x * data->bsize, y * data->bsize);
			else if (data->map.array[y][x] == EXIT)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->exit_img.mlx_img, x * data->bsize, y * data->bsize);
			x++;
		}
		y++;
	}
}

