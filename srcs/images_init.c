/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:02:05 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/02 10:07:27 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	set_xpm_img(void *mlx_ptr, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	img->addr = mlx_get_data_addr(img->mlx_img,
			&img->bpp, &img->line_len, &img->endian);
	return (img->mlx_img != NULL);
}

bool	images_init(t_data *data)
{
	if (set_xpm_img(data->mlx_ptr, &data->wall_img, WALL_XPM_PATH) == false)
		return (false);
	if (set_xpm_img(data->mlx_ptr, &data->player_img, PLAYER_XPM_PATH) == false)
		return (false);
	if (set_xpm_img(data->mlx_ptr, &data->collectible_img,
			COLLECTIBLE_XPM_PATH) == false)
		return (false);
	if (set_xpm_img(data->mlx_ptr, &data->exit_img, EXIT_XPM_PATH) == false)
		return (false);
	if (set_xpm_img(data->mlx_ptr, &data->empty_img, EMPTY_XPM_PATH) == false)
		return (false);
	return (true);
}
