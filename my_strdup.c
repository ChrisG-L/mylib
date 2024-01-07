/*
** EPITECH PROJECT, 2023
** STRDUP
** File description:
** Utili malloc
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
    int len = my_strlen(src) + 1;
    char *dest;

    if (src == NULL)
        return NULL;
    dest = malloc(len);
    dest = my_strcpy(dest, src);
    dest[len - 1] = '\0';
    return dest;
}
