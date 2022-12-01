/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:24:47 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/01 22:16:40 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_data(t_data *data)
{
	data->bsize = 100;
	data->window_width = data->map.width * data->bsize;
	data->window_height = data->map.height * data->bsize;
	data->move_count = 0;
	data->pos.x = data->map.start_pos.x * data->bsize;
	data->pos.y = data->map.start_pos.y * data->bsize;
}

bool	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (false);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width,
			data->window_height, "so_long");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->win_ptr);
		return (false);
	}
	return (true);
}

bool	init(t_data *data, int argc, char *argv[])
{
	if (argc != 2)
		return (false);
	if (check_map(&data->map, argv[1]) == false)
	{
		if (data->map.array != NULL)
			free_map(data->map.array);
		return (false);
	}
	init_data(data);
	if (init_window(data) == false)
	{
		free_map(data->map.array);
		return (false);
	}
	if (images_init(data) == false)
		return (false);
	put_in_loop(data);
	return (true);
}
