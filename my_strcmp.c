/*
** EPITECH PROJECT, 2023
** Comparer str
** File description:
** Comparaison de str avec str < ou > ou =
*/

#include "my.h"

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return -1;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i += 1;
    }
    if (str1[i] == str2[i]) {
        return 0;
    } else if (str1[i] < str2[i]) {
        return -1;
    } else {
        return 1;
    }
}

int my_strncmp(const char *str1, const char *str2, int n)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] &&
        i < n - 1) {
        i += 1;
    }
    if (str1[i] == str2[i]) {
        return 0;
    } else if (str1[i] < str2[i]) {
        return -1;
    } else {
        return 1;
    }
}
