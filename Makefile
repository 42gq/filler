# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 00:23:00 by gquerre           #+#    #+#              #
#    Updated: 2017/10/27 11:35:25 by gquerre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gquerre.filler

SRC = ./main.c\
	  ./ft_read.c\
	  ./parth/ft_scout.c\
	  ./treatment/ft_diag.c\
	  ./treatment/ft_find_pos.c\
	  ./treatment/ft_place.c\
	  ./treatment/ft_test_pos.c\
	  ./treatment/ft_treat.c\
	  ./maj/ft_maj.c\
	  ./maj/ft_majmap.c\
	  ./mask/ft_create_mask.c\
	  ./mask/ft_maj_mask.c\
	  ./mask/ft_sum.c\
	  ./init/ft_init_val.c\
	  ./init/ft_init_val_piece.c\
	  ./mask/ft_distance.c

FLAG = -Wextra -Wall -Werror

SUPP = ./filler.h ./libft/libft.a

OBJ = ft_read.o\
	  ft_scout.o\
	  ft_diag.o\
	  ft_find_pos.o\
	  ft_place.o\
	  ft_test_pos.o\
	  ft_treat.o\
	  ft_maj.o\
	  ft_majmap.o\
	  ft_create_mask.o\
	  ft_maj_mask.o\
	  ft_sum.o\
	  ft_init_val.o\
	  ft_init_val_piece.o\
	  ft_distance.o

all: $(NAME)

$(NAME) : libft/libft.a $(SRC)
	gcc -I $(SUPP) -g $(SRC) -o $(NAME)

libft/libft.a:
	make fclean -C libft/
	make -C libft/

clean:
	rm -f $(OBJ)
	rm -f libft/libft.a
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/

re : fclean all
