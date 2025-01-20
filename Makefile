##
## EPITECH PROJECT, 2023
## Header epitech
## File description:
## Makefile
##

NAME = libmy.a

SRCS = 	file_length.c 	\
		file_operations.c	\
		memory_allocation.c	\
		memory_management.c 	\
		operations_array.c	\
		operations_scientific.c \
		operations_string.c	\
		output_basic.c \
		output_complex.c \
		output_formatted.c \
		output_formatted_scientific.c \
		output_variadic_wrapper.c \
		my_printf.c \
		structinitializer.c \
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
		square_finder.c \

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
