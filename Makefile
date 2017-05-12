# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeziyan <mmeziyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 18:15:03 by mmeziyan          #+#    #+#              #
#    Updated: 2017/05/05 19:24:46 by juhallyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_Colors_#

GREEN	=	echo "\x1b[32m $1 \x1b[0m $2"

PURPLE	=	echo "\x1b[35m $1 \x1b[0m $2"

#_Files_#

NAME	=	fillit

SRC 	=	check_map.c		\
			coord.c			\
			function.c		\
			main.c			\
			place.c			\
			solve.c			\
			solve_tools.c	\

OBJ		=	$(SRC:.c=.o)

LIB		=	Includes/libft/

#_Compilation_#

FLAG 	=	-W -Wall -Wextra -Werror

all: $(NAME)

norm:
	@clear
	@norminette $(SRC)

#_Compilation_#

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@(cd $(LIB) && $(MAKE) libft.a)
	@gcc $(OBJ) Includes/libft/libft.a  -o $(NAME)

clean:
	@rm -f $(OBJ)
	@(cd $(LIB) && $(MAKE) $@)

fclean:
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all norm clean fclean
