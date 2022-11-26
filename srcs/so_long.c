/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:24:13 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/26 20:26:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int deal_key(int key, t_data *data)
{
	// printf("PressKey : %d | XK_Escape : %d\n", key, XK_Escape);
	// if (key == XK_Escape)
	// {
	// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// 	data->win_ptr = NULL;
	// }
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	//printf("Keyrelease: %d\n", keysym);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img, j++, i, color);
		}
		++i;
	}
}

void	moving_square(t_data *data, int color)
{
	size_t	x;
	size_t	y;
	size_t	square_size;

	y = 0;
	square_size = 50;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			render_rect(&data->img, (t_rect){x, y, 100, 100, RED_PIXEL});
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
			sleep(1);
			render_rect(&data->img, (t_rect){x , y, 100, 100, BLACK_PIXEL});
			x += square_size;
		}
		y += square_size;
	}
}

int	render(t_data *data)
{

	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	moving_square(data, BLACK_PIXEL);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.wall.mlx_img = mlx_xpm_file_to_image(&data->mlx_ptr, W_PATH,
			&data->wall.width, &data->wall.height);
	data.wall.addr = mlx_get_data_addr(&data->wall.mlx_img, &data->wall.bpp,
			&data->wall->line_len, &data->wall.endian);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &deal_key, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
