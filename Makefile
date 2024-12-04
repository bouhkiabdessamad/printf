# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhki <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 11:38:11 by abouhki           #+#    #+#              #
#    Updated: 2024/12/03 17:47:09 by abouhki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFL = ft_printf.c ft_putchar.c ft_puthex.c ft_bzero.c ft_putuhex.c ft_putadress.c ft_putnbr.c ft_putunbr.c ft_putstr.c
OBJFL = $(SRCFL:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJFL)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJFL)
fclean: clean
	$(RM) $(NAME)
re: fclean all
