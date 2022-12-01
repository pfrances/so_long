/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:02:05 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/01 14:13:56 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_background(t_data *data, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->bsize)
	{
		x = 0;
		while (x < data->bsize)
		{
			img_pix_put(img, x, y, GREEN_PIXEL);
			x++;
		}
		y++;
	}
	return (0);
}

bool	set_background(t_data *data, t_img *img)
{
	img->mlx_img = mlx_new_image(data->mlx_ptr, data->bsize, data->bsize);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	return (img->mlx_img != NULL);
}

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
	if (set_background(data, &data->empty_img) == false)
		return (false);
	render_background(data, &data->empty_img);
	return (true);
}
