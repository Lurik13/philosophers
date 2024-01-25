# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 18:34:10 by lribette          #+#    #+#              #
#    Updated: 2024/01/25 19:21:41 by lribette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = death.c main.c manage_routine.c routine.c time.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(SOURCES) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re