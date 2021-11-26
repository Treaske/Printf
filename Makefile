# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 17:03:17 by ade-blas          #+#    #+#              #
#    Updated: 2021/11/18 16:57:38 by ade-blas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC 			= gcc
CFLAGS		= -Wall -Werror -Wextra
LIB1 		= ar -rcs
RM 			= /bin/rm -f

NAME 		=libftprintf.a

INCLUDE		=ft_printf.h
SRCS		= ft_printf.c ft_putchar.c ft_puthexa.c ft_putnum.c ft_putstr.c ft_putunnum.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)

.c.o:		
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
