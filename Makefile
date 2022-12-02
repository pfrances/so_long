# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 12:06:24 by pfrances          #+#    #+#              #
#    Updated: 2022/12/02 18:23:44 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	$(addprefix $(SRCS_DIR)/,	check_map.c			\
									check_map_content.c	\
									check_playability.c	\
									end_game.c			\
									images_init.c		\
									init.c				\
									loop.c				\
									render_map.c		\
									read_all.c			\
									so_long.c)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
CFLAGS = -g -Wall -Wextra -Werror
LIBS_DIR = ./libraries
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = $(LIBS_DIR)/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
MLX_DIR = $(LIBS_DIR)/minilibx
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
MLX_LIBS = -L$(MLX_DIR) -L/usr/X11/include/../lib -lmlx_Darwin -lXext -lX11 -framework OpenGL -framework AppKit
endif

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINE_VARS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re