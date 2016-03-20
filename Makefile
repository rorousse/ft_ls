#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/03/20 16:34:10 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
HEADER = ft_printf.h libft/libft.h
SRC_PATH=./
OBJ_PATH=./
LIBS= ft_printf/libftprintf.a
SRC = main.c listing.c tri.c flags.c ft_ls.c paths.c recursion.c affichage.c

OBJ = $(SRC:.c=.o )

all : lib $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) $(LIBS) -o $(NAME)

lib :
	make -C ft_printf/

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean :
	/bin/rm -f $(OBJ)
	make clean -C ft_printf/

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C ft_printf/

re : fclean all
