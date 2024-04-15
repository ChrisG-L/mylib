/*
** EPITECH PROJECT, 2019
** GITHUB_minif_2018
** File description:
** minif
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <unistd.h>
    #include <stdarg.h>

typedef struct fi {
    int flags;
    int width;
    int precision;
    int length;
} finfo_t;

typedef int (*ptr_t)(va_list, finfo_t);
int my_printf(char *str, ...);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_put_nbrenoctal(unsigned int nb);
int my_put_nbr_hexa(unsigned long int nb);
int my_put_nbr_hexamaj(unsigned int nb);
int my_put_nbrunsigned(unsigned int nb);
int my_char_isnum(char c);
int my_putcharf(va_list va, finfo_t Fi);
int my_putstrf(va_list va, finfo_t Fi);
int my_abs(int nb);
int my_strlenf(va_list va, finfo_t Fi);
int my_put_nbrf(va_list va, finfo_t Fi);
int my_put_nbrenoctalf(va_list va, finfo_t Fi);
int my_put_nbrunsignedf(va_list va, finfo_t Fi);
int my_put_floatf(va_list va, finfo_t Fi);
int my_put_nbr_hexaf(va_list va, finfo_t Fi);
int my_put_nbr_hexamajf(va_list va, finfo_t Fi);
int ptr_f(va_list ap, finfo_t Fi);
int my_put_scienf(va_list va, finfo_t Fi);
int my_put_float(double nb, int precision);
void printsign(int *i);
int my_put_floatautof(va_list va, finfo_t Fi);
int my_put_scien(float nb, int precision);
finfo_t structinit(char *str, int *i);
void structinitflags(char *str, int *i, finfo_t *Fi);
void structinitwidth(char *str, int *i, finfo_t *Fi);
void structinitprecision(char *str, int *i, finfo_t *Fi);
void structinitlength(char *str, int *i, finfo_t *Fi);

#endif
