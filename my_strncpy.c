/*
** EPITECH PROJECT, 2023
** Renvoie copie n carac
** File description:
** Copie de n octets
*/

#include "my.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i += 1;
    }
    while (i < n) {
        dest[i] = '\0';
        i += 1;
    }
    return dest;
}
