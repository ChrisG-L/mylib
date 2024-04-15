/*
** EPITECH PROJECT, 2023
** B-CPE-200-NCE-2-1-amazed-christophe.gerardin [WSL: Debian]
** File description:
** Alloc Gestionaire
*/

#include "my.h"

void my_memcpy(void *dest, const void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (int i = 0; i < n; i++)
        cdest[i] = csrc[i];
}

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc((size + 1) * sizeof(ptr));

    if (new_ptr == NULL)
        return NULL;
    if (ptr == NULL)
        return new_ptr;
    my_memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}
