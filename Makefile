# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trkapous <trkapous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 16:17:17 by trkapous          #+#    #+#              #
#    Updated: 2016/05/20 13:26:17 by baalbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

SRC = main.c\
	  algo.c\
	  check.c\
	  lstool.c\
	  printmap.c\
	  read.c\
	  tool.c\
	  printtool.c \
	  math.c \

CC = gcc

DEL = rm -f
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(DEL) fillit.h.gch
	@$(CC) $(FLAG) $(SRC) -o $(NAME)
	@echo
	@echo "make -> $(NAME) created"
	@echo

clean: start
	@$(DEL) fillit.h.gch
	@echo
	@echo "clean -> fillit.h.gch deleted"
	@echo

fclean: clean
	@$(DEL) $(NAME)
	@$(DEL) fillit.h.gch
	@echo
	@echo "fclean -> $(NAME) and fillit.h.gch deleted"
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded"
	@echo

start:
	@echo "################"
	@echo "### MAKEFILE ###"
	@echo "################"

.PHONY: all clean fclean re

