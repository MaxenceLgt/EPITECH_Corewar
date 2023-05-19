/*
** EPITECH PROJECT, 2023
** get_file_content
** File description:
** get_file_content
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
ssize_t ml_get_file_size(char const *file);

char *ml_get_file_content(char const *file)
{
    int fd = open(file, O_RDONLY);
    ssize_t size_file = ml_get_file_size(file);
    char *buffer = malloc(sizeof(char) * (size_file + 1));

    if (fd < 0 || !buffer)
        return NULL;
    read(fd, buffer, size_file);
    buffer[size_file] = '\0';
    close(fd);
    return (buffer);
}
