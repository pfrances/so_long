/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_tools_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:47:15 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/10 11:00:10 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	set_position(t_position *position, size_t x, size_t y)
{
	if (position == NULL)
		return ;
	position->x = x;
	position->y = y;
}

void	x_y_by_direction(t_position position, t_direction direction,
	size_t *x, size_t *y)
{
	*x = position.x;
	*y = position.y;
	if (direction == LEFT)
		*x -= 1;
	else if (direction == RIGHT)
		*x += 1;
	else if (direction == UP)
		*y -= 1;
	else if (direction == DOWN)
		*y += 1;
}
