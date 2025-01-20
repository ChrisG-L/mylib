/*
** EPITECH PROJECT, 2023
** Fonction usuelle flag comp
** File description:
** Fonction usuelle flags complexe
*/

#include "printf.h"

int my_put_nbrunsigned(unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbrunsigned(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}

int my_put_nbr_hexa(unsigned long int nb)
{
    char digit = 0;

    if (nb >= 16) {
        my_put_nbr_hexa(nb / 16);
    }
    digit = (nb % 16 < 10) ? (nb % 16 + '0') : (nb % 16 - 10 + 'a');
    my_putchar(digit);
    return 0;
}

int my_put_nbr_hexamaj(unsigned int nb)
{
    char digit = 0;

    if (nb >= 16) {
        my_put_nbr_hexamaj(nb / 16);
    }
    digit = (nb % 16 < 10) ? (nb % 16 + '0') : (nb % 16 - 10 + 'A');
    my_putchar(digit);
    return 0;
}

int my_put_float(double nb, int precision)
{
    int int_part = (int) nb;
    float frac_part = nb - int_part;
    int digit = 0;
    int count = 0;

    count += my_put_nbr(int_part);
    if (precision != 0) {
        my_putchar('.');
        count += 1;
    }
    for (int i = 0; i < precision; i += 1) {
        frac_part *= 10;
        digit = (int)frac_part;
        count += my_put_nbr(digit);
        frac_part -= digit;
        digit = 0;
    }
    return count;
}
