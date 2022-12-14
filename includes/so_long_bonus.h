/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:25:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/12/12 19:04:10 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libraries/libft/includes/libft.h"
# include "../libraries/ft_printf/includes/ft_printf.h"
# include "../libraries/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define BUFFER_SIZE 1024
# define BSIZE 100
# define HEIGHT_MIN 3
# define WITDH_MIN 3
# define SPACE_FOR_MSG 20
# define DOUBLE_R_TIMING 250000
# define SPRITE_TIMING 500000
# define DEFAULT_SPAWN_TIMING 1000000
# define ENEMIES_SPEED_MIN 5000000
# define ENEMIES_SPEED_MAX 200000
# define ENEMIES_SPEED_STEP 200000
# define ENEMIES_SPEED_MSG "ENEMIES SPEED:"
# define MOVES_COUNT_MSG "MOVES COUNT:"
# define TIMER_MSG "TIME:"
# define SIZE_MAX_DIGITS 20
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000

# define MAP_FILE_EXTENSION ".ber"
# define WALL1_XPM_PATH "./xpm_files/wall_1.xpm"
# define WALL2_XPM_PATH "./xpm_files/wall_2.xpm"
# define PLAYER1_XPM_PATH "./xpm_files/player_1.xpm"
# define PLAYER2_XPM_PATH "./xpm_files/player_2.xpm"
# define PLAYER_ON_EXIT1_XPM_PATH "./xpm_files/player_on_exit_1.xpm"
# define PLAYER_ON_EXIT2_XPM_PATH "./xpm_files/player_on_exit_2.xpm"
# define COLLECTIBLE_XPM_PATH "./xpm_files/collectible.xpm"
# define EXIT_XPM_PATH "./xpm_files/exit.xpm"
# define EMPTY_XPM_PATH "./xpm_files/empty.xpm"
# define ENEMY1_XPM_PATH "./xpm_files/enemy_1.xpm"
# define ENEMY2_XPM_PATH "./xpm_files/enemy_2.xpm"
# define ENEMY_ON_EXIT1_XPM_PATH "./xpm_files/enemy_on_exit_1.xpm"
# define ENEMY_ON_EXIT2_XPM_PATH "./xpm_files/enemy_on_exit_2.xpm"
# define BOTTOM_XPM_PATH "./xpm_files/bottom.xpm"
# define GAME_OVER_XPM_PATH "./xpm_files/game_over_screen.xpm"
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define ENEMY 'W'

# define NB_OF_WALL_IMG 2
# define NB_OF_PLAYER_IMG 2
# define NB_OF_PLAYER_ON_EXIT_IMG 2
# define NB_OF_COLLECTIBLE_IMG 1
# define NB_OF_EXIT_IMG 1
# define NB_OF_EMPTY_IMG 1
# define NB_OF_ENEMY_IMG 2
# define NB_OF_ENEMY_ON_EXIT_IMG 2
# define NB_OF_BOTTOM_IMG 1
# define NB_OF_GAME_OVER_IMG 1

# define ERROR_MSG "Error"
# define WRONG_NB_OF_ARGS_MSG "The programm take only one argument: map path."
# define WRONG_MAP_NAME_MSG "The map should be named like '[FILENAME].ber'."
# define FAILED_AT_OPENING_MAP_MSG "Failed at opening the map."
# define FAILED_AT_READING_MAP_MSG "Failed at reading the map."
# define EMPTY_MAP_MSG "The map is empty."
# define FAILED_AT_CLOSING_MAP_MSG "Failed at closing the map."
# define HAS_EMPTY_LINE_MSG "The map has empty line(s)."
# define FAILED_ON_MALLOC_MSG "Failed on memory allocation."
# define NOT_BORDERED_BY_WALL_MSG "The map has to be bordered by walls."
# define TO_MUCH_PLAYER_MSG "There are more than one player."
# define TO_MUCH_EXIT_MSG "There are more than one exit."
# define UNDEFINED_CHARACTER_MSG "There are undefined character(s)."
# define WRONG_SHAPE_MSG "The map should be a rectangle."
# define MAP_TOO_HIGH_MSG "The map is too high."
# define MAP_TOO_WIDE_MSG "The map is too wide."
# define HAS_NO_PLAYER_MSG "There no player."
# define HAS_NO_EXIT_MSG "There no exit."
# define HAS_NO_COLLECTIBLE_MSG "There no collectible."
# define MAP_NOT_PLAYABLE_MSG "The map is not playable."
# define FAILED_AT_INIT_MLX_MSG "Failed at init MLX."
# define FAILED_AT_INIT_WINDOW_MSG "Failed at init window."
# define FAILED_AT_INIT_IMGS_MSG "Failed at init images."
# define MLX_LOOP_ISSUE_MSG "Issue occured on MLX loop."

