/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:30:40 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/10 18:16:01 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	change_direction(t_data *data, t_enemy *enemy, size_t x, size_t y)
{
	t_direction	new_direction;

	while (data->map.array[y][x] == WALL || data->map.array[y][x] == ENEMY)
	{
		new_direction = rand() % 4;
		x_y_by_direction(enemy->pos, new_direction, &x, &y);
	}
	enemy->direction = new_direction;
	enemies_moves(data, enemy, x, y);
}

void	enemies_moves(t_data *data, t_enemy *enemy, size_t x, size_t y)
{
	t_map	*map;

	map = &data->map;
	if (map->array[y][x] == WALL || map->array[y][x] == ENEMY)
		return (change_direction(data, enemy, x, y));
	if (map->array[y][x] == PLAYER)
		display_game_over(data);
	if (enemy->pos.x == map->exit_pos.x && enemy->pos.y == map->exit_pos.y)
		map->array[enemy->pos.y][enemy->pos.x] = EXIT;
	else if (enemy->on_collectible == true)
		map->array[enemy->pos.y][enemy->pos.x] = COLLECTIBLE;
	else
		map->array[enemy->pos.y][enemy->pos.x] = EMPTY;
	if (map->array[y][x] == EMPTY || map->array[y][x] == EXIT)
	{
		map->array[y][x] = ENEMY;
		enemy->on_collectible = false;
	}
	else if (map->array[y][x] == COLLECTIBLE)
	{
		map->array[y][x] = ENEMY;
		enemy->on_collectible = true;
	}
	enemy->pos.x = x;
	enemy->pos.y = y;
}

bool	can_move(t_data *data, t_enemy *enemy)
{
	if (data->map.array[enemy->pos.y][enemy->pos.x + 1] != WALL
		&& data->map.array[enemy->pos.y][enemy->pos.x + 1] != ENEMY)
		return (true);
	if (data->map.array[enemy->pos.y][enemy->pos.x - 1] != WALL
		&& data->map.array[enemy->pos.y][enemy->pos.x - 1] != ENEMY)
		return (true);
	if (data->map.array[enemy->pos.y + 1][enemy->pos.x] != WALL
		&& data->map.array[enemy->pos.y + 1][enemy->pos.x] != ENEMY)
		return (true);
	if (data->map.array[enemy->pos.y - 1][enemy->pos.x] != WALL
		&& data->map.array[enemy->pos.y - 1][enemy->pos.x] != ENEMY)
		return (true);
	return (false);
}
