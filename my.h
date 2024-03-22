/*
** EPITECH PROJECT, 2023
** bs Setting Up
** File description:
** bs Setting Up
*/

#ifndef MY_H_
    #define MY_H_

    #include "printf.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <stdlib.h>
    #include <stdio.h>

typedef struct square_s {
    int tempsize;
    int size;
    int row;
    int col;
} square_t;

void fs_understand_return_of_read(int fd, char *buffer, int size);
int fs_open_file(char const *filepath);
void fs_cat_500_bytes(char const *filepath);
void fs_cat_x_bytes(char const *filepath, int x);
void fs_print_first_line(char const *filepath);
int fs_get_number_from_first_line(char const *filepath);
char *my_strncpy(char *dest, const char *src, int n);
int my_atoi(char *str);
char *my_strdup(char *src);
char *my_itoa(int nb);
char *my_revstr(char *str);
int tokenlen(char *str, char delim);
int my_strncmp(const char *str1, const char *str2, int n);
char **my_strtok(char *str, char delim);
char *my_strstr(char *str, const char *to_find);

int mylenoflign(const char *filepath);
int mylenofbiggerlign(const char *filepath);
int mylenoflignbuffer(char *buffer);
int mynumoflign(const char *filepath);
char **my_str_to_word_array(char const *str);
int extractnumberforpos(char *str, int *number, int *i);
void compareajout(int nb, int ref, int *total);
char *my_strcpy(char *dest, char const *src);
void copy_char(int i, char const *src, char *dest);
char *my_stpcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_strcmp(const char *str1, const char *str2);
struct stat returnfile(char const *filepath);

void array_1d_print_chars(char const *arr);
void array_1d_print_ints(int const *arr, int size);
int array_1d_sum(int const *arr, int size);
int array_2d_sum(int **arr, int nb_rows, int nb_cols);
int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number);
char *mem_alloc(char const *a, char const *b);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int is_square_of_size(char **map, int row, int col, int square_size);
square_t *find_biggest_square(char **map, int nb_rows, int nb_cols);

#endif /* !MY_H_ */
