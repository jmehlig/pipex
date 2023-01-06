# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 12:26:53 by jmehlig           #+#    #+#              #
#    Updated: 2021/12/17 19:32:43 by jmehlig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

C_FLAGS=-Wall -Wextra -Werror

NAME_MAIN=pipex

LIBS=libft/libft.a

SRC_DIR=./
SRC_LIST_MAIN= pipex.c
SRC_LIST= free.c\

SRC=$(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_MAIN= $(addprefix $(SRC_DIR), $(SRC_LIST_MAIN))

all: $(NAME_MAIN)

$(NAME_MAIN): $(SRC) $(SRC_MAIN)
	make -C libft
	$(CC) $(C_FLAGS) $^ $(LIBS) -o $@

$(OBJ_LIST): $(SRC_LIST)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f $(NAME_MAIN) $(NAME_BONUS)

re:
	make fclean
	make $(NAME)
