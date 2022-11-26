# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 12:06:24 by pfrances          #+#    #+#              #
#    Updated: 2022/11/26 19:49:12 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FILES = so_long.c
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	$(addprefix $(SRCS_DIR)/, so_long.c)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
CFLAGS = #-Wall -Wextra -Werror
INCLUDES = -I includes -I/usr/X11/include
LIBFT_PATH = ./libraries/libft
MLX_PATH = ./libraries/minilibx
X11_PATH = /usr/X11/include/../lib
LIBS_PATH = -L$(LIBFT_PATH) -L$(MLX_PATH) -L$(X11_PATH)
LIBS = -lft -lmlx_Darwin -lXext -lX11 -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS_PATH) $(LIBS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINE_VARS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean:
	rm -f $(OBJS) $(NAME)
	make fclean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re