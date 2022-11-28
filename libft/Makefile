# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 09:25:04 by moduwole          #+#    #+#              #
#    Updated: 2022/05/11 09:25:04 by moduwole         ###   ########.fr        #
#      \\\\\\\\                                                                        #
# **************************************************************************** #

NAME		=		libft.a

SRC			= 		ft_calloc.c       ft_isdigit.c  ft_memcmp.c      ft_putchar_fd.c  ft_split.c  \
					ft_strjoin.c      ft_strmapi.c  ft_strtrim.c     ft_isalnum.c     ft_toupper.c  \
					ft_isprint.c      ft_memcpy.c   ft_putendl_fd.c  ft_strchr.c      ft_strlcat.c  \
					ft_strncmp.c      ft_substr.c   ft_atoi.c        ft_isalpha.c     ft_itoa.c  \
					ft_putnbr_fd.c    ft_strdup.c   ft_strlcpy.c     ft_strnstr.c     ft_tolower.c  \
					ft_bzero.c        ft_isascii.c  ft_memchr.c      ft_memset.c      ft_putstr_fd.c  \
					ft_striteri.c     ft_strlen.c   ft_strrchr.c     ft_memmove.c	  ft_utoa.c  \
					ft_puthexi.c	  ft_hexi.c 	ft_printf.c		 ft_put.c 		  ft_putadd.c  \
					get_next_line.c   ft_strcpy.c	ft_strcat.c \

OBJ			=		$(SRC:.c=.o)

CC			=		gcc

CFLAGS		=		-Werror -Wextra -Wall

BONUS		=		ft_lstadd_back.c  ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c	  ft_lstlast.c \
					ft_lstmap.c	ft_lstnew.c	ft_lstsize.c \

B_OBJ		=		$(BONUS:.c=.o)

all:				$(NAME)

$(NAME):			$(OBJ)
							ar -crs $(NAME) $(OBJ)

$(OBJ):				$(SRC)

bonus:				$(OBJ) $(B_OBJ)
							ar -crs $(NAME) $(OBJ) $(B_OBJ)

clean:
							rm -f $(OBJ) $(B_OBJ)

fclean:				clean
							rm -f $(NAME)

re:					fclean $(NAME)

