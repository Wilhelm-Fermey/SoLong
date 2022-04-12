# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfermey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 09:20:51 by wfermey           #+#    #+#              #
#    Updated: 2022/04/12 14:48:15 by wfermey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

${NAME}:	
			gcc -Wall -Werror -Wextra main.c get_next_line.c \
			get_next_line_utils.c  ft_split.c check.c \
			check2.c print.c hook.c else.c free.c -o $(NAME) -L/usr/local/lib \
			-lmlx -framework OpenGL -framework AppKit

all:		${NAME}

clean:
			rm $(NAME)	

fclean:
			rm $(NAME)

re: fclean all
