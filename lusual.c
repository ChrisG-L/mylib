/*
** EPITECH PROJECT, 2023
** Usuel
** File description:
** Usual function
*/

#include "printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
        int i = 0;

        while (str[i] != '\0') {
                my_putchar(str[i]);
                i += 1;
        }
        return 0;
}

int my_put_nbr(int nb)
{
        int count = 0;

        if (nb < -2147483647) {
                my_putstr("-2147483648");
                return 11;
        } else if (nb < 0) {
                nb = nb * -1;
                my_putchar('-');
                count += 1;
        }
        if (nb >= 10) {
                count += my_put_nbr(nb / 10);
                count += my_put_nbr(nb % 10);
        } else {
                my_putchar(nb + '0');
                count += 1;
        }
        return count;
}

int my_put_nbrenoctal(unsigned int nb)
{
    if (nb >= 8) {
        my_put_nbrenoctal(nb / 8);
    }
    my_putchar((nb % 8) + '0');
    return 0;
}
