# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:42:11 by aadnane           #+#    #+#              #
#    Updated: 2023/05/03 15:15:59 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = main.c gnl.c parsing.c parse_utils.c split.c directions_paths.c \
	ceiling_and_floor.c utils_floor_celling.c parse_utils2.c parse_utils3.c \
	parse_utils1.c parse_utils4.c
OBJS = $(SRCS:.c=.o)
NAME = cub3D
HEADER = cub3D.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
