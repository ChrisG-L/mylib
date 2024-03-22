/*
** EPITECH PROJECT, 2023
** FIND SUBSTR
** File description:
** trouver substr in str
*/

#include "my.h"

char *my_strstr(char *str, const char *to_find)
{
    int strlen = my_strlen(str);
    int finderlen = my_strlen(to_find);

    if (finderlen == 0) {
        return str;
    }
    for (int i = 0; i <= strlen; i += 1) {
        if (my_strncmp(&str[i], to_find, finderlen) == 0) {
            return &str[i];
        }
    }
    return 0;
}
