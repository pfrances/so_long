/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:47 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/10 16:27:37 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_one_image(t_data *data, size_t x, size_t y, t_img img)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img.mlx_img, x * BSIZE, y * BSIZE);
}

void	put_images(t_data *data, size_t x, size_t y)
{
	if (data->map.array[y][x] == WALL)
		put_one_image(data, x, y, data->wall_img);
	else if (data->map.array[y][x] == EMPTY)
		put_one_image(data, x, y, data->empty_img);
	else if (data->map.array[y][x] == PLAYER)
	{
		if (x == data->map.exit_pos.x && y == data->map.exit_pos.y)
			put_one_image(data, x, y, data->player_on_exit_img);
		else
			put_one_image(data, x, y, data->player_img);
	}
	else if (data->map.array[y][x] == COLLECTIBLE)
		put_one_image(data, x, y, data->collectible_img);
	else if (data->map.array[y][x] == EXIT)
		put_one_image(data, x, y, data->exit_img);
	else if (data->map.array[y][x] == ENEMY)
	{
		if (x == data->map.exit_pos.x && y == data->map.exit_pos.y)
			put_one_image(data, x, y, data->enemy_on_exit_img);
		else
			put_one_image(data, x, y, data->enemy_img);
	}
}

int	render_map(t_data *data)
{
	size_t	x;
	size_t	y;

	if (data->win_ptr == NULL)
		return (1);
	y = 0;
	if (get_time(data->start_timings)
		> data->last_move_timings + data->enemies_speed)
		deal_enemies(data);
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

void	last_setup_before_loop(t_data *data)
{
	gettimeofday(&data->start_timings, NULL);
	data->last_move_timings = get_time(data->start_timings);
	data->last_reset_timings = data->last_move_timings;
	data->enemies_speed = DEFAULT_SPAWN_TIMING;
	data->move_count_str = malloc(sizeof(char) * (SIZE_MAX_DIGITS + 1));
	if (data->move_count_str == NULL)
		end_program(data, FAILED_ON_MALLOC_MOVE_COUNT,
			FAILED_ON_MALLOC_MSG);
	data->enemies_speed_str = malloc(sizeof(char) * (SIZE_MAX_DIGITS + 1));
	if (data->enemies_speed_str == NULL)
		end_program(data, FAILED_ON_MALLOC_ENEMIES_SPEED,
			FAILED_ON_MALLOC_MSG);
	set_display_info_position(data);
	display_infos(data);
}

void	put_in_loop(t_data *data)
{
	last_setup_before_loop(data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask,
		&cross_button_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &deal_keys, data);
	mlx_loop_hook(data->mlx_ptr, &render_map, data);
	mlx_loop(data->mlx_ptr);
}
