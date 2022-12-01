/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:46:33 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/01 15:44:49 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_line_content(t_map *map, char *line, size_t y)
{
	size_t	x;

	x = 0;
	while (x < map->width)
	{
		if ((x == 0 && line[x] == WALL) 
			|| (x == map->width - 1 && line[x] == WALL)
			|| line[x] == EMPTY)
			;
		else if (line[x] == PLAYER && map->has_player == false)
		{
			map->start_pos.x = x;
			map->start_pos.y = y;
			map->has_player = true;
		}
		else if (line[x] == COLLECTIBLE)
			map->nbr_of_collectibles++;
		else if (line[x] == EXIT && map->has_exit == false)
		{
			map->exit_pos.x = x;
			map->exit_pos.y = y;
			map->has_exit = true;
		}
		else
			return (false);
		x++;
	}
	return (true);
}

bool	are_there_only_walls(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	check_content(t_map *map)
{
	size_t	i;

	map->width = ft_strlen(map->array[0]);
	if (map->width < 3 || are_there_only_walls(map->array[0]) == false)
		return (false);
	i = 1;
	map->has_player = false;
	map->has_exit = false;
	while (map->array[i + 1] != NULL)
	{
		if (ft_strlen(map->array[i]) != map->width)
			return (false);
		if (check_line_content(map, map->array[i], i) == false)
			return (false);
		i++;
	}
	if (are_there_only_walls(map->array[i]) == false)
		return (false);
	map->height = i + 1;
	if (map->height < 3 || map->nbr_of_collectibles < 1
		|| map->has_player == false || map->has_exit == false)
		return (false);
	return (true);
}
