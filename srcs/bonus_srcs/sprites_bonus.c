/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:38:16 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 10:39:04 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	deal_sprites(t_data *data)
{
	if (get_time(data->start_time)
		< data->last_sprite_time + SPRITE_TIMING)
		return ;
	data->sprite_cnt++;
	data->last_sprite_time = get_time(data->start_time);
}

t_img	find_enemy_sprite(t_data *data, size_t enemy_x, size_t enemy_y)
{
	size_t		i;
	t_enemy		*enemy;
	t_position	*exit_pos;
	size_t		img_nb;

	enemy = data->map.enemies;
	exit_pos = &data->map.exit_pos;
	i = 0;
	while (i < data->map.nb_enemies)
	{
		if (enemy[i].pos.x == enemy_x && enemy[i].pos.y == enemy_y)
		{
			if (enemy[i].direction == LEFT || enemy[i].direction == DOWN)
				img_nb = 0;
			else
				img_nb = 1;
			if (enemy_x == exit_pos->x && enemy_y == exit_pos->y)
				return (data->enemy_on_exit_img[img_nb]);
			else
				return (data->enemy_img[img_nb]);
		}
		i++;
	}
	return (data->enemy_img[0]);
}
