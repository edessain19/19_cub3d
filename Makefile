# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by edessain          #+#    #+#              #
#    Updated: 2020/10/16 19:24:14 by edessain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CUB = ./map.cub

MLX = ./minilibx/libmlx.a

LIBFT = ./libft/libft.a

SRCS 			= ./srcs/main.c \
					./srcs/keycode.c \
					./srcs/ft_raycast.c \
					./srcs/ft_raycast_2.c \
					./srcs/textures.c \
					./srcs/ft_init_struct.c \
					./srcs/ft_init_struct_2.c \
					./srcs/bmp.c \
				 	./parsing/ft_parsing.c \
				 	./parsing/ft_parsing_info.c \
					./parsing/ft_parsing_info_2.c \
				 	./parsing/ft_parsing_map.c \
					./parsing/ft_parsing_tab.c \
					./parsing/ft_parsing_dir.c \
					./parsing/ft_parsing_sprt.c \
					./parsing/check_error.c \
					./parsing/check_error_2.c \
					./parsing/check_error_3.c \
					./parsing/ft_exit.c \
					./sprites/ray_sprites.c \
					./sprites/ray_sprites_2.c \

FLGS = -Wall -Wextra -Werror -framework OpenGL -framework Appkit

HEADER = ./cub3d.h

all:
	make -C ./minilibx
	make -C ./libft
	gcc -o $(NAME) -I$(HEADER) $(FLGS) $(SRCS) $(LIBFT) $(MLX)

clean:
	make -C ./minilibx clean
	make -C ./libft clean
	rm -rf *.o

fclean:
	make -C ./minilibx clean
	make -C ./libft fclean
	rm -rf *.o
	rm -rf ${NAME}

re: fclean all

.PHONY: all fclean clean re
