# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 18:34:10 by lribette          #+#    #+#              #
#    Updated: 2024/01/10 17:29:21 by lribette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = utils.c main.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g

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