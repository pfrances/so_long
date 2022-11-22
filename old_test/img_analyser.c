/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_analyser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:54:59 by pfrances          #+#    #+#             */
/*   Updated: 2022/10/01 15:27:27 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_analyser(t_data *data)
{
	int		fd;
	char	*str;
	t_xpm	wall;
	size_t	i;
	t_img	*img;

	fd = open("wall.xpm", O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("bonjour", STDOUT_FILENO);
	str = read_all(fd);
	i = 0;
	while (str[i++] != '"')
		;
	wall.width = ft_atoi(&str[i]);
	while (str[i++] != ' ')
		;
	wall.height = ft_atoi(&str[i++]);
	while (str[i++] != ' ')
		;
	wall.colors = ft_atoi(&str[i++]);
	while (str[i++] != ' ')
		;
	wall.char_per_pixel = ft_atoi(&str[i++]);

	printf("width : %ld | height : %ld | colors : %ld | char_pp : %ld\n",
	wall.width, wall.height, wall.colors, wall.char_per_pixel);
	while (str[i++] != ',')
		;
	int width = 25;
	int	height = 25;
	img = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm", &width, &height);
	printf("addr : %s | bpp : %d\n", img->addr, img->bpp);
//	ft_putstr_fd(str, STDOUT_FILENO);
}
