/*
** EPITECH PROJECT, 2023
** Init struct
** File description:
** Init structurediffspecifier
*/

#include "printf.h"

void structinitflags(char *str, int *i, finfo *Fi)
{
    int entered = 0;
    char Flag = str[*i];

    if (str[*i] == '-' || str[*i] == '+' || str[*i] == '0' ||
        str[*i] == '#' || str[*i] == ' ') {
        Fi->flags = Flag;
        *i += 1;
    }
}

void structinitwidth(char *str, int *i, finfo *Fi)
{
    if (my_char_isnum(str[*i])) {
        Fi->width = 0;
        while (my_char_isnum(str[*i])) {
            Fi->width = Fi->width * 10 + (str[*i] - '0');
            *i += 1;
        }
    }
}

void structinitprecision(char *str, int *i, finfo *Fi)
{
    if (str[*i] == '.') {
        Fi->precision = 0;
        *i += 1;
        while (my_char_isnum(str[*i])) {
            Fi->precision = Fi->precision * 10 + (str[*i] - '0');
            *i += 1;
        }
    }
}

void structinitlength(char *str, int *i, finfo *Fi)
{
    if (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'L') {
        Fi->length = str[*i];
        *i += 1;
    }
}

finfo structinit(char *str, int *i)
{
    finfo Fi = { -1, -1, 6, -1 };

    structinitflags(str, i, &Fi);
    structinitwidth(str, i, &Fi);
    structinitprecision(str, i, &Fi);
    structinitlength(str, i, &Fi);
    return Fi;
}
