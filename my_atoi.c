/*
** EPITECH PROJECT, 2023
** Atoi
** File description:
** str_to_int
*/

#include "my.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str[0] == '-') {
        neg = -1;
        i += 1;
    }
    while (str[i] != '\0') {
        nb = nb * 10 + str[i] - '0';
        i += 1;
    }
    return nb * neg;
}
