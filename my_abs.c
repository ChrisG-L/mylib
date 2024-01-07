/*
** EPITECH PROJECT, 2023
** ABSCISSE
** File description:
** abs int and float
*/

#include "my.h"

int my_abs(int nb)
{
    if (nb < 0)
        return nb * -1;
    return nb;
}
