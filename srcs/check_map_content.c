/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:46:33 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/02 08:34:34 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_this_object_ok(t_map *map, char c, size_t x, size_t y)
{
	if ((x == 0 && c != WALL)
		|| (x == map->width - 1 && c != WALL))
		return (false);
	else if (c == WALL || c == EMPTY)
		;
	else if (c == PLAYER && map->has_player == false)
	{
		map->start_pos.x = x;
		map->start_pos.y = y;
		map->has_player = true;
	}
	else if (c == COLLECTIBLE)
		map->nbr_of_collectibles++;
	else if (c == EXIT && map->has_exit == false)
	{
		map->exit_pos.x = x;
		map->exit_pos.y = y;
		map->has_exit = true;
	}
	else
		return (false);
	return (true);
}

bool	check_line_content(t_map *map, char *line, size_t y)
{
	size_t	x;

	x = 0;
	while (x < map->width)
	{
		if (is_this_object_ok(map, line[x], x, y) == false)
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
	map->nbr_of_collectibles = 0;
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
