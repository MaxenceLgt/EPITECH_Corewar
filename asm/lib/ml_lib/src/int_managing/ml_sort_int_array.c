/*
** EPITECH PROJECT, 2022
** ml_sort_int_array
** File description:
** ml_sort_int_array
*/

#include <unistd.h>

static size_t find_the_lowest(int *tab, size_t size)
{
    int value = tab[0];
    size_t pos = 0;

    for (size_t i = 0; i < size; i++){
        if (tab[i] < value) {
            value = tab[i];
            pos = i;
        }
    }
    return (pos);
}

void ml_sort_int_array(int **tab, size_t size)
{
    size_t pos = 0;
    int temp = 0;

    for (size_t i = 0; i < size; i++){
        pos = find_the_lowest(&(*tab)[i], size - i);
        if (i != pos + i){
            temp = (*tab)[pos + i];
            (*tab)[pos + i] = (*tab)[i];
            (*tab)[i] = temp;
        }
    }
}
