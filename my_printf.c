/*
** EPITECH PROJECT, 2023
** Miniprintf
** File description:
** Mini my_printf (4 flags)
*/

#include "printf.h"

int formatinterro(char *str, int *i, va_list list, ptr_t func[])
{
    int j = 0;
    char l[] = {'c', 'd', 'i', 's', 'u', 'o', 'f', 'x', 'X', 'p', 'e', 'g', 0};
    finfo_t Fi;

    if (str[*i] == '%') {
        *i += 1;
        Fi = structinit(str, i);
        for (j = 0; l[j] != 0 && str[*i] != l[j]; j += 1);
        if (l[j]) {
            func[j](list, Fi);
        } else {
            write(1, &str[*i], 1);
        }
    } else {
        write(1, &str[*i], 1);
    }
    return 0;
}

int my_printf(char *str, ...)
{
    va_list list;
    ptr_t func[] = {&my_putcharf, &my_put_nbrf, &my_put_nbrf, &my_putstrf,
        &my_put_nbrunsignedf, &my_put_nbrenoctalf, &my_put_floatf,
        &my_put_nbr_hexaf, &my_put_nbr_hexamajf, &ptr_f, &my_put_scienf,
        &my_put_floatautof};

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        formatinterro(str, &i, list, func);
    }
    va_end(list);
    return 0;
}
