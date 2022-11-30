/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:00:47 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/30 16:40:43 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int key, t_data *data)
{
	printf("PressKey : %d | XK_Escape : %d\n", key, XK_Escape);
	if (key == XK_Escape)
	{
		end_game(data);
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_map(data);
	return (0);
}

bool	put_in_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask,
		&destroy_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &deal_key, data);
	mlx_loop(data->mlx_ptr);
}
