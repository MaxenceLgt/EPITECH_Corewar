/*
** EPITECH PROJECT, 2023
** set_load_adress
** File description:
** set_load_adress
*/

#include "corewar_header.h"

void load_process(champ_t *champ, size_t pos)
{
    process_t *process = NULL;

    while (pos > MEM_SIZE) {
        pos -= MEM_SIZE;
        if (pos < MEM_SIZE)
            pos--;
    }
    process = champ->process->head->data;
    process->pos = pos;
    process->pc = pos;
}

static void load_champ(champ_t *champ, size_t start, unsigned char **vm)
{
    size_t parser = 0;

    load_process(champ, start);
    for (size_t i = start; i < MEM_SIZE && parser != champ->prog_size; i++,
    parser++, start++)
        (*vm)[i] = champ->champ_content[parser];
    if (parser == champ->prog_size)
        return;
    if (start >= MEM_SIZE && parser == 0)
        while (start > MEM_SIZE)
            start -= MEM_SIZE;
    if (start >= MEM_SIZE && parser != 0)
        start = 0;
    for (size_t i = start; parser != champ->prog_size; i++, parser++)
        (*vm)[i] = champ->champ_content[parser];
}

static int set_changing_start(vm_t *vm, size_t start)
{
    int offset = MEM_SIZE / vm->nb_champ;
    ml_node *temp = vm->champs_data->head;
    champ_t *champ = NULL;

    for (; temp; temp = temp->next)
        if ((champ = temp->data) && champ->load_address != 0) {
            load_champ(champ, start, &vm->vm);
            break;
        }
    temp = vm->champs_data->head;
    for (size_t i = start + offset; temp; temp = temp->next, i += offset) {
        champ = temp->data;
        if (champ->load_address != 0) {
            i -= offset;
            continue;
        }
        load_champ(champ, i, &vm->vm);
    }
    return (0);
}

int set_load_adress(vm_t *vm)
{
    int offset = MEM_SIZE / vm->nb_champ;
    ml_node *champ = vm->champs_data->head;
    champ_t *info = NULL;

    if (only_one_load(vm->champs_data))
        return (set_changing_start(vm, get_load(vm->champs_data)));
    for (size_t i = 0; champ; champ = champ->next, i += offset) {
        info = champ->data;
        if (info->load_address != 0)
            load_champ(info, info->load_address, &vm->vm);
        else
            load_champ(info, i, &vm->vm);
    }
    return (0);
}
