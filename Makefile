#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/04/10 15:21:41 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCNAME =	affichage.c	\
			build.c		\
			date.c		\
			flags.c		\
			ft_ls.c		\
			listing.c	\
			main.c		\
			paths.c		\
			printage.c	\
			recursion.c	\
			tri.c		\
			usage.c		\

SRCPATH = ./srcs/

SRC = $(addprefix $(SRCPATH), $(SRCNAME))

OBJNAME = $(SRCNAME:.c=.o)

OBJPATH = ./objs/

OBJ = $(addprefix $(OBJPATH), $(OBJNAME))

NAME = ft_ls

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ft_printf/
	gcc $(FLAG) $(OBJ) ft_printf/libftprintf.a -o $(NAME)

$(OBJPATH)%.o:	$(SRCPATH)%.c
	gcc $(FLAGS) -I ./ -c $< -o $@

clean:
	/bin/rm $(OBJ)
	make -C ./ft_printf/ clean

fclean: clean
	/bin/rm $(NAME)
	make -C ./ft_printf/ fclean

re:	fclean  all

