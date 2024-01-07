/*
** EPITECH PROJECT, 2023
** BS setting up
** File description:
** Bs setting up
*/

#include "my.h"

int fs_get_number_from_first_line(char const *filepath)
{
    int len = mylenoflign(filepath);
    int fd = fs_open_file(filepath);
    char *buffer = malloc(sizeof(char *) * (len + 1));
    int bytes_read = 0;
    int number = -1;

    bytes_read = read(fd, buffer, len);
    if (bytes_read == -1) {
        return -1;
    }
    buffer[bytes_read] = '\0';
    for (int i = 0; i < len; i += 1) {
        if (extractnumberforpos(buffer, &number, &i)) {
            break;
        }
    }
    return number;
}

void array_1d_print_chars(char const *arr)
{
    int i = 0;

    while (arr[i] != '\0') {
        my_printf("%c\n", arr[i]);
        i += 1;
    }
}

void array_1d_print_ints(int const *arr, int size)
{
    int i = 0;

    while (i < size) {
        my_printf("%i\n", arr[i]);
        i += 1;
    }
}

int array_1d_sum(int const *arr, int size)
{
    int i = 0;
    int total = 0;

    while (i < size) {
        total += arr[i];
        i += 1;
    }
    return total;
}

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int total = 0;

    for (int i = 0; i < nb_rows; i += 1) {
        for (int y = 0; y < nb_cols; y += 1) {
            total += arr[i][y];
        }
    }
    return total;
}
