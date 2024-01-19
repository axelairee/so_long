# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abolea <abolea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:48:52 by abolea            #+#    #+#              #
#    Updated: 2023/11/28 11:04:22 by abolea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr_u.c ft_strchr.c ft_strlen.c ft_putnbr_fd.c \
 ft_putchar_fd.c ft_putstr_fd.c ft_print_p.c ft_putnbr_base.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c ft_printf.h
	$(CC) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ) ft_printf.h
	ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
