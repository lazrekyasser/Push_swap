# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 08:46:41 by ylazrek           #+#    #+#              #
#    Updated: 2021/06/26 16:47:41 by ylazrek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME_PS = push_swap
NAME_CHECK = checker

MAIN_CHECK = srcs/checker.c
MAIN_PS = srcs/push_swap.c
SRCS = srcs/stack.c \
		srcs/tool.c \
		srcs/sort_stack.c \
		srcs/sort_stack1.c \
		srcs/sort_stack2.c \
		srcs/sort_stack3.c \
		srcs/quicksort.c \
		srcs/utils.c \
		srcs/utils_stack.c \
		srcs/swap.c \
		srcs/rotate.c\
		srcs/push_pop.c \
		srcs/check_arg.c \
		srcs/ft_strcmp.c \
		srcs/tool1.c \
		srcs/sort_s3.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
MAIN_CHECK_O = $(MAIN_CHECK:.c=.o)
MAIN_PS_O = $(MAIN_PS:.c=.o)

HEADERS = -I libft -I .

all : mylib  $(NAME_PS) $(NAME_CHECK)

$(NAME_CHECK): $(MAIN_CHECK_O) $(OBJS)
	$(CC) $(FLAGS) $(HEADERS) $(MAIN_CHECK_O) $(OBJS) libft/libft.a -o $(NAME_CHECK)

$(NAME_PS): $(MAIN_PS_O) $(OBJS)
	$(CC) $(FLAGS) $(HEADERS) $(MAIN_PS_O) $(OBJS) libft/libft.a -o $(NAME_PS)

clean:
	cd libft && $(MAKE) clean
	rm -rf $(OBJS)
	rm -rf $(MAIN_PS_O)
	rm -rf $(MAIN_CHECK_O)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME_PS)
	rm -f $(NAME_CHECK)

mylib:
	cd libft && $(MAKE)

re: fclean all

%.o : %.c push_swap.h libft/libft.h
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@