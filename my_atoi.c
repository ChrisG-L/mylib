/*
** EPITECH PROJECT, 2023
** Atoi
** File description:
** str_to_int
*/

#include "my.h"

int is_num(char carac)
{
    if (carac >= '0' && carac <= '9') {
        return 1;
    }
    return 0;
}

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

char *my_revstr(char *str)
{
    int len = 0;
    int i;
    char c;

    for (; str[len]; len++);
    for (i = 0; str[i + i - len % 2]; i++) {
        c = str[i];
        *(str + i) = str[len - i - 1];
        *(str + len - i - 1) = c;
    }
    return (str);
}

char *my_itoa(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 12);

    if (nb == 0)
        return "0";
    if (nb < 0) {
        str[i] = '-';
        i += 1;
        nb *= -1;
    }
    while (nb > 0) {
        str[i] = nb % 10 + '0';
        nb /= 10;
        i += 1;
    }
    str[i] = '\0';
    return my_revstr(str);
}
