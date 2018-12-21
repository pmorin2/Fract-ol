#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmorin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 15:43:01 by pmorin            #+#    #+#              #
#    Updated: 2018/12/20 16:14:45 by pmorin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= fractol
LIB= libft/libft.a minilibx_macos/libmlx.a
FLAGS= -Wall -Wextra -Werror
CC= gcc
_GREEN= $'\x1b[32m'
SRCS= main.c mandelbrot.c put_pixel.c key.c color.c julia.c burningship.c\
	spider.c bonus_2.c bonus_3.c bonus_4.c bonus_5.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)
	@echo "${_GREEN}Fractol is ready !${_GREEN}"

$(NAME): $(OBJS)
	@make -C minilibx_macos/
	@make -C libft/
	@gcc -o $@ $(OBJS) $(LIB) -framework OpenGL -framework AppKit

.c.o:
	$(CC) -c $^ -o $@ $(FLAGS) -I libft/ -I minilibx_macos/

.PHONY: clean

clean:
	rm -f *.o
	rm -f libft/*.o
	rm -f minilibx_macos/*.o

fclean: clean
	rm -f fractol
	rm -f libft/libft.a
	rm -f minilibx_macos/libmlx.a

re: fclean all
