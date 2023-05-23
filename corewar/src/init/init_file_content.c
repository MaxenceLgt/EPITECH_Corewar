/*
** EPITECH PROJECT, 2023
** init_file_content
** File description:
** init_file_content
*/

#include <stdio.h>
#include "corewar_header.h"

void change_endians(void *data, size_t size)
{
    unsigned char *byte = (unsigned char *)data;
    size_t i = 0;
    unsigned char temp = 0;

    for (; i < size / 2; i++) {
        temp = byte[i];
        byte[i] = byte[size - i - 1];
        byte[size - i - 1] = temp;
    }
}

static int transfer_char_to_int(char *str)
{
    int res = 0;

    res |= str[0] << 4;
    return (res);
}

void get_file_info(UNUSED champ_t *node, char *file)
{
    FILE *fd = fopen(file, "r");
    fpos_t pos;
    char name[PROG_NAME_LENGTH] = "";
    char size[4] = "";

    fseek(fd, 4, SEEK_SET);
    fread(name, sizeof(char), PROG_NAME_LENGTH, fd);
    fseek(fd, 4, SEEK_CUR);
    fread(size, sizeof(int), 1, fd);
    change_endians(&size, sizeof(int));
}

void init_file_content(vm_t *vm)
{
    ml_node *temp = vm->champs_data->head;
    champ_t *node = NULL;

    for (; temp; temp = temp->next) {
        node = temp->data;
        get_file_info(node, node->file);
    }
}
