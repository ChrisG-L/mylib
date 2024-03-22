/*
** EPITECH PROJECT, 2023
** BS setting up
** File description:
** BS setting up usual fct
*/

#include "my.h"

char *my_stpcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    while (src[i] != '\0') {
        copy_char(i, src, dest);
        i += 1;
    }
    dest[i] = '\0';
    return &dest[i];
}

char *my_strcat(char *dest, char const *src)
{
    my_stpcpy(dest + my_strlen(dest), src);
    return dest;
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
            i += 1;
    }
    return i;
}

struct stat returnfile(char const *filepath)
{
    struct stat file;

    if (stat(filepath, &file) == -1) {
        write(2, "File not found\n", 15);
        return file;
    }
    return file;
}
