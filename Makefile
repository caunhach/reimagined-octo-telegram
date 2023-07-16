# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caunhach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 00:48:45 by caunhach          #+#    #+#              #
#    Updated: 2023/06/22 01:06:52 by caunhach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall -g
NAME=fdf
SRC= src/create_map.c \
     src/free.c \
	 src/main.c \
	 src/matrix.c \
	 src/mlx_bresenham.c \
	 src/mlx_color.c \
	 src/mlx_control.c \
	 src/mlx_draw.c \
	 src/mlx_key.c \
	 src/mlx_main.c \
	 src/mlx_operation.c
INCLUDES=lib/libft/libft.a lib/minilibx_macos/libmlx.a

all:
	@make -C lib/libft/ all
	@make -C lib/minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C lib/libft/ clean
	@make -C lib/minilibx_macos/ clean

fclean: clean
	rm -f $(NAME)
	@make -C lib/libft/ fclean
	rm -rf fdf.dSYM

re: fclean all

.PHONY: all clean fclean re
