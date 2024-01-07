/*
** EPITECH PROJECT, 2023
** BS setting up
** File description:
** BS setting up usual fct
*/

#include "my.h"

int mylenoflign(const char *filepath)
{
    int fd = fs_open_file(filepath);
    char buffer;
    int len = 0;

    while (read(fd, &buffer, 1) == 1) {
        if (buffer == '\n') {
            break;
        }
        len += 1;
    }
    close(fd);
    return len;
}

int extractnumberforpos(char *str, int *number, int *i)
{
    char sign = 0;

    if (*i != 0 && str[*i - 1] == '-') {
        *i += 1;
        while (my_char_isnum(str[*i])) {
            *i += 1;
        }
    }
    if (my_char_isnum(str[*i])) {
        *number = str[*i] - '0';
        *i += 1;
        while (my_char_isnum(str[*i])) {
            *number = *number * 10 + (str[*i] - '0');
            *i += 1;
        }
        return 1;
    } else {
        return 0;
    }
}

void compareajout(int nb, int ref, int *total)
{
    if (nb == ref) {
        *total += 1;
    }
}

void copy_char(int i, char const *src, char *dest)
{
    dest[i] = src[i];
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        copy_char(i, src, dest);
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
