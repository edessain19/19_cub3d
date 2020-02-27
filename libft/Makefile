# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 15:32:36 by edessain          #+#    #+#              #
#    Updated: 2020/02/17 09:34:15 by edessain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

NAME = libft.a

OBJS = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

GCC = gcc

RM = rm -rf

HEADER = ./

all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) -I$(HEADER) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	$(GCC) $(CFLAGS) -I$(HEADER) -c $(SBONUS) $(SRC)
	ar rc $(NAME) $(BOBJS)
	ranlib $(NAME)

.PHONY: all test clean fclean re
