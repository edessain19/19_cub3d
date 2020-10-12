# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by edessain          #+#    #+#              #
#    Updated: 2020/09/30 16:37:04 by edessain         ###   ########.fr        #
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


FLGS = -Wall -Wextra -Werror

HEADER = ./

FSAN = -g -fsanitize=address

all:
	make -C ./minilibx
	make -C ./libft
	gcc -o $(NAME) -I$(HEADER) $(FLGS) $(SRC) $(LIBFT) $(MLX) -lm -lX11 -lXext

clean: 
	make -C ./minilibx clean
	make -C ./libft clean
	rm -rf *.o

fclean:
	make -C ./minilibx clean
	make -C ./libft fclean
	rm -rf *.o
	rm -rf *.bmp
	rm -rf ${NAME}

re: fclean all

phony: all clean fclean re
