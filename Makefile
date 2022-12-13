# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 12:06:24 by pfrances          #+#    #+#              #
#    Updated: 2022/12/13 11:31:55 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = objs
######################################### MANDATORY #########################################
MANDATORY_SRCS_DIR = $(SRCS_DIR)/mandatory_srcs
MANDATORY_OBJS_DIR = $(OBJS_DIR)/mandatory_objs
MANDATORY_SRCS = $(addprefix $(MANDATORY_SRCS_DIR)/,		array_duplicate.c		\
															check_map.c				\
															check_map_content.c		\
															check_playability.c		\
															deal_keys.c				\
															end_program.c			\
															images_init.c			\
															loop.c					\
															read_all.c				\
															set_position.c			\
															so_long.c)
MANDATORY_OBJS = $(subst $(MANDATORY_SRCS_DIR), $(MANDATORY_OBJS_DIR), $(MANDATORY_SRCS:.c=.o))
########################################### BONUS ###########################################
BONUS_SRCS_DIR = $(SRCS_DIR)/bonus_srcs
BONUS_OBJS_DIR = $(OBJS_DIR)/bonus_objs
BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR)/,				array_duplicate_bonus.c			\
															check_map_bonus.c				\
															check_map_content_bonus.c		\
															check_playability_bonus.c		\
															deal_keys_bonus.c				\
															display_info_init_bonus.c		\
															display_infos_bonus.c			\
															end_program_bonus.c				\
															end_program_frees_bonus.c		\
															enemies_bonus.c					\
															enemies_moves_bonus.c			\
															images_init_bonus.c				\
															images_init_tools_bonus.c		\
															loop_bonus.c					\
															read_all_bonus.c				\
															position_tools_bonus.c			\
															so_long_bonus.c					\
															times_bonus.c					\
															sprites_bonus.c)
BONUS_OBJS = $(subst $(BONUS_SRCS_DIR), $(BONUS_OBJS_DIR), $(BONUS_SRCS:.c=.o))

LIBS_DIR = ./libraries
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = $(LIBS_DIR)/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
MLX_DIR = $(LIBS_DIR)/minilibx
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
INCLUDES = -I includes
DEFINE_VARS = -D $(ESC) -D $(W) -D $(A) -D $(S) -D $(D) -D $(FRAMERATE) -D $(ADJUST)

#--------------------------------------------------------------------------#

OS = $(shell uname -s)

ifeq ($(OS),Linux)
ESC = ESC=65307
W = W=119
A = A=97
S = S=115
D = D=100
FRAMERATE = FRAMERATE=1000
ADJUST = ADJUST=0
MLX = $(MLX_DIR)/libmlx.a
MLX_LIBS = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 $(MLX)
else
ESC = ESC=53
W = W=13
A = A=0
S = S=1
D = D=2
FRAMERATE = FRAMERATE=200
ADJUST = ADJUST=20
MLX = $(MLX_DIR)/libmlx_Darwin.a
INCLUDES += -I/usr/X11/include
MLX_LIBS = -L $(MLX_DIR) -L /usr/X11/include/../lib -lmlx_Darwin -lXext -lX11 -framework OpenGL -framework AppKit
endif

#--------------------------------------------------------------------------#

all: $(NAME)


$(NAME): $(MANDATORY_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(MANDATORY_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIBS) -o $(NAME)

$(MANDATORY_OBJS_DIR)/%.o: $(MANDATORY_SRCS_DIR)/%.c $(MLX)
	@mkdir -p $(MANDATORY_OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINE_VARS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(MLX): $(MLX_DIR)/Makefile
	make -C $(MLX_DIR)

$(MLX_DIR)/Makefile:
	git clone $(MLX_REPO) $(MLX_DIR)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -rf $(MLX_DIR)

re: fclean all

bonus: $(BONUS_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIBS) -o $(NAME)

$(BONUS_OBJS_DIR)/%.o: $(BONUS_SRCS_DIR)/%.c $(MLX)
	@mkdir -p $(BONUS_OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINE_VARS) -c $< -o $@

.PHONY: all clean fclean re bonus