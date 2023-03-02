# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 12:01:23 by amateo-r          #+#    #+#              #
#    Updated: 2022/08/11 12:01:26 by amateo-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	SOURCES
SRC		=	./src/main.c \
			./src/exception_handlers.c \
			./src/libft/ft_strlen.c \
			./src/libft/ft_strncmp.c \
			./src/libft/ft_atoi.c \
			./src/libft/ft_timediff.c \
			./src/philosophers_actions.c \
			./src/forks.c \
			./src/init.c \
			./src/ft_print.c

OBJ		=	$(SRC:.c=.o)

#	COMPILER
NAME	=	philosophers
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
RM		=	rm -f

all:		$(NAME)

.%o.%c:		$(CC) $(CFLAGS) $<	-o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
