/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:46:53 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/06 15:38:24 by pfrances         ###   ########.fr       */
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
	size_t	i;
	t_map	*map;

	map = &data->map;
	map->flood_floor_array = malloc(sizeof(char *) * (map->height + 1));
	if (map->flood_floor_array == NULL)
		end_program(data, FAILED_ON_MALLOC_FLOODED, FAILED_ON_MALLOC_MSG);
	i = 0;
	while (i < map->height)
	{
		map->flood_floor_array[i] = ft_strdup(map->array[i]);
		if (map->flood_floor_array == NULL)
		{
			while (i--)
				free(map->flood_floor_array[i]);
			free(map->flood_floor_array);
			end_program(data, FAILED_ON_MALLOC_FLOODED, FAILED_ON_MALLOC_MSG);
		}
		i++;
	}
	map->flood_floor_array[i] = NULL;
	flood_floor(map, map->player_pos.x, map->player_pos.y);
	if (flooded_floor_check(map->flood_floor_array) == false)
		end_program(data, MAP_NOT_PLAYABLE, MAP_NOT_PLAYABLE_MSG);
}
