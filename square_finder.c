/*
** EPITECH PROJECT, 2023
** Bs setting up
** File description:
** bs su
*/

#include "my.h"

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    struct stat file = returnfile(filepath);
    char *buffer = load_file_in_mem(filepath);
    char **arr = mem_alloc_2d_array(nb_rows + 1, nb_cols + 1);
    int size = file.st_size;
    int bufferpos = 0;
    int linelen = 0;

    for (int y = 0; y <= nb_rows; y += 1) {
        linelen = mylenoflignbuffer(buffer + bufferpos);
        linelen = linelen > nb_cols ? nb_cols : linelen;
        for (int i = 0; i <= linelen; i += 1) {
            arr[y][i] = buffer[bufferpos];
            bufferpos += 1;
        }
    }
    return arr;
}

void helpersquaresize(char **map, int *coord, int i, int *valid)
{
    for (int j = coord[0]; j < coord[2]; j += 1) {
        if (map[i][j] != '.') {
            *valid = 0;
            return;
        }
    }
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int valid = 1;
    int limit1 = row + square_size;
    int limit2 = col + square_size;
    int coord[3] = {col, row, limit2};

    for (int i = row; i < limit1; i += 1) {
        helpersquaresize(map, coord, i, &valid);
        if (valid == 0) {
            return 0;
        }
    }
    return valid;
}

void helperbiggest(char **map, int i, int j, square_t *biggest)
{
    while (is_square_of_size(map, i, j, biggest->tempsize)) {
        if (biggest->tempsize > biggest->size) {
            biggest->size = biggest->tempsize;
            biggest->row = i;
            biggest->col = j;
        }
        biggest->tempsize += 1;
    }
}

square_t *find_biggest_square(char **map, int nb_rows, int nb_cols)
{
    square_t *biggest = malloc(sizeof(square_t));

    biggest->size = 0;
    biggest->row = 0;
    biggest->col = 0;
    for (int i = 0; i < nb_rows; i += 1) {
        for (int j = 0; j < nb_cols; j += 1) {
            biggest->tempsize = 1;
            helperbiggest(map, i, j, biggest);
        }
    }
    return biggest;
}
