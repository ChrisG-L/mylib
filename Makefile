##
## EPITECH PROJECT, 2023
## Header epitech
## File description:
## Makefile
##

NAME = libmy.a

SRCS = 	fct.c 	\
		fct2.c	\
		fct3.c	\
		fct4.c 	\
		usual.c	\
		usual2.c \
		lusual.c	\
		lusual2.c \
		my_printf.c \
		structinitializer.c \
		usual3.c \
		usualf.c \
		usual2f.c \
		usual3f.c \
		my_strcmp.c \
		my_str_to_word_array.c \
		my_strncpy.c \
		my_atoi.c \
		my_abs.c \
		my_strdup.c \
		my_strtok.c \
		my_strstr.c \
		allocgest.c \
		my_cleanstr.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	gcc -g3 -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

unit_test : $(SRCS) tests/testbs.c ./lib/libmy.a
	gcc tests/testbs.c $(SRCS) -I. -L./lib/ -lmy -lcriterion --coverage

tests_run : unit_test
	./a.out

testfclean : fclean
	rm -f ./a.out
	rm -f *.gc*

run : all
	./$(NAME)
