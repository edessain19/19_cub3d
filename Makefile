# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by edessain          #+#    #+#              #
#    Updated: 2020/07/15 17:11:56 by evrard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
LIBFT_PATH 		= ./libft
MINILIBX_PATH   = ./minilibx
SRCS 			= ./srcs/main.c \
					./srcs/keycode.c \
					./srcs/ft_raycast.c \
					./srcs/ft_raycast_2.c \
					./srcs/textures.c \
					./srcs/ft_init_struct.c \
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
					./parsing/check_parsing_error.c \
					./parsing/ft_exit.c \
					./sprites/ray_sprites.c \
					./sprites/ray_sprites_2.c \


OBJS			= ${SRCS:.c=.o}
INCLUDE 		= cube3d.h
LIBFT 			= libft
MINILIBX 		= minilibx
CC				= gcc -g -Wall -Wextra -Werror #-fsanitize=address
RM				= rm -f
MLXFLAGS 		= -I ./minilibx -L ./minilibx -lmlx -framework OpenGl -framework Appkit
LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c
# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking

all:			libft_all minilibx_all ${NAME}
$(NAME):		${OBJS}
				@$(CC) $(MLXFLAGS) $(LIBFLAGS) libft.a libmlx.a -I./ $(OBJS) -o $@
clean:			libft_clean minilibx_clean
				@${RM} ${OBJS}
fclean:			libft_fclean clean
				@${RM} ${NAME}
re:				fclean all

# In this last section we make other makefiles compile with the -C flag
# The -C flag makes you go to the appropriate path and do the asked command
libft_all:
	make -C $(LIBFT_PATH) all
	cp ./libft/libft.a libft.a

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) libft.a

minilibx_all:
	make -C $(MINILIBX_PATH) all
	cp ./minilibX/libmlx.a libmlx.a

minilibx_clean:
	make -C $(MINILIBX_PATH) clean
	$(RM) libmlx.a

.PHONY: all fclean clean re
