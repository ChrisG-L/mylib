/*
** EPITECH PROJECT, 2023
** Usuel
** File description:
** Usual function
*/

#include "my.h"

int my_put_scien(float nb, int precision)
{
    int int_part = (int) nb;
    int i = 0;

    for (; int_part == 0; int_part = (int) nb) {
        nb *= 10;
        i -= 1;
    }
    for (; int_part >= 10; int_part = (int) nb) {
        nb /= 10;
        i += 1;
    }
    my_put_float(nb, precision);
    my_putchar('e');
    printsign(&i);
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int mylenofbiggerlign(const char *filepath)
{
    int fd = fs_open_file(filepath);
    char buffer;
    int currentlen = 0;
    int maxlen = 0;

    while (read(fd, &buffer, 1) == 1) {
        if (buffer == '\n') {
            currentlen = 0;
            continue;
        }
        currentlen += 1;
        if (currentlen > maxlen) {
            maxlen = currentlen;
        }
    }
    close(fd);
    return maxlen;
}

int mylenoflignbuffer(char *buffer)
{
    int len = 0;

    while (buffer[len] != '\0') {
        if (buffer[len] == '\n') {
            break;
        }
        len += 1;
    }
    return len;
}

int mynumoflign(const char *filepath)
{
    int fd = fs_open_file(filepath);
    char buffer;
    int lines = 0;

    while (read(fd, &buffer, 1) == 1) {
        if (buffer == '\n') {
            lines += 1;
        }
    }
    close(fd);
    return lines;
}
