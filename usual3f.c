/*
** EPITECH PROJECT, 2023
** Fonction usuelle argvariadic flag comp
** File description:
** Fonction usuelle qui récup. la donnée depuis list variadique flags complexe
*/

#include "printf.h"

void printsign(int *i)
{
    if (*i < 0) {
        my_putstr("-");
        *i = -(*i);
    } else
        my_putstr("+");
}

int my_put_scienf(va_list va, finfo Fi)
{
    float nb = (float) va_arg(va, double);
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
    my_put_float(nb, Fi.precision);
    my_putchar('e');
    printsign(&i);
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}

int my_put_floatautof(va_list va, finfo Fi)
{
    double nb = va_arg(va, double);
    double stock = nb;
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
    if (Fi.precision > i && i >= -4) {
        my_put_float(stock, Fi.precision - (i + 1));
    } else {
        my_put_scien(stock, Fi.precision - 1);
    }
}
