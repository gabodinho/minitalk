# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:33:58 by ggiertzu          #+#    #+#              #
#    Updated: 2023/08/28 22:19:26 by ggiertzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = cc
CFLAGS = -Werror -Wall -Wextra -I. -I./libft
MAKE = make -C
RM = rm -f

SRCS = server.c client.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: minitalk.a server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server minitalk.a

client: client.c
	$(CC) $(CFLAGS) client.c -o client minitalk.a

minitalk.a:
	$(MAKE) $(LIBFT_DIR)
	cp libft/libftprintf.a .
	mv libftprintf.a minitalk.a

clean:
	make clean -C $(LIBFT_DIR)
fclean: clean
	$(RM) server client
	make fclean -C $(LIBFT_DIR)
re: fclean all

.PHONY: all clean fclean re
