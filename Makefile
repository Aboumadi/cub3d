# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 13:59:10 by aboumadi          #+#    #+#              #
#    Updated: 2022/10/23 20:35:56 by aboumadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

HEADER = cub3d.h

LIBFT = ./libft/libft.a

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	Utils/parsing.c Utils/checking_map.c\
	cub3d.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

FRAME = -lmlx -framework OpenGL -framework AppKit

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(MAKE) -C ./libft
		$(MAKE) bonus -C ./libft
		@echo "making libft.a ..."
		@$(CC) $(CFLAGS) $(FRAME) $(OBJ) $(LIBFT) -o $(NAME)

clean :
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean :  clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re : 	fclean $(NAME)