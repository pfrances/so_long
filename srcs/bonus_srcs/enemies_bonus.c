/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:33:39 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 15:33:12 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	reset_enemies_pos(t_data *data)
{
	size_t	i;
	t_enemy	*enemies;

	i = 0;
	enemies = data->map.enemies;
	while (i < data->map.nb_enemies)
	{
		set_position(&enemies[i].pos,
			enemies[i].initial_pos.x, enemies[i].initial_pos.y);
		enemies[i].direction = rand() % 4;
		data->map.enemies[i].on_collectible = false;
		i++;
	}
}

void	set_initial_enemies_pos(t_data *data)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	y = 0;
	srand((unsigned) time(&data->time));
	while (data->map.array[y] != NULL)
	{
		x = 0;
		while (data->map.array[y][x] != '\0')
		{
			if (data->map.array[y][x] == ENEMY)
			{
				set_position(&data->map.enemies[i].initial_pos, x, y);
				set_position(&data->map.enemies[i].pos, x, y);
				data->map.enemies[i].direction = rand() % 4;
				data->map.enemies[i].on_collectible = false;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	data->map.nb_enemies = 0;
	while (data->map.array[y] != NULL)
	{
		x = 0;
		while (data->map.array[y][x] != '\0')
		{
			if (data->map.array[y][x] == ENEMY)
				data->map.nb_enemies++;
			x++;
		}
		y++;
	}
	if (data->map.nb_enemies == 0)
	{
		data->map.enemies = NULL;
		return ;
	}
	data->map.enemies = malloc(sizeof(t_enemy) * (data->map.nb_enemies));
	if (data->map.enemies == NULL)
		end_program(data, ENEMIES_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	set_initial_enemies_pos(data);
}

void	deal_enemies(t_data *data)
{
	size_t	i;
	size_t	x;
	size_t	y;
	t_enemy	*enemies;

	if (get_time(data->start_time) < data->last_move_time
		+ (data->enemies_speed.value / data->map.nb_enemies))
		return ;
	i = data->map.enemies_moves_turn_over % data->map.nb_enemies;
	enemies = data->map.enemies;
	if (can_move(data, &enemies[i]))
	{
		x_y_by_direction(enemies[i].pos, enemies[i].direction, &x, &y);
		enemies_moves(data, &enemies[i], x, y);
		if (rand() % 2 == 0)
			enemies[i].direction = rand() % 4;
	}
	data->map.enemies_moves_turn_over++;
	data->last_move_time = get_time(data->start_time);
}
