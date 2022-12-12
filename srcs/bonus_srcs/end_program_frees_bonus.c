/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_frees_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:02:10 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 14:03:09 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map_array)
{
	size_t	i;

	i = 0;
	while (map_array[i] != NULL)
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
}

void	free_all_img(t_data *data, t_error error)
{
	if (error > WALL_IMG_MALLOC_FAILED)
		free(data->wall_img);
	if (error > PLAYER_IMG_MALLOC_FAILED)
		free(data->player_img);
	if (error > PLAYER_ON_EXIT_IMG_MALLOC_FAILED)
		free(data->player_on_exit_img);
	if (error > COLLECTIBLE_IMG_MALLOC_FAILED)
		free(data->collectible_img);
	if (error > EXIT_IMG_MALLOC_FAILED)
		free(data->exit_img);
	if (error > EMPTY_IMG_MALLOC_FAILED)
		free(data->empty_img);
	if (error > ENEMY_IMG_MALLOC_FAILED)
		free(data->enemy_img);
	if (error > ENEMY_ON_EXIT_IMG_MALLOC_FAILED)
		free(data->enemy_on_exit_img);
	if (error > BOTTOM_IMG_MALLOC_FAILED)
		free(data->bottom_img);
	if (error > GAME_OVER_IMG_MALLOC_FAILED)
		free(data->game_over_img);
}
