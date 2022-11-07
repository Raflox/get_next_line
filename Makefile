# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafilipe <rafilipe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 17:27:49 by rafilipe          #+#    #+#              #
#    Updated: 2022/11/07 11:30:52 by rafilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re