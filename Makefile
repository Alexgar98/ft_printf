# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexigar <alexigar@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 12:37:43 by alexigar          #+#    #+#              #
#    Updated: 2023/12/22 10:59:11 by alexigar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

SOURCES = conversions.c \
		  ft_printf.c \
		  change_formats.c \
		  ./libft/ft_itoa.c \
		  ./libft/ft_memset.c \
		  ./libft/ft_putchar_fd.c \
		  ./libft/ft_putstr_fd.c \
		  ./libft/ft_toupper.c \
		  ./libft/ft_strlen.c

OBJS = $(SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all : $(NAME)

%.o : %.c
	@$(CC) -c $(CCFLAGS) $< -o $@
clean :
	@rm -rf $(OBJS) $(OBJBONUS)
fclean : clean
	@rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
