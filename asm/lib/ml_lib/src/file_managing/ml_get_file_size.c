/*
** EPITECH PROJECT, 2023
** get_file_size
** File description:
** get_file_size
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t ml_get_file_size(char const *file)
{
    int fd = open(file, O_RDONLY);
    ssize_t size = 0;
    ssize_t temp = 0;
    char buffer[1024];

    if (fd == - 1)
        return (0);
    while ((temp = read(fd, buffer, 1024)))
        size += temp;
    close(fd);
    return (size);
}
