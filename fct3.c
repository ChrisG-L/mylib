/*
** EPITECH PROJECT, 2023
** Bs setting up
** File description:
** bs su
*/

#include "my.h"

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int total = 0;

    for (int i = 0; i < nb_rows; i += 1) {
        for (int y = 0; y < nb_cols; y += 1) {
            compareajout(arr[i][y], number, &total);
        }
    }
    return total;
}

char *mem_alloc(char const *a, char const *b)
{
    char *str = malloc(my_strlen(a) + my_strlen(b) + 2);

    my_strcpy(str, a);
    my_strcat(str, b);
    return str;
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i += 1) {
        arr[i] = malloc(nb_cols * sizeof(char));
    }
    return arr;
}

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **arr2 = mem_alloc_2d_array(nb_rows, nb_cols);

    arr2 = arr;
    return arr2;
}

char *load_file_in_mem(char const *filepath)
{
    struct stat file = returnfile(filepath);
    int size = file.st_size;
    int fd = fs_open_file(filepath);
    char *buffer = malloc(sizeof(char *) * (size + 1));
    int bytes_read = 0;

    bytes_read = read(fd, buffer, size);
    if (bytes_read == -1) {
        return 0;
    }
    buffer[bytes_read] = '\0';
    return buffer;
}
