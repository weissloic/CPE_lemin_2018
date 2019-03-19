##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile the lib
##

CC	=	gcc -g

SRC	=	my_compute_square_root.c	\
		my_compute_power_rec.c		\
		my_find_prime_sup.c			\
		my_getnbr.c					\
		my_is_prime.c				\
		my_isneg.c					\
		my_put_nbr.c				\
		my_putchar.c				\
		my_putstr.c					\
		my_revstr.c					\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c		\
		my_str_isupper.c			\
		my_strcapitalize.c			\
		my_strcat.c					\
		my_strcmp.c					\
		my_strcpy.c					\
		my_strlen.c					\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c					\
		my_strupcase.c				\
		my_swap.c					\
		print_base.c				\
		print_basicfunc.c			\
		print_float.c				\
		printf.c                    \
		my_memset.c                 \

RED     = \033[0;31m
YELLOW  = \033[1;33m
CYAN    = \033[0;36m
GOLD    = \033[0;33m
GREEN   = \033[0;32m
BLUE	= \033[0;34m
NC	    = \033[0;0m

OBJ  	= $(SRC:%.c=%.o)

NAME 	= libmy.a

PREFIX  = $(GREEN)"[LIB] "

all:	 $(NAME)

%.o: %.c
	$(CC) -c -o $@ $^
	echo "$(PREFIX)$(YELLOW)$^ $(GREEN)=> $(YELLOW)$@$(NC)"

$(NAME):  $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(PREFIX)$(RED)Delete .o$(NC)"
	@echo "$(PREFIX)$(BLUE)Created $(NAME) !$(NC)"
	@rm -f *.o

clean:
	rm -f *~ *# *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all clean

