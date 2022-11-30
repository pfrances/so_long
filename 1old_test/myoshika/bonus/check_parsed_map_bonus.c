/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:42:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/21 18:42:24 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_num_of_cep(t_config *g)
{
	if (g->map_error != MAP_OK)
		return ;
	if (g->num_of_collectibles < 1 || g->num_of_exits != 1
		|| g->num_of_players != 1)
		g->map_error = WRONG_CEP;
}

void	check_if_rectangle(t_config *g)
{
	if (g->map_error != MAP_OK)
		return ;
	if (g->map_height == g->map_width)
		g->map_error = WRONG_MAP_SHAPE;
}

void	check_basic_requirements(t_config *g)
{
	if (g->map_error != MAP_OK)
		return ;
	if (g->map_height < 3 || g->map_width < 3)
		g->map_error = INVALID_MAP_FORMATTING;
}

void	check_for_walls(t_config *g)
{
	size_t	i;

	if (g->map_error != MAP_OK)
		return ;
	i = 0;
	while (g->map[0][i] != '\n' && g->map[0][i] != '\0')
	{
		if (g->map[0][i] != '1')
			g->map_error = NO_WALLS;
		i++;
	}
	i = 1;
	while (g->map[i] && i < g->map_height - 1)
	{
		if (g->map[i][0] != '1' || g->map[i][g->map_width - 1] != '1')
			g->map_error = NO_WALLS;
		i++;
	}
	i = 0;
	while (g->map[g->map_height - 1][i] != '\0')
	{
		if (g->map[g->map_height - 1][i] != '1')
			g->map_error = NO_WALLS;
		i++;
	}
}
