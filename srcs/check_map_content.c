/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:46:33 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/06 16:44:57 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_objects_on_map(t_data *data, char c, size_t x, size_t y)
{
	if ((x == 0 && c != WALL)
		|| (x == data->map.width - 1 && c != WALL))
		end_program(data, NOT_BORDERED_BY_WALL, NOT_BORDERED_BY_WALL_MSG);
	else if (c == WALL || c == EMPTY)
		;
	else if (c == PLAYER)
	{
		if (data->map.has_player == true)
			end_program(data, TOO_MUCH_PLAYER, TO_MUCH_PLAYER_MSG);
		data->map.player_pos.x = x;
		data->map.player_pos.y = y;
		data->map.has_player = true;
	}
	else if (c == COLLECTIBLE)
		data->map.nbr_of_collectibles++;
	else if (c == EXIT)
	{
		if (data->map.has_exit == true)
			end_program(data, TO_MUCH_EXIT, TO_MUCH_EXIT_MSG);
		data->map.exit_pos.x = x;
		data->map.exit_pos.y = y;
		data->map.has_exit = true;
	}
	else
		end_program(data, UNDEFINED_CHARACTER, UNDEFINED_CHARACTER_MSG);
}

void	check_line_content(t_data *data, char *line, size_t y)
{
	size_t	x;

	x = 0;
	while (x < data->map.width)
	{
		check_objects_on_map(data, line[x], x, y);
		x++;
	}
}

void	check_there_are_only_walls(t_data *data, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != WALL)
			end_program(data, NOT_BORDERED_BY_WALL, NOT_BORDERED_BY_WALL_MSG);
		i++;
	}
}

void	check_content(t_data *data)
{
	size_t	i;

	data->map.width = ft_strlen(data->map.array[0]);
	if (data->map.width < 3)
		end_program(data, WRONG_SHAPE, WRONG_SHAPE_MSG);
	i = 0;
	data->map.has_player = false;
	data->map.has_exit = false;
	data->map.nbr_of_collectibles = 0;
	while (data->map.array[i] != NULL)
	{
		if (i != 0 && ft_strlen(data->map.array[i]) != data->map.width)
			end_program(data, WRONG_SHAPE, WRONG_SHAPE_MSG);
		if (i == 0 || data->map.array[i + 1] == NULL)
			check_there_are_only_walls(data, data->map.array[i]);
		else
			check_line_content(data, data->map.array[i], i);
		i++;
	}
	data->map.height = i;
	if (data->map.height < 3)
		end_program(data, WRONG_SHAPE, WRONG_SHAPE_MSG);
	if (data->map.nbr_of_collectibles < 1)
		end_program(data, HAS_NO_COLLECTIBLE, HAS_NO_COLLECTIBLE_MSG);
}
