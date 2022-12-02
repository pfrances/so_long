/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:47 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/02 18:23:33 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_moves(t_data *data, size_t x, size_t y)
{
	t_map	*map;

	map = &data->map;
	if (map->array[y][x] == WALL)
		return ;
	if (map->array[y][x] == EXIT && map->nbr_of_collectibles == 0)
		end_game(data);
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
	printf("moves count: %ld\n", ++data->move_count);
}

int	deal_key(int key, t_data *data)
{
	if (key == XK_Escape)
		end_game(data);
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

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_map(data);
	return (0);
}

void	put_in_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask,
		&end_game, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &deal_key, data);
	mlx_loop(data->mlx_ptr);
}
