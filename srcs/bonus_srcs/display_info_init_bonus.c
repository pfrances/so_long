/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info_init_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:37:09 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 15:53:11 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	set_colors(t_data *data)
{
	data->move_count.color = WHITE;
	data->timer.color = WHITE;
	data->enemies_speed.color = WHITE;
}

void	set_display_info_position(t_data *data)
{
	size_t	y_pos;

	y_pos = data->window_height - 5;
	data->move_count.title_str_pos.x = 10;
	data->move_count.title_str_pos.y = y_pos;
	data->move_count.value_pos.x = data->move_count.title_str_pos.x + 60;
	data->move_count.value_pos.y = y_pos;
	data->timer.title_str_pos.x = data->window_width / 2;
	data->timer.title_str_pos.y = y_pos;
	data->timer.value_pos.x = data->timer.title_str_pos.x + 40;
	data->timer.value_pos.y = y_pos;
	data->enemies_speed.title_str_pos.x = data->window_width - 130;
	data->enemies_speed.title_str_pos.y = y_pos;
	data->enemies_speed.value_pos.x = data->enemies_speed.title_str_pos.x + 90;
	data->enemies_speed.value_pos.y = y_pos;
}

void	set_titles_str(t_data *data)
{
	data->move_count.title_str = STEPS_COUNT_MSG;
	data->timer.title_str = TIMER_MSG;
	data->enemies_speed.title_str = ENEMIES_SPEED_MSG;
}

void	display_info_init(t_data *data)
{
	data->info_value_buff = malloc(sizeof(char) * (SIZE_MAX_DIGITS + 1));
	if (data->info_value_buff == NULL)
		end_program(data, INFO_BUFF_MALLOC_FAILED, FAILED_ON_MALLOC_MSG);
	set_colors(data);
	set_display_info_position(data);
	set_titles_str(data);
}
