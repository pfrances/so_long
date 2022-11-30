/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:25:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/11/30 17:41:34 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "../libraries/libft/includes/libft.h"
# include "../libraries/get_next_line/includes/get_next_line.h"
# include "../libraries/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# define BUFFER_SIZE 1024
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define BLACK_PIXEL 0x000000
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x1E8449
# define WHITE_PIXEL 0xFFFFFF
# define MAP_FILE_EXTENSION ".ber"
# define WALL_XPM_PATH "./xpm_files/wall.xpm"
# define EMPTY_XPM_PATH "./xpm_files/empty.xpm"
# define PLAYER_XPM_PATH "./xpm_files/player.xpm"
# define COLLECTIBLE_XPM_PATH "./xpm_files/collectible.xpm"
# define EXIT_XPM_PATH "./xpm_files/exit.xpm"
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char		**array;
	size_t		height;
	size_t		width;
	size_t		nbr_of_collectibles;
	t_position	start_pos;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		wall_img;
	t_img		empty_img;
	t_img		player_img;
	t_img		collectible_img;
	t_img		exit_img;
	int			cur_img;
	t_map		map;
	t_position	pos;
	int			bsize;
	int			move_count;
	int			window_width;
	int			window_height;
}	t_data;

bool	init(t_data *data, int argc, char *argv[]);
bool	images_init(t_data *data);
void	destroy_images(t_data *data);
int		destroy_window(t_data *data);
void	end_game(t_data *data);
void	render_map(t_data *data);

bool	set_map(t_map *map, char *filename);
bool	check_map(t_map *map, char *filename);

#endif