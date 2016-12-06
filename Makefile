##
## Makefile for  in /home/maryem/libmy/Librairie/libmy_03
## 
## Made by ENNAMOURI Maryem
## Login   <ennamo_m@etna-alternance.net>
## 
## Started on  Thu Oct 27 13:43:15 2016 ENNAMOURI Maryem
## Last update Tue Dec  6 12:26:41 2016 ENNAMOURI Maryem
##

CC = gcc

NAME = 	my_sta

SRC = 	main.c		\
	getCreature.c	\
	readline.c	\
	my_string.c

NAME_LIB = libmy.a

SRC_LIB  =	libmy_03/my_putchar.c	\
		libmy_03/my_isneg.c	\
		libmy_03/my_put_nbr.c	\
		libmy_03/my_swap.c	\
		libmy_03/my_putstr.c	\
		libmy_03/my_strlen.c 	\
		libmy_03/my_getnbr.c	\
		libmy_03/my_strcpy.c	\
		libmy_03/my_strncpy.c 	\
		libmy_03/my_strcmp.c 	\
		libmy_03/my_strncmp.c 	\
		libmy_03/my_strcat.c 	\
		libmy_03/my_strncat.c 	\
		libmy_03/my_strstr.c 	\
		libmy_03/my_strdup.c 	\
		libmy_03/my_str_to_wordtab.c

OBJ_LIB		=	$(SRC_LIB:%.c=%.o)

OBJ		=	$(SRC:%.c=%.o)
RM		= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror
LDSFLAGS	= 	-L. -lmy


$(NAME):	$(NAME_LIB) $(OBJ)
		$(CC) $(OBJ) $(LDSFLAGS) -o $(NAME)

$(NAME_LIB): 	$(OBJ_LIB)
		ar r $(NAME_LIB) $(OBJ_LIB)
		ranlib $(NAME_LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ_LIB)
fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAME_LIB)

re:		fclean all	
.PHONY: 	all	clean	fclean
