/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:25:15 by pfrances          #+#    #+#             */
/*   Updated: 2022/10/01 13:18:47 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#define BUFFER_SIZE 1024
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300
#define BLACK_PIXEL 0x000000
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_xpm
{
	size_t	width;
	size_t	height;
	size_t	colors;
	size_t	char_per_pixel;
	char	**pixels;
}	t_xpm;

typedef struct s_sprites
{
	t_xpm	wall;
}	t_sprites;


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

char	*read_all(int fd);
void	img_analyser(t_data *data);

#endif