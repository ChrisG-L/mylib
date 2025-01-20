/*
** EPITECH PROJECT, 2023
** bs Setting Up
** File description:
** bs Setting Up
*/

#include "my.h"

int fs_open_file(char const *filepath)
{
    int x = open(filepath, O_RDONLY);

    if (x == -1) {
        write(2, "File not found\n", 15);
        return 84;
    }
    return x;
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int bytes_read = read(fd, buffer, size);

    if (bytes_read == -1) {
        my_printf("read failed\n");
        return;
    }
    if (bytes_read == 0) {
        my_printf("read has nothing more to read\n");
        return;
    }
    if (bytes_read < size) {
        my_printf("read didn't complete the entire buffer\n");
        return;
    }
    my_printf("read completed the entire buffer\n");
}

void fs_cat_500_bytes(char const *filepath)
{
    int fd = fs_open_file(filepath);
    int bytes_read = 0;
    char buffer[501];

    bytes_read = read(fd, buffer, 500);
    if (bytes_read == -1) {
        return;
    }
    buffer[bytes_read] = '\0';
    my_printf(buffer);
    close(fd);
}

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = fs_open_file(filepath);
    char *buffer = malloc(sizeof(char *) * (x + 1));
    int bytes_read = 0;

    bytes_read = read(fd, buffer, x);
    if (bytes_read == -1) {
        return;
    }
    buffer[bytes_read] = '\0';
    my_printf(buffer);
    close(fd);
}

void fs_print_first_line(char const *filepath)
{
    int len = mylenoflign(filepath);

    fs_cat_x_bytes(filepath, len);
}
