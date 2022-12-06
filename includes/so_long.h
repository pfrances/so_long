/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:25:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/06 19:24:10 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/libft/includes/libft.h"
# include "../libraries/ft_printf/includes/ft_printf.h"
# include "../libraries/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1024
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

# define ERROR_MSG "Error."
# define WRONG_NB_OF_ARGS_MSG "The programm take only one argument: map path."
# define WRONG_MAP_NAME_MSG "The map name should be named like '[FILENAME].ber'"
# define FAILED_AT_OPENING_MAP_MSG "Failed at opening the map."
# define FAILED_AT_READING_MAP_MSG "Failed at reading the map."
# define FAILED_AT_CLOSING_MAP_MSG "Failed at closing the map."
# define HAS_EMPTY_LINE_MSG "The map has empty line(s)."
# define FAILED_ON_MALLOC_MSG "Failed on memory allocation."
# define NOT_BORDERED_BY_WALL_MSG "The map has to be bordered by walls."
# define TO_MUCH_PLAYER_MSG "There are more than one player."
# define TO_MUCH_EXIT_MSG "There are more than one exit."
# define HAS_NO_COLLECTIBLE_MSG "There no collectible."
# define UNDEFINED_CHARACTER_MSG "There are undefined character(s)."
# define WRONG_SHAPE_MSG "The map should be a rectangle."
# define MAP_NOT_PLAYABLE_MSG "The map is not playable."
# define FAILED_AT_INIT_MLX_MSG "Failed at init MLX."
# define FAILED_AT_INIT_WINDOW_MSG "Failed at init window."
# define FAILED_AT_INIT_IMGS_MSG "Failed at init images."
# define MLX_LOOP_ISSUE_MSG "Issue occured on MLX loop."

typedef enum e_error
{
	NONE,
	WRONG_NB_OF_ARGS,
	WRONG_MAP_NAME,
	FAILED_AT_OPENING_MAP,
	FAILED_AT_READING_MAP,
	FAILED_AT_CLOSING_MAP,
	HAS_EMPTY_LINE,
	FAILED_ON_MALLOC,
	NOT_BORDERED_BY_WALL,
	TOO_MUCH_PLAYER,
	TO_MUCH_EXIT,
	HAS_NO_COLLECTIBLE,
	UNDEFINED_CHARACTER,
	WRONG_SHAPE,
	FAILED_ON_MALLOC_FLOODED,
	MAP_NOT_PLAYABLE,
	FAILED_AT_INIT_MLX,
	FAILED_AT_INIT_WINDOW,
	FAILED_AT_INIT_WALL_IMG,
	FAILED_AT_INIT_PLAYER_IMG,
	FAILED_AT_INIT_COLLECTIBLES_IMG,
	FAILED_AT_INIT_EXIT_IMG,
	FAILED_AT_INIT_EMPTY_IMG,
}	t_error;

typedef struct s_position
{
	size_t	x;
	size_t	y;
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
	char		**flood_floor_array;
	size_t		height;
	size_t		width;
	size_t		nbr_of_collectibles;
	bool		has_player;
	bool		has_exit;
	t_position	player_pos;
	t_position	exit_pos;
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
	int			bsize;
	size_t		move_count;
	int			window_width;
	int			window_height;
}	t_data;

/*		images_init.c		*/
void	images_init(t_data *data);

/*		check_map.c			*/
void	check_map(t_data *data, char *filename);

/*		check_content.c		*/
void	check_content(t_data *data);

/*		check_playability	*/
void	are_map_playble(t_data *data);

/*		end_program.c		*/
int		end_program_when_mlx_issue(t_data *data);
void	end_program(t_data *data, t_error error, char *error_msg);
void	free_map(char **map_array);

/*		loop.c				*/
void	put_in_loop(t_data *data);

/*		read_all.c			*/
char	*read_all(int fd);

#endif