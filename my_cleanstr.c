/*
** EPITECH PROJECT, 2023
** Clean STR
** File description:
** Suppr tab and space
*/

#include "my.h"

void intern1(char *car1, char *car2, int *j, int *space)
{
    *car1 = *car2;
    *j += 1;
    *space = 0;
}

char *my_cleanstr(char *str)
{
    int i = 0;
    int j = 0;
    int space = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i += 1;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t')
            intern1(&str[j], &str[i], &j, &space);
        if ((str[i] == ' ' || str[i] == '\t') && !space) {
            str[j] = ' ';
            j += 1;
            space = 1;
        }
        i += 1;
    }
    if (j > 0 && str[j - 1] == ' ')
        j -= 1;
    str[j] = '\0';
    return str;
}
