/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:02:05 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/11 12:17:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	set_xpm_img(void *mlx_ptr, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	return (img->mlx_img != NULL);
}

void	images_init(t_data *data)
{
	if (set_xpm_img(data->mlx_ptr, &data->wall_img, WALL_XPM_PATH) == false)
		end_program(data, FAILED_AT_INIT_WALL_IMG, FAILED_AT_INIT_IMGS_MSG);
	if (set_xpm_img(data->mlx_ptr, &data->player_img, PLAYER_XPM_PATH) == false)
		end_program(data, FAILED_AT_INIT_PLAYER_IMG, FAILED_AT_INIT_IMGS_MSG);
	if (set_xpm_img(data->mlx_ptr, &data->player_on_exit_img,
			PLAYER_ON_EXIT_XPM_PATH) == false)
		end_program(data, FAILED_AT_INIT_PLAYER_IMG, FAILED_AT_INIT_IMGS_MSG);
	if (set_xpm_img(data->mlx_ptr, &data->collectible_img,
			COLLECTIBLE_XPM_PATH) == false)
		end_program(data, FAILED_AT_INIT_COLLECTIBLES_IMG,
			FAILED_AT_INIT_IMGS_MSG);
	if (set_xpm_img(data->mlx_ptr, &data->exit_img, EXIT_XPM_PATH) == false)
		end_program(data, INIT_EXIT_IMG_FAILED, FAILED_AT_INIT_IMGS_MSG);
	if (set_xpm_img(data->mlx_ptr, &data->empty_img, EMPTY_XPM_PATH) == false)
		end_program(data, INIT_EMPTY_IMG_FAILED, FAILED_AT_INIT_IMGS_MSG);
}
