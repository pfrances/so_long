/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:46:53 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/01 16:59:49 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	flood_floor(t_map *map, int x, int y)
{
	if (map->flood_floor_array[y][x] == EXIT)
		return (true);
	if (map->flood_floor_array[y][x] == WALL 
		|| map->flood_floor_array[y][x] == 'X')
		return (false);
	map->flood_floor_array[y][x] = 'X';
	flood_floor(map, x + 1, y);
	flood_floor(map, x - 1, y);
	flood_floor(map, x, y + 1);
	flood_floor(map, x, y - 1);
	return (false);
}

bool	are_map_playble(t_map *map)
{
	size_t	i;
	bool	result;

	map->flood_floor_array = malloc(sizeof(char *) * (map->height + 1));
	i = 0;
	while (i < map->height)
	{
		map->flood_floor_array[i] = ft_strdup(map->array[i]);
		if (map->flood_floor_array == NULL)
		{
			while (i--)
				free(map->flood_floor_array[i]);
			free(map->flood_floor_array);
			return (false);
		}
		i++;
	}
	map->flood_floor_array[i] = NULL;
	result = flood_floor(map, map->start_pos.x, map->start_pos.y);
	free_map(map->flood_floor_array);
	return (result);
}