typedef enum e_error
{
	WRONG_NB_OF_ARGS,
	WRONG_MAP_NAME,
	OPENING_MAP_FAILED,
	READING_MAP_FAILED,
	EMPTY_MAP,
	CLOSING_MAP_FAILED,
	HAS_EMPTY_LINE,
	MALLOC_FAILED,
	NOT_BORDERED_BY_WALL,
	TOO_MUCH_PLAYER,
	TO_MUCH_EXIT,
	WRONG_SHAPE,
	UNDEFINED_CHARACTER,
	HAS_NO_PLAYER,
	HAS_NO_EXIT,
	HAS_NO_COLLECTIBLE,
	FLOODED_MALLOC_FAILED,
	MAP_NOT_PLAYABLE,
	INITIAL_MAP_MALLOC_FAILED,
	ENEMIES_MALLOC_FAILED,
	INIT_MLX_FAILED,
	MAP_TOO_HIGH,
	MAP_TOO_WIDE,
	INIT_WINDOW_FAILED,
	WALL_IMG_MALLOC_FAILED,
	PLAYER_IMG_MALLOC_FAILED,
	PLAYER_ON_EXIT_IMG_MALLOC_FAILED,
	COLLECTIBLE_IMG_MALLOC_FAILED,
	EXIT_IMG_MALLOC_FAILED,
	EMPTY_IMG_MALLOC_FAILED,
	ENEMY_IMG_MALLOC_FAILED,
	ENEMY_ON_EXIT_IMG_MALLOC_FAILED,
	BOTTOM_IMG_MALLOC_FAILED,
	GAME_OVER_IMG_MALLOC_FAILED,
	INIT_WALL1_IMG_FAILED,
	INIT_WALL2_IMG_FAILED,
	INIT_PLAYER1_IMG_FAILED,
	INIT_PLAYER2_IMG_FAILED,
	INIT_PLAYER_ON_EXIT1_IMG_FAILED,
	INIT_PLAYER_ON_EXIT2_IMG_FAILED,
	INIT_COLLECTIBLE_IMG_FAILED,
	INIT_EXIT_IMG_FAILED,
	INIT_EMPTY_IMG_FAILED,
	INIT_ENEMY1_IMG_FAILED,
	INIT_ENEMY2_IMG_FAILED,
	INIT_ENEMY_ON_EXIT1_IMG_FAILED,
	INIT_ENEMY_ON_EXIT2_IMG_FAILED,
	INIT_BOTTOM_IMG_FAILED,
	INIT_GAME_OVER_IMG_FAILED,
	INFO_BUFF_MALLOC_FAILED,
	RESET_MAP_MALLOC_FAILED,
	NONE
}	t_error;

typedef enum e_direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
}	t_direction;

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
	char	*path;
	t_error	error;
	char	*error_msg;
	bool	last;
}	t_img;

typedef struct s_enemy
{
	t_position	initial_pos;
	t_position	pos;
	t_direction	direction;
	bool		on_collectible;
}	t_enemy;

typedef struct s_map
{
	char		**initial_map;
	char		**array;
	char		**flood_floor_array;
	size_t		height;
	size_t		width;
	size_t		nbr_of_collectibles;
	bool		has_player;
	bool		has_exit;
	t_position	player_initial_pos;
	size_t		initial_nbr_of_collectibles;
	t_position	player_pos;
	t_position	exit_pos;
	t_enemy		*enemies;
	size_t		nb_enemies;
	size_t		enemies_moves_turn_over;
}	t_map;

typedef struct s_info
{
	int			color;
	size_t		value;
	t_position	value_pos;
	char		*title_str;
	t_position	title_str_pos;
}	t_info;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*wall_img;
	t_img			*player_img;
	t_img			*player_on_exit_img;
	t_img			*collectible_img;
	t_img			*exit_img;
	t_img			*empty_img;
	t_img			*enemy_img;
	t_img			*enemy_on_exit_img;
	t_img			*bottom_img;
	t_img			*game_over_img;
	size_t			sprite_cnt;
	size_t			last_sprite_time;
	int				cur_img;
	t_map			map;
	size_t			screen_witdh;
	size_t			screen_height;
	int				window_width;
	int				window_height;
	time_t			time;
	size_t			last_move_time;
	size_t			last_reset_time;
	t_info			move_count;
	t_info			timer;
	t_info			enemies_speed;
	char			*info_value_buff;
	struct timeval	start_time;
	bool			game_over;
}	t_data;

/*			images_init_bonus.c			*/
void	images_init(t_data *data);

/*			images_init_tools_bonus.c	*/
t_img	*image_allocation(t_data *data, size_t nb,
			t_error error, char *error_msg);
void	set_img_info(t_img *img, char *path, t_error error);
void	set_xpm_img(t_data *data, t_img *img);

/*			check_map_bonus.c			*/
void	check_map(t_data *data, char *filename);

/*			check_content_bonus.c		*/
void	check_content(t_data *data);

/*			check_playability_bonus.c	*/
void	are_map_playble(t_data *data);

/*			end_program_bonus.c			*/
int		cross_button_event(t_data *data);
void	end_program(t_data *data, t_error error, char *error_msg);

/*			end_program_frees_bonus.c	*/
void	free_all_img(t_data *data, t_error error);
void	free_map(char **map_array);

/*			loop_bonus.c				*/
void	put_one_image(t_data *data, size_t x, size_t y, t_img img);
void	put_in_loop(t_data *data);

/*			deal_keys_bonus.c			*/
int		deal_keys(int key, t_data *data);

/*			map_duplicate_bonus.c		*/
char	**array_duplicate(char **to_dup);

/*			read_all_bonus.c			*/
char	*read_all(int fd);

/*			position_tools_bonus.c		*/
void	set_position(t_position *position, size_t x, size_t y);
void	x_y_by_direction(t_position position, t_direction direction,
			size_t *x, size_t *y);

/*			enemies_bonus.c				*/
void	init_enemies(t_data *data);
void	reset_enemies_pos(t_data *data);
void	deal_enemies(t_data *data);

/*			enemies_moves_bonus.c		*/
bool	can_move(t_data *data, t_enemy *enemy);
void	enemies_moves(t_data *data, t_enemy *enemy, size_t x, size_t y);

/*			times_bonus.c				*/
size_t	get_time(struct timeval start);

/*			display_infos_bonus.c		*/
void	display_game_over(t_data *data);
void	display_infos(t_data *data);

/*			display_infos_init_bonus.c	*/
void	display_info_init(t_data *data);

/*			sprites_bonus.c				*/
void	deal_sprites(t_data *data);
t_img	find_enemy_sprite(t_data *data, size_t enemy_x, size_t enemy_y);

#endif