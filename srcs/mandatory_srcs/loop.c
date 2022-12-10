/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:47 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/09 09:26:38 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_images(t_data *data, size_t x, size_t y)
{
	if (data->map.array[y][x] == WALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img.mlx_img, x * BSIZE, y * BSIZE);
	else if (data->map.array[y][x] == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->empty_img.mlx_img, x * BSIZE, y * BSIZE);
	else if (data->map.array[y][x] == PLAYER)
	{
		if (x == data->map.exit_pos.x && y == data->map.exit_pos.y)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player_on_exit_img.mlx_img, x * BSIZE, y * BSIZE);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player_img.mlx_img, x * BSIZE, y * BSIZE);
	}
	else if (data->map.array[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible_img.mlx_img, x * BSIZE, y * BSIZE);
	else if (data->map.array[y][x] == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img.mlx_img, x * BSIZE, y * BSIZE);
}

int	render_map(t_data *data)
{
	size_t	x;
	size_t	y;

	if (data->win_ptr == NULL)
		return (1);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			put_images(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_in_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render_map, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask,
		&cross_button_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &deal_keys, data);
	mlx_loop(data->mlx_ptr);
}
