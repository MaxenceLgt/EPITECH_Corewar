/*
** EPITECH PROJECT, 2023
** init_file_content
** File description:
** init_file_content
*/

#include <stdio.h>
#include "corewar_header.h"

static int transfer_char_to_int(char *str)
{
    int res = 0;

    res |= str[0];
    res |= str[1] << 8;
    res |= str[2] << 16;
    res |= str[3] << 24;
    return (res);
}

void get_header_info(champ_t *node, char *file)
{
    FILE *fd = fopen(file, "r");
    char name[PROG_NAME_LENGTH] = "";
    char size[4] = "";

    fseek(fd, 4, SEEK_SET);
    fread(name, sizeof(char), PROG_NAME_LENGTH, fd);
    node->name = ml_strdup(name);
    fseek(fd, 4, SEEK_CUR);
    fread(size, sizeof(int), 1, fd);
    change_endians(&size, sizeof(int));
    node->prog_size = (size_t)transfer_char_to_int(size);
    fclose(fd);
}

void init_file_content(vm_t *vm)
{
    ml_node *temp = vm->champs_data->head;
    champ_t *node = NULL;

    for (; temp; temp = temp->next) {
        node = temp->data;
        get_header_info(node, node->file);
    }
}
