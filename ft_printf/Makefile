# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 20:27:50 by galves-f          #+#    #+#              #
#    Updated: 2023/12/08 14:40:42 by galves-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MAKE_LIB = ar -rcs
INCS = inc
SRCS = ft_printf.c \
		format_c.c \
		format_s.c \
		format_d.c
OBJS = $(SRCS:.c=.o)

bonus : all

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) 
	$(MAKE_LIB) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(INCS) 

	
$(LIBFT) :
	cd $(LIBFT_PATH) && make 
	cp $(LIBFT) $(NAME) 


clean :
	rm -rf $(OBJS) $(NAME)

fclean : clean
	cd $(LIBFT_PATH) && make fclean

re: fclean all

t: all
	$(CC) $(CFLAGS) test.c -o test -L. -lftprintf
	./test
	rm test

.PHONY: all bonus clean fclean re
