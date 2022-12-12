/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:47 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 15:51:08 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_one_image(t_data *data, size_t x, size_t y, t_img img)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img.mlx_img, x * BSIZE, y * BSIZE);
}

void	put_images(t_data *data, size_t x, size_t y, size_t cnt)
{
	if (data->map.array[y][x] == WALL)
		put_one_image(data, x, y, data->wall_img[cnt % NB_OF_WALL_IMG]);
	else if (data->map.array[y][x] == EMPTY)
		put_one_image(data, x, y, data->empty_img[cnt % NB_OF_EMPTY_IMG]);
	else if (data->map.array[y][x] == PLAYER)
	{
		if (x == data->map.exit_pos.x && y == data->map.exit_pos.y)
			put_one_image(data, x, y,
				data->player_on_exit_img[cnt % NB_OF_PLAYER_ON_EXIT_IMG]);
		else
			put_one_image(data, x, y, data->player_img[cnt % NB_OF_PLAYER_IMG]);
	}
	else if (data->map.array[y][x] == COLLECTIBLE)
		put_one_image(data, x, y, data->collectible_img[0]);
	else if (data->map.array[y][x] == EXIT)
		put_one_image(data, x, y, data->exit_img[cnt % NB_OF_EXIT_IMG]);
	else if (data->map.array[y][x] == ENEMY)
		put_one_image(data, x, y, find_enemy_sprite(data, x, y));
}

int	render_map(t_data *data)
{
	size_t	x;
	size_t	y;

	if (data->win_ptr == NULL)
		return (1);
	if (data->game_over == true)
		return (0);
	deal_enemies(data);
	deal_sprites(data);
	y = 0;
	while (y < data->map.height && data->game_over == false)
	{
		x = 0;
		while (x < data->map.width && data->game_over == false)
		{
			put_images(data, x, y, data->sprite_cnt);
			x++;
		}
		y++;
	}
	display_infos(data);
	return (0);
}

void	last_setup_before_loop(t_data *data)
{
	data->game_over = false;
	gettimeofday(&data->start_time, NULL);
	data->last_move_time = get_time(data->start_time);
	data->last_reset_time = get_time(data->start_time);
	data->last_sprite_time = get_time(data->start_time);
	data->enemies_speed.value = DEFAULT_SPAWN_TIMING;
	data->map.enemies_moves_turn_over = 0;
	display_info_init(data);
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
