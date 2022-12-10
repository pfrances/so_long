/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:19:06 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/09 16:49:49 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

size_t	get_time(struct timeval start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000000 + time.tv_usec)
			- (start.tv_sec * 1000000 + start.tv_usec)));
}
