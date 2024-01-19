# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abolea <abolea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 11:32:23 by abolea            #+#    #+#              #
#    Updated: 2024/01/19 16:10:07 by abolea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = so_long

PRINTF_FILE	=	ft_printf/libftprintf.a

MLX_FILE	=	minilibx-linux/libmlx.a

MLX_FLAG = -Iminilibx-linux -Lminilibx-linux -lmlx -lX11 -lXext -lm -Lft_printf -lftprintf

SRC = check_map.c check_move.c display_map.c display_player.c ft_itoa.c \
get_next_line_utils.c get_next_line.c init_map.c init_mlx.c move_player.c \
main.c utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) so_long.h
		make -sC minilibx-linux
		make -sC ft_printf
		$(CC) $(FLAGS) $(OBJ) $(MLX_FLAG) -o $(NAME)

clean :
		rm -f $(OBJ)
		make -sC ft_printf clean
		make -sC minilibx-linux clean

fclean : clean
		rm -f $(NAME)
		rm -f $(PRINTF_FILE)
		rm -f $(MLX_FILE)
		

re : fclean all

.PHONY: all clean fclean re
