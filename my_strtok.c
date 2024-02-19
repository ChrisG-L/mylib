/*
** EPITECH PROJECT, 2023
** Str tok perso
** File description:
** Split une string en fct d'un char
** Sans Rebond
*/

#include "my.h"

int tokenlen(char *str, char delim)
{
    int nbtoken = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            nbtoken += 1;
    }
    return nbtoken;
}

int strtokenlen(char *str, int j, char delim)
{
    int len = 0;

    while (str[j] != delim && str[j] != '\0') {
        len += 1;
        j += 1;
    }
    return len;
}

int extracttoken(char *str, char **token, int active[2], char delim)
{
    int i = 0;
    int lenoftok = strtokenlen(str, active[1], delim);

    token[active[0]] = malloc(sizeof(char) * lenoftok + 1);
    while (i < lenoftok) {
        token[active[0]][i] = str[active[1]];
        i += 1;
        active[1] += 1;
    }
    token[active[0]][i] = '\0';
    return active[1] + 1;
}

char **my_strtok(char *str, char delim)
{
    int nbtoken = tokenlen(str, delim);
    char **token = malloc(sizeof(char *) * (nbtoken + 2));
    int i = 0;
    int j = 0;

    if (str == NULL)
        return NULL;
    for (; i <= nbtoken; i += 1) {
        j = extracttoken(str, token, (int[2]) {i, j}, delim);
    }
    token[i] = NULL;
    return token;
}
