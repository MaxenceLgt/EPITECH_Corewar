/*
** EPITECH PROJECT, 2023
** indexes
** File description:
** indexes
*/

#ifndef INDEXES_
    #define INDEXES_

    typedef struct index_s {
        char *cmd;
        int pos_index[3];
        int nb_parameters;
    } index_t;

    extern index_t index_tab[];

#endif /* !INDEXES_ */
