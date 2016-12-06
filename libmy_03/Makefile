##
## Makefile for  in /home/projet/CHIFUMI/libmy_03
## 
## Made by ENNAMOURI Maryem
## Login   <ennamo_m@etna-alternance.net>
## 
## Started on  Thu Oct 29 11:13:15 2016 ENNAMOURI Maryem
## Last update Thu Oct 29 11:33:29 2016 ENNAMOURI Maryem
##

NAME = 	libmy.a

SRC  =	my_putchar.c	\
	my_isneg.c	\
	my_put_nbr.c	\
	my_swap.c	\
	my_putstr.c	\
	my_strlen.c 	\
	my_getnbr.c	\
	my_strcpy.c	\
	my_strncpy.c 	\
	my_strcmp.c 	\
	my_strncmp.c 	\
	my_strcat.c 	\
	my_strncat.c 	\
	my_strstr.c 	\
	my_strdup.c 	\
	my_str_to_wordtab.c\
	main.c		\
	liste_chainee.c	\
	jeu.c		\

OBJ	=	$(SRC:%.c=%.o)
RM	= 	rm -f

$(NAME):	$(OBJ)
		ar r $(NAME) $(OBJ)
		ranlib $(NAME)

all:		$(NAME)

clean:		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)

.PHONY: 	all	clean	fclean
