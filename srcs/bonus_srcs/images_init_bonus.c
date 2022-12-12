/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:02:05 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 14:13:06 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	set_all_img_infos(t_data *data)
{
	set_img_info(&data->wall_img[0], WALL1_XPM_PATH, INIT_WALL1_IMG_FAILED);
	set_img_info(&data->wall_img[1], WALL2_XPM_PATH, INIT_WALL2_IMG_FAILED);
	set_img_info(&data->player_img[0],
		PLAYER1_XPM_PATH, INIT_PLAYER1_IMG_FAILED);
	set_img_info(&data->player_img[1],
		PLAYER2_XPM_PATH, INIT_PLAYER2_IMG_FAILED);
	set_img_info(&data->player_on_exit_img[0],
		PLAYER_ON_EXIT1_XPM_PATH, INIT_PLAYER_ON_EXIT1_IMG_FAILED);
	set_img_info(&data->player_on_exit_img[1],
		PLAYER_ON_EXIT2_XPM_PATH, INIT_PLAYER_ON_EXIT2_IMG_FAILED);
	set_img_info(&data->collectible_img[0],
		COLLECTIBLE_XPM_PATH, INIT_COLLECTIBLE_IMG_FAILED);
	set_img_info(&data->exit_img[0], EXIT_XPM_PATH, INIT_EXIT_IMG_FAILED);
	set_img_info(&data->empty_img[0], EMPTY_XPM_PATH, INIT_EMPTY_IMG_FAILED);
	set_img_info(&data->enemy_img[0], ENEMY1_XPM_PATH, INIT_ENEMY1_IMG_FAILED);
	set_img_info(&data->enemy_img[1], ENEMY2_XPM_PATH, INIT_ENEMY2_IMG_FAILED);
	set_img_info(&data->enemy_on_exit_img[0],
		ENEMY_ON_EXIT1_XPM_PATH, INIT_ENEMY_ON_EXIT1_IMG_FAILED);
	set_img_info(&data->enemy_on_exit_img[1],
		ENEMY_ON_EXIT2_XPM_PATH, INIT_ENEMY_ON_EXIT2_IMG_FAILED);
	set_img_info(&data->bottom_img[0], BOTTOM_XPM_PATH, INIT_BOTTOM_IMG_FAILED);
	set_img_info(&data->game_over_img[0],
		GAME_OVER_XPM_PATH, INIT_GAME_OVER_IMG_FAILED);
}

void	prepare_all_img_allocations(t_data *data)
{
	data->wall_img = image_allocation(data, NB_OF_WALL_IMG,
			WALL_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->player_img = image_allocation(data, NB_OF_PLAYER_IMG,
			PLAYER_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->player_on_exit_img = image_allocation(data, NB_OF_PLAYER_ON_EXIT_IMG,
			PLAYER_ON_EXIT_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->collectible_img = image_allocation(data, NB_OF_COLLECTIBLE_IMG,
			COLLECTIBLE_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->exit_img = image_allocation(data, NB_OF_EXIT_IMG,
			EXIT_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->empty_img = image_allocation(data, NB_OF_EMPTY_IMG,
			EMPTY_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->enemy_img = image_allocation(data, NB_OF_ENEMY_IMG,
			ENEMY_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->enemy_on_exit_img = image_allocation(data, NB_OF_ENEMY_ON_EXIT_IMG,
			ENEMY_ON_EXIT_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->bottom_img = image_allocation(data, NB_OF_BOTTOM_IMG,
			BOTTOM_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	data->game_over_img = image_allocation(data, NB_OF_GAME_OVER_IMG,
			GAME_OVER_IMG_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
}

void	images_init(t_data *data)
{
	prepare_all_img_allocations(data);
	set_all_img_infos(data);
	set_xpm_img(data, &data->wall_img[0]);
	set_xpm_img(data, &data->wall_img[1]);
	set_xpm_img(data, &data->player_img[0]);
	set_xpm_img(data, &data->player_img[1]);
	set_xpm_img(data, &data->player_on_exit_img[0]);
	set_xpm_img(data, &data->player_on_exit_img[1]);
	set_xpm_img(data, &data->collectible_img[0]);
	set_xpm_img(data, &data->exit_img[0]);
	set_xpm_img(data, &data->empty_img[0]);
	set_xpm_img(data, &data->enemy_img[0]);
	set_xpm_img(data, &data->enemy_img[1]);
	set_xpm_img(data, &data->enemy_on_exit_img[0]);
	set_xpm_img(data, &data->enemy_on_exit_img[1]);
	set_xpm_img(data, &data->bottom_img[0]);
	set_xpm_img(data, &data->game_over_img[0]);
	data->sprite_cnt = 0;
}
