# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 13:43:19 by luisanch          #+#    #+#              #
#    Updated: 2024/08/16 11:29:48 by luisanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC  = main.c init.c utils.c
MANPATH =
FLAGS	= -Wall -Werror -Wextra -03 -pthread
HEADER = philo


all : $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)
	