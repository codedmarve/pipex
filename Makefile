# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:22:44 by moduwole          #+#    #+#              #
#    Updated: 2022/11/21 13:22:44 by moduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRC		=	*.c

CC		=	gcc

CFLAGS	=	-Werror -Wextra -Wall

LIB_DIR =	./libft/
LIBFT	=	./libft/libft.a



all:	$(NAME)
	
$(NAME):	$(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all