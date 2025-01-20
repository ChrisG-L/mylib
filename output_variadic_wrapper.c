/*
** EPITECH PROJECT, 2023
** Fonction usuelle argvariadic
** File description:
** Fonction usuelle qui récupére la donnée depuis list variadique
*/

#include "printf.h"

int my_putcharf(va_list va, finfo_t Fi)
{
    int c = va_arg(va, int);

    write(1, &c, 1);
    return 0;
}

int my_putstrf(va_list va, finfo_t Fi)
{
    char *str = va_arg(va, char *);
    int i = 0;

    if (str == NULL) {
        my_putstr("(null)");
        return 0;
    }
    while (str[i] != '\0') {
            my_putchar(str[i]);
            i += 1;
    }
    return 0;
}

int my_put_nbrf(va_list va, finfo_t Fi)
{
    int nb = va_arg(va, int);
    int count = 0;

    if (Fi.flags == '+') {
        if (nb >= 0) {
            my_putchar('+');
            count += 1;
        }
    }
    if (nb < -2147483647) {
            my_putstr("-2147483648");
            return 11;
    } else {
        count += my_put_nbr(nb);
    }
    return count;
}

int my_put_nbrenoctalf(va_list va, finfo_t Fi)
{
    unsigned int nb = va_arg(va, unsigned int);

    if (Fi.flags == '#') {
        my_putstr("0");
    }
    if (nb >= 8) {
        my_put_nbrenoctal(nb / 8);
    }
    my_putchar((nb % 8) + '0');
    return 0;
}
