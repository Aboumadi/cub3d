# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 13:59:10 by aboumadi          #+#    #+#              #
#    Updated: 2023/02/25 23:14:36 by aboumadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

HEADER = cub3d.h

LIBFT = ./libft/libft.a

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	Utils/parsing.c Utils/check_col_map.c Utils/check_text_map.c\
	cub3d.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

#FRAME = -lmlx -framework OpenGL -framework AppKit

CC = cc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(MAKE) -C ./libft
		@echo "making libft.a ..."
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean :
		$(MAKE) clean -C ./libft
		rm -rf $(OBJ)

fclean :  clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re : 	fclean $(NAME)