/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:46:53 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/11 12:11:56 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_floor(t_map *map, size_t x, size_t y)
{
	if (map->flood_floor_array[y][x] == WALL
		|| map->flood_floor_array[y][x] == 'X')
		return ;
	map->flood_floor_array[y][x] = 'X';
	flood_floor(map, x + 1, y);
	flood_floor(map, x - 1, y);
	flood_floor(map, x, y + 1);
	flood_floor(map, x, y - 1);
}

bool	flooded_floor_check(char **array)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (array[y] != NULL)
	{
		x = 0;
		while (array[y][x] != '\0')
		{
			if (array[y][x] == EXIT || array[y][x] == COLLECTIBLE)
			{
				free_map(array);
				return (false);
			}
			x++;
		}
		y++;
	}
	free_map(array);
	return (true);
}

void	are_map_playble(t_data *data)
{
	t_map	*map;

	map = &data->map;
	map->flood_floor_array = array_duplicate(map->array);
	if (map->flood_floor_array == NULL)
		end_program(data, FLOODED_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	flood_floor(map, map->player_pos.x, map->player_pos.y);
	if (flooded_floor_check(map->flood_floor_array) == false)
		end_program(data, MAP_NOT_PLAYABLE, MAP_NOT_PLAYABLE_MSG);
}
