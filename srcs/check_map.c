/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:45:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:18 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_filename(t_data *data, char *str)
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
		end_program(data, WRONG_MAP_NAME, WRONG_MAP_NAME_MSG);
	if (ft_strncmp(MAP_FILE_EXTENSION,
			&filename[filename_len - extension_len], extension_len) != 0)
		end_program(data, WRONG_MAP_NAME, WRONG_MAP_NAME_MSG);
}

char	*skip_head_tail_empty_lines(char *map)
{
	while (*map == '\n')
		map++;
	while ((*map != '\0' || *(map + 1) != '\0')
		&& (*map != '\n' || *(map + 1) != '\n'))
		map++;
	while (*map == '\n')
		map++;
	return (map);
}

bool	check_empty_line(char *map)
{
	size_t	i;

	map = skip_head_tail_empty_lines(map);
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

void	get_file_content(t_data *data, char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		end_program(data, FAILED_AT_OPENING_MAP, FAILED_AT_OPENING_MAP_MSG);
	content = read_all(fd);
	if (content == NULL)
	{
		close(fd);
		end_program(data, FAILED_AT_READING_MAP, FAILED_AT_READING_MAP_MSG);
	}
	close(fd);
	if (check_empty_line(content) == false)
	{
		free(content);
		end_program(data, HAS_EMPTY_LINE, HAS_EMPTY_LINE_MSG);
	}
	data->map.array = ft_split(content, '\n');
	free(content);
	if (data->map.array == NULL)
		end_program(data, FAILED_ON_MALLOC, FAILED_ON_MALLOC_MSG);
}

void	check_map(t_data *data, char *filename)
{
	data->map.array = NULL;
	check_filename(data, filename);
	get_file_content(data, filename);
	check_content(data);
	are_map_playble(data);
}
