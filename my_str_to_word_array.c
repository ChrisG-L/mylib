/*
** EPITECH PROJECT, 2023
** STR TO WORD ARRAY
** File description:
** split str in array
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int count(const char *str, int i)
{
    int a = 0;

    while ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
        a += 1;
        i += 1;
    }
    return a;
}

int nbmot(char const *str)
{
    int nb = 0;
    int i = 0;
    int len = my_strlen(str);

    if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') ||
        (str[i] >= '0' && str[i] <= '9')) {
        nb += 1;
    }
    for (i = 0; i < len; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
            i += count(str, i);
            nb += 1;
        } else {
            i += 1;
        }
    }
    return nb;
}

void extract(char const *str, char **dest, int *i, int *word_index)
{
    int word_i = *i;
    int wordlen = 0;

    while ((str[*i] >= 65 && str[*i] <= 90) ||
            (str[*i] >= 97 && str[*i] <= 122) ||
            (str[*i] >= '0' && str[*i] <= '9')) {
        wordlen += 1;
        *i += 1;
    }
    dest[*word_index] = malloc(wordlen + 1);
    my_strncpy(dest[*word_index], str + word_i, wordlen);
    dest[*word_index][wordlen] = '\0';
    *word_index += 1;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int len = my_strlen(str);
    int wordlen = 0;
    int word_index = 0;
    int word_i = 0;
    char **dest;
    int nb = nbmot(str);

    dest = malloc((nb + 1) * sizeof(char *));
    while (i < len) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
            extract(str, dest, &i, &word_index);
        } else {
            i += 1;
        }
    }
    dest[nb] = 0;
    return dest;
}
