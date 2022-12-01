/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:45:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/01 16:21:17 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_filename(char *str)
{
	size_t	filename_len;
	size_t	extension_len;
	char	*filename;

	filename = ft_strrchr(str, '/');
	if (filename == NULL)
		filename = str;
	else
		filename++;
	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(MAP_FILE_EXTENSION);
	if (filename_len <= extension_len)
		return (false);
	if (ft_strncmp(MAP_FILE_EXTENSION,
			&filename[filename_len - extension_len], extension_len) != 0)
		return (false);
	return (true);
}

bool	check_empty_line(char *map)
{
	size_t	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (i == 0 || map[i + 1] == '\n' || map[i + 1] == '\0')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	get_file_content(t_map *map, char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	content = read_all(fd);
	close(fd);
	if (content == NULL)
		return (false);
	if (check_empty_line(content) == false)
		return (false);
	map->array = ft_split(content, '\n');
	free(content);
	if (map->array == NULL)
		return (false);
	return (true);
}

bool	check_map(t_map *map, char *filename)
{
	if (check_filename(filename) == false)
		return (false);
	if (get_file_content(map, filename) == false)
		return (false);
	if (check_content(map) == false)
		return (false);
	// if (are_map_playble(map) == false)
	// 	return (false);
	printf("pass\n");
	return (true);
}
