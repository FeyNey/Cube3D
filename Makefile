# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 17:28:49 by acoste            #+#    #+#              #
#    Updated: 2025/04/20 21:46:13 by acoste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-g -Wall -Werror -Wextra

NAME		=	cub3D

SRC_DIR		=	src/

SRC_FILES	=	main.c\
				utils.c\
				event.c\
				map_setup.c\
				get_next_line.c\
				get_next_line_utils.c\
				image.c\
				verif_map.c\
				ft_split.c\

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ			=	$(SRC:.c=.o)

MLX = -Lminilibx-linux -lmlx_Linux -lXext -lX11

all			:	$(NAME)

$(SRC_DIR)%.o	:	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJ)
#	@echo "Compiling minilibx"
#	@make -C minilibx-linux/ > /dev/null 2>&1
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean		:
#				@echo "cleaning minilibx"
#				@make -C minilibx-linux clean > /dev/null 2>&1
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all