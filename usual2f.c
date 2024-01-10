/*
** EPITECH PROJECT, 2023
** Fonction usuelle argvariadic flag comp
** File description:
** Fonction usuelle qui récup. la donnée depuis list var flags complexe
*/

#include "printf.h"

int my_put_nbrunsignedf(va_list va, finfo Fi)
{
    unsigned int nb = va_arg(va, unsigned int);

    if (nb >= 10) {
        my_put_nbrunsigned(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}

int my_put_floatf(va_list va, finfo Fi)
{
    double num = va_arg(va, double);
    int count = 0;

    if (Fi.flags == '+') {
        if (num >= 0) {
            my_putchar('+');
            count += 1;
        }
    }
    count += my_put_float(num, Fi.precision);
    return count;
}

int my_put_nbr_hexaf(va_list va, finfo Fi)
{
    unsigned int nb = va_arg(va, unsigned int);
    char digit = 0;

    if (Fi.flags == '#') {
        my_putstr("0x");
    }
    if (nb >= 16) {
        my_put_nbr_hexa(nb / 16);
    }
    digit = (nb % 16 < 10) ? (nb % 16 + '0') : (nb % 16 - 10 + 'a');
    my_putchar(digit);
    return 0;
}

int my_put_nbr_hexamajf(va_list va, finfo Fi)
{
    unsigned int nb = va_arg(va, unsigned int);
    char digit = 0;

    if (Fi.flags == '#') {
        my_putstr("0X");
    }
    if (nb >= 16) {
        my_put_nbr_hexamaj(nb / 16);
    }
    digit = (nb % 16 < 10) ? (nb % 16 + '0') : (nb % 16 - 10 + 'A');
    my_putchar(digit);
    return 0;
}

int ptr_f(va_list ap, finfo Fi)
{
    unsigned long int ptr;

    ptr = va_arg(ap, unsigned long int);
    my_putstr("0x");
    my_put_nbr_hexa(ptr);
    return 0;
}
