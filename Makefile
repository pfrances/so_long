# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 12:06:24 by pfrances          #+#    #+#              #
#    Updated: 2022/11/30 16:46:29 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	$(addprefix $(SRCS_DIR)/,	check_map.c	\
									end_game.c	\
									images.c	\
									init.c		\
									loop.c		\
									map.c		\
									so_long.c)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
CFLAGS = -g #-Wall -Wextra -Werror
LIBFT_DIR = ./libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ./libraries/get_next_line
GNL = $(GNL_DIR)/get_next_line.a
MLX_DIR = ./libraries/minilibx
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
MLX_LIBS = -I $(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 $(MLX_DIR)/libmlx.a
else
ESC = ESC=53
W = W=13
A = A=0
S = S=1
D = D=2
FRAMERATE = FRAMERATE=200
ADJUST = ADJUST=20
MLX_LIBS = -lft -lmlx_Darwin -lXext -lX11 -framework OpenGL -framework AppKit
endif

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(GNL) $(MLX_LIBS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINE_VARS) $(LIBFT) $(GNL) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(GNL):
	make -C $(GNL_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(GNL)

re: fclean all

.PHONY: all clean fclean re