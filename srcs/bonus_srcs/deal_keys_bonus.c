/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:47:44 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/13 17:57:24 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_moves(t_data *data, size_t x, size_t y)
{
	t_map	*map;

	map = &data->map;
	if (map->array[y][x] == WALL)
		return ;
	data->move_count.value++;
	if ((map->array[y][x] == EXIT && map->nbr_of_collectibles == 0)
		|| map->array[y][x] == ENEMY)
		display_game_over(data);
	else if (map->array[y][x] == EMPTY || map->array[y][x] == EXIT)
	{
		map->array[y][x] = PLAYER;
		map->array[map->player_pos.y][map->player_pos.x] = EMPTY;
	}
	else if (map->array[y][x] == COLLECTIBLE)
	{
		map->array[y][x] = PLAYER;
		map->array[map->player_pos.y][map->player_pos.x] = EMPTY;
		map->nbr_of_collectibles--;
	}
	if (map->player_pos.x == map->exit_pos.x
		&& map->player_pos.y == map->exit_pos.y)
		map->array[map->player_pos.y][map->player_pos.x] = EXIT;
	map->player_pos.x = x;
	map->player_pos.y = y;
}

void	reset_game(t_data *data)
{
	free_map(data->map.array);
	data->map.array = array_duplicate(data->map.initial_map);
	if (data->map.array == NULL)
		end_program(data, RESET_MAP_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->map.player_pos = data->map.player_initial_pos;
	data->map.nbr_of_collectibles = data->map.initial_nbr_of_collectibles;
	reset_enemies_pos(data);
	if (get_time(data->start_time)
		< data->last_reset_time + DOUBLE_R_TIMING)
		data->enemies_speed.value = DEFAULT_SPAWN_TIMING;
	gettimeofday(&data->start_time, NULL);
	data->last_reset_time = get_time(data->start_time);
	data->last_move_time = get_time(data->start_time);
	data->last_sprite_time = get_time(data->start_time);
	data->map.enemies_moves_turn_over = 0;
	data->move_count.value = 0;
	data->game_over = false;
}

void	teleport_to_start_pos(t_data *data)
{
	t_map	*map;

	map = &data->map;
	if (map->array[map->player_pos.y][map->player_pos.x] == ENEMY)
		return (display_game_over(data));
	if (map->player_pos.y == map->exit_pos.y
		&& map->player_pos.x == map->exit_pos.x)
		map->array[map->player_pos.y][map->player_pos.x] = EXIT;
	else
		map->array[map->player_pos.y][map->player_pos.x] = EMPTY;
	map->player_pos = map->player_initial_pos;
	map->array[map->player_pos.y][map->player_pos.x] = PLAYER;
}

int	deal_keys(int key, t_data *data)
{
	if (key == XK_Escape)
		end_program(data, NONE, NULL);
	else if (key == XK_Return && data->game_over == true)
		reset_game(data);
	else if (data->game_over == true)
		return (0);
	if (key == XK_r)
		reset_game(data);
	else if (key == XK_w)
		player_moves(data, data->map.player_pos.x, data->map.player_pos.y - 1);
	else if (key == XK_a)
		player_moves(data, data->map.player_pos.x - 1, data->map.player_pos.y);
	else if (key == XK_s)
		player_moves(data, data->map.player_pos.x, data->map.player_pos.y + 1);
	else if (key == XK_d)
		player_moves(data, data->map.player_pos.x + 1, data->map.player_pos.y);
	else if (key == XK_t)
		teleport_to_start_pos(data);
	else if (key == XK_Up && data->enemies_speed.value > ENEMIES_SPEED_MAX)
		data->enemies_speed.value -= ENEMIES_SPEED_STEP;
	else if (key == XK_Down && data->enemies_speed.value < ENEMIES_SPEED_MIN)
		data->enemies_speed.value += ENEMIES_SPEED_STEP;
	return (0);
}
