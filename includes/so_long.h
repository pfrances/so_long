/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:25:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/26 19:45:19 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
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

#endif