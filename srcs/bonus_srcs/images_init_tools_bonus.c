/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init_tools_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:14:53 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 14:13:23 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	set_xpm_img(t_data *data, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img->path,
			&img->width, &img->height);
	if (img->mlx_img == NULL)
		end_program(data, img->error, img->error_msg);
}

void	set_img_info(t_img *img, char *path, t_error error)
{
	img->path = path;
	img->error = error;
	img->error_msg = FAILED_AT_INIT_IMGS_MSG;
}

t_img	*image_allocation(t_data *data, size_t nb,
	t_error error, char *error_msg)
{
	t_img	*img;
	size_t	i;

	img = malloc(sizeof(t_img) * nb);
	if (img == NULL)
		end_program(data, error, error_msg);
	i = 0;
	while (i < nb)
	{
		if (i < nb - 1)
			img[i].last = false;
		else
			img[i].last = true;
		i++;
	}
	return (img);
}
