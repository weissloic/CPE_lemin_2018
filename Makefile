##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

.RECIPEPREFIX +=

CC      =       gcc

SRC     =   main.c \
            src/my_put_nbr.c \
            src/my_putchar.c \
            src/my_putstr.c \
            src/my_getnbr.c

OBJ     =       $(SRC:.c=.o)

NAME    =       lemin

CFLAGS  =       -W -Wextra -Wall -ansi -pedantic -g -std=c99 -I ./include

all:    $(NAME)

$(NAME):	$(OBJ)
    $(CC) $(OBJ) -o $(NAME) $(CFLAGS)
    rm -f $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re:		fclean all