/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_duplicate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:43:42 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/08 14:05:50 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

size_t	array_size(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

char	**array_duplicate(char **to_dup)
{
	size_t	i;
	char	**dup_map;

	if (to_dup == NULL)
		return (NULL);
	dup_map = malloc(sizeof(char *) * (array_size(to_dup) + 1));
	if (dup_map == NULL)
		return (NULL);
	i = 0;
	while (to_dup[i] != NULL)
	{
		dup_map[i] = ft_strdup(to_dup[i]);
		if (dup_map[i] == NULL)
		{
			while (i--)
				free(dup_map[i]);
			free(dup_map);
			return (NULL);
		}
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}
