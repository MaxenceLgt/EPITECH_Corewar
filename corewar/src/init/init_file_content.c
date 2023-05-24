/*
** EPITECH PROJECT, 2023
** init_file_content
** File description:
** init_file_content
*/

#include <stdio.h>
#include <stdlib.h>
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

static void get_file_content(champ_t *node, char *file)
{
    FILE *fd = fopen(file, "r");

    fseek(fd, sizeof(header_t), SEEK_SET);
    node->champ_content = malloc(sizeof(char) * (node->prog_size + 1));
    if (!node->champ_content) {
        fclose(fd);
        return;
    }
    fread(node->champ_content, sizeof(char), node->prog_size, fd);
    node->champ_content[node->prog_size] = '\0';
    fclose(fd);
}

void init_file_content(vm_t *vm)
{
    ml_node *temp = vm->champs_data->head;
    champ_t *node = NULL;

    if (vm->nb_champ < 2)
        return;
    for (; temp; temp = temp->next) {
        node = temp->data;
        get_header_info(node, node->file);
        get_file_content(node, node->file);
    }
}
