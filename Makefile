# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 12:06:24 by pfrances          #+#    #+#              #
#    Updated: 2022/11/22 12:32:56 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	$(addprefix $(SRCS_DIR)/, so_long.c)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
RM = rm -f

LIB_DIR = library
LIBFT_DIR = ./$(LIB_DIR)/libft
PRINTF_DIR = ./$(LIB_DIR)/printf
GNL_DIR = ./$(LIB_DIR)/get_next_line
MLX_DIR = ./$(LIB_DIR)/minilibx-linux

PRINTF_LIB = ./$(PRINTF_DIR)/libftprintf.a
GNL_LIB = ./$(GNL_DIR)/get_next_line.a
MLX_LIB = ./$(MLX_DIR)/libmlx.a

CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
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
MLX = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lXext -lX11 $(MLX_DIR)/libmlx.a
else
ESC = ESC=53
W = W=13
A = A=0
S = S=1
D = D=2
FRAMERATE = FRAMERATE=200
ADJUST = ADJUST=20
MLX = -I $(MLX_DIR) -L/usr/X11R6/lib -lmlx -lXext -lX11 -framework OpenGL -framework Appkit $(MLX_DIR)/libmlx_Darwin.a
endif

#--------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(PRINTF) $(GNL) $(MLX)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(DEFINE_VARS) -c -o $@ $<

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PRINTF_LIB)
	$(RM) $(GNL_LIB)
	$(RM) $(MLX_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re