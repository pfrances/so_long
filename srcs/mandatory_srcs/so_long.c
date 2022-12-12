/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:24:13 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 17:28:04 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_window_size(t_data *data)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(data->mlx_ptr, &screen_width, &screen_height);
	data->window_height = data->map.height * BSIZE;
	if (data->window_height > screen_height)
		end_program(data, MAP_TOO_HIGH, MAP_TOO_HIGH_MSG);
	data->window_width = data->map.width * BSIZE;
	if (data->window_width > screen_width)
		end_program(data, MAP_TOO_WIDE, MAP_TOO_WIDE_MSG);
}

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		end_program(data, INIT_MLX_FAILED, FAILED_AT_INIT_MLX_MSG);
	check_window_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width,
			data->window_height, "so_long");
	if (data->win_ptr == NULL)
		end_program(data, INIT_WINDOW_FAILED, FAILED_AT_INIT_WINDOW_MSG);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		end_program(&data, WRONG_NB_OF_ARGS, WRONG_NB_OF_ARGS_MSG);
	check_map(&data, argv[1]);
	init_window(&data);
	images_init(&data);
	put_in_loop(&data);
	return (0);
}
