/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:24:13 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/07 12:59:03 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		end_program(data, FAILED_AT_INIT_MLX, FAILED_AT_INIT_MLX_MSG);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width,
			data->window_height, "so_long");
	if (data->win_ptr == NULL)
		end_program(data, FAILED_AT_INIT_WINDOW, FAILED_AT_INIT_WINDOW_MSG);
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
