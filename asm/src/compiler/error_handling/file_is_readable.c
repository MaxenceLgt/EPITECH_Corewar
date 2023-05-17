/*
** EPITECH PROJECT, 2023
** file_is_readable
** File description:
** file_is_readable
*/

#include <fcntl.h>
#include "asm_head.h"

bool file_is_readable(const char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return (false);
    close(fd);
    if (ml_get_file_size(file) == 0)
        return (false);
    return (true);
}
