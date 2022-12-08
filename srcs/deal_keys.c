/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:47:44 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/08 11:52:08 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_moves(t_data *data, size_t x, size_t y)
{
	t_map	*map;

	map = &data->map;
	if (map->array[y][x] == WALL)
		return ;
	ft_printf("moves count: %ld\n", ++data->move_count);
	if (map->array[y][x] == EXIT && map->nbr_of_collectibles == 0)
		end_program(data, NONE, NULL);
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
		end_program(data, FAILED_ON_MALLOC_RESET_MAP, FAILED_ON_MALLOC_MSG);
	data->map.player_pos = data->map.player_initial_pos;
	data->map.nbr_of_collectibles = data->map.initial_nbr_of_collectibles;
}

int	deal_keys(int key, t_data *data)
{
	if (key == XK_Escape)
		end_program(data, NONE, NULL);
	if (key == RESET)
		reset_game(data);
	if (key == XK_w)
		player_moves(data, data->map.player_pos.x, data->map.player_pos.y - 1);
	if (key == XK_a)
		player_moves(data, data->map.player_pos.x - 1, data->map.player_pos.y);
	if (key == XK_s)
		player_moves(data, data->map.player_pos.x, data->map.player_pos.y + 1);
	if (key == XK_d)
		player_moves(data, data->map.player_pos.x + 1, data->map.player_pos.y);
	return (0);
}
