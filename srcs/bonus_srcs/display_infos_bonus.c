/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:32:13 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/10 10:27:14 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	nbr_to_dst_str(size_t nbr, char *dst)
{
	size_t	i;
	size_t	divisor;

	if (dst == NULL)
		return ;
	i = 0;
	divisor = 1;
	while (nbr / divisor >= 10)
		divisor *= 10;
	ft_bzero(dst, SIZE_MAX_DIGITS + 1);
	while (divisor > 0)
	{
		dst[i] = (nbr / divisor) + '0';
		nbr %= divisor;
		divisor /= 10;
		i++;
	}
}

void	us_to_sec_ms_char(size_t nbr, char *dst)
{
	size_t	len;

	nbr_to_dst_str(nbr, dst);
	if (dst == NULL)
		return ;
	len = ft_strlen(dst);
	if (len > 6)
	{
		dst[2] = dst[1];
		dst[1] = '.';
		dst[3] = ' ';
		dst[4] = 's';
		dst[5] = '\0';
	}
	else if (len == 6)
	{
		dst[3] = ' ';
		dst[4] = 'm';
		dst[5] = 's';
		dst[6] = '\0';
	}
}

void	set_display_info_position(t_data *data)
{
	size_t	y_pos;

	y_pos = data->window_height - 5;
	data->move_count_str_pos.x = 10;
	data->move_count_str_pos.y = y_pos;
	data->move_count_value_pos.x = data->move_count_str_pos.x + 60;
	data->move_count_value_pos.y = y_pos;
	data->enemies_speed_str_pos.x = data->window_width - 130;
	data->enemies_speed_str_pos.y = y_pos;
	data->enemies_speed_value_pos.x = data->enemies_speed_str_pos.x + 90;
	data->enemies_speed_value_pos.y = y_pos;
}

void	display_infos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->window_width)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bottom_img.mlx_img, i, data->window_height - SPACE_FOR_MSG);
		i += BSIZE;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->move_count_str_pos.x,
		data->move_count_str_pos.y, WHITE, STEPS_COUNT_MSG);
	nbr_to_dst_str(data->move_count, data->move_count_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->move_count_value_pos.x,
		data->move_count_value_pos.y, WHITE, data->move_count_str);
	if (data->map.nb_enemies > 0)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			data->enemies_speed_str_pos.x, data->enemies_speed_str_pos.y,
			WHITE, ENEMIES_SPEED_MSG);
		us_to_sec_ms_char(data->enemies_speed, data->enemies_speed_str);
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			data->enemies_speed_value_pos.x, data->enemies_speed_value_pos.y,
			WHITE, data->enemies_speed_str);
	}
}
