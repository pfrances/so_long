/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:42:35 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/30 18:13:54 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_filename(char *filename)
{
	size_t	filename_len;
	size_t	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(MAP_FILE_EXTENSION);
	if (filename_len < extension_len + 1)
		return (false);
	if (ft_strncmp(MAP_FILE_EXTENSION,
		&filename[filename_len - extension_len], extension_len - 1) != 0)
		return (false);
	return (true);
}

bool	check_height(t_map *map, int fd)
{
	size_t	i;
	size_t	width;
	ssize_t	read_count;
	char	str[BUFFER_SIZE];

	map->height = 0;
	read_count = 0;
	while (read_count > 0 || map->height == 0)
	{
		ft_bzero(str, BUFFER_SIZE);
		read_count = read(fd, str, BUFFER_SIZE);
		if (read_count == -1)
			return (false);
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (str[i] == '\n' || str[i] == '\0')
				map->height++;
			if (str[i] == '\0')
				return (map->height >= 3);
			i++;
		}
	}
}
bool	check_width(t_map *map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map->array[0]);
	if (len < 3)
		return (false);
	i = 1;
	while (i < map->height)
	{
		if (ft_strlen(map->array[i]) != len)
			return (false);
		i++;
	}
	map->width = len - 1;
	return (true);
}

bool	check_map_content(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x] == WALL)
				;
			else if (map->array[y][x] == PLAYER)
			{
				map->start_pos.x = x;
				map->start_pos.y = y;
			}
			else if (map->array[y][x] == COLLECTIBLE)
				map->nbr_of_collectibles++;
			else if (map->array[y][x] == EMPTY)
				;
			else if (map->array[y][x] == EXIT)
				;
			else
				return (false);
			x++;
		}
		y++;
	}
}

bool	set_array(t_map *map, char *filename)
{
	size_t	i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	map->array = ft_calloc((map->height + 1), sizeof(char *));
	if (map->array == NULL)
	{
		close(fd);
		return (false);
	}
	i = 0;
	while (i < map->height)
	{
		map->array[i] = get_next_line(fd);
		if (map->array[i] == NULL && i != map->height - 1)
		{
			while (i > 0)
				free(map->array[i--]);
			free(map->array);
			close(fd);
			return (false);
		}
		i++;
	}
	close(fd);
	return (true);
}

bool	check_map(t_map *map, char *filename)
{
	int	fd;

	if (check_filename(filename) == false)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!check_height(map, fd))
		return (false);
	close(fd);
	if (!set_array(map, filename) || !check_width(map))
		return (false);
	if (check_map_content(map) == false)
		return (false);
	return (true);
}
