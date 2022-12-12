/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:32:13 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 19:03:27 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	display_game_over(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	sprite;

	data->game_over = true;
	x = ((data->window_width / 2) - 100) / BSIZE;
	y = ((data->window_height / 2) - 150) / BSIZE;
	sprite = data->last_sprite_time % NB_OF_GAME_OVER_IMG;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	put_one_image(data, x, y, data->game_over_img[sprite]);
}

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
		dst[len - 5] = dst[len - 6];
		dst[len - 6] = '.';
		dst[len - 4] = ' ';
		dst[len - 3] = 's';
		dst[len - 2] = '\0';
	}
	else if (len <= 6)
	{
		dst[3] = ' ';
		dst[4] = 'm';
		dst[5] = 's';
		dst[6] = '\0';
	}
}

void	display_one_info(t_data *data, t_info *info)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, info->title_str_pos.x,
		info->title_str_pos.y, info->color, info->title_str);
	if (ft_strncmp(info->title_str, MOVES_COUNT_MSG, 12) == 0)
		nbr_to_dst_str(info->value, data->info_value_buff);
	else
		us_to_sec_ms_char(info->value, data->info_value_buff);
	mlx_string_put(data->mlx_ptr, data->win_ptr, info->value_pos.x,
		info->value_pos.y, info->color, data->info_value_buff);
}

void	display_infos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.width)
	{
		put_one_image(data, i, data->map.height,
			data->bottom_img[data->last_sprite_time % NB_OF_BOTTOM_IMG]);
		i++;
	}
	data->timer.value = get_time(data->start_time);
	display_one_info(data, &data->move_count);
	display_one_info(data, &data->timer);
	if (data->map.nb_enemies > 0)
		display_one_info(data, &data->enemies_speed);
}
