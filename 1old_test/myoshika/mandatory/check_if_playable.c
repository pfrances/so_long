/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_playable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:40:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/21 18:42:24 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_square(size_t y, size_t x, t_config *g)
{
	if (g->map_dup[y][x] == '1')
		return (false);
	else if (g->map_dup[y][x] == 'C')
		g->reachable_collectibles++;
	else if (g->map_dup[y][x] == 'E')
		g->reachable_exit = true;
	return (true);
}

static void	search_all_directions(size_t y, size_t x, t_config *g)
{
	if (!check_square(y, x, g))
		return ;
	else
		g->map_dup[y][x] = '1';
	search_all_directions(y, x + 1, g);
	search_all_directions(y, x - 1, g);
	search_all_directions(y + 1, x, g);
	search_all_directions(y - 1, x, g);
}

void	check_if_playable(t_config *g)
{
	search_all_directions(g->player_y, g->player_x, g);
	if (!g->reachable_exit
		|| g->reachable_collectibles != g->num_of_collectibles)
		g->map_error = NO_VALID_PATH;
	free_map(g->map_dup);
	if (g->map_error == NO_VALID_PATH)
	{
		free_map(g->map);
		print_err_and_exit("map not playable");
	}
}
