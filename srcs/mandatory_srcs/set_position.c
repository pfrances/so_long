/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:47:15 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/08 15:54:36 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_position(t_position *position, size_t x, size_t y)
{
	if (position == NULL)
		return ;
	position->x = x;
	position->y = y;
}
