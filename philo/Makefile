# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 17:43:56 by mlachheb          #+#    #+#              #
#    Updated: 2021/07/11 17:57:05 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

MAIN = philosophers.c

SRC = fatal.c libft_functions.c philosopher_actions.c philosopher_prints.c\
	philosophers_functions.c read_check_args.c supervisor.c threads_functions.c\
	time_functions.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) $(MAIN) -o $(NAME)

clean: 
	echo "No object files to remove."

fclean:
	rm -rf $(NAME)

re: fclean all

noflags:
	gcc $(SRC) $(MAIN) -o $(NAME)
