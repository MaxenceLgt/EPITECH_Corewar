/*
** EPITECH PROJECT, 2023
** ml_int_head
** File description:
** ml_int_head
*/

#ifndef ml_INT_HEAD_
    #define ml_INT_HEAD_

    #include <unistd.h>

    /**
     * @brief ml_sort_int_array function sort
     * an array of int 'tab' in ascending order.
     *
     * @param tab: Pointer to int array to be sorted.
     * @param size: Size of int array.
     * @return Nothing.
    */
    void ml_sort_int_array(int **tab, size_t size);

    /**
     * @brief ml_get_nbrlen function get the size in char bytes
     * of 'nbr'.
     *
     * @param nbr: Int to get the lenght.
     * @return Length of 'nbr'.
    */
    size_t ml_get_nbrlen(int nbr);

    /**
     * @brief ml_atoi function get an int from 'str'.
     * The function doesn't verify if there is an error or no number
     * and return 0 in this case.
     *
     * @param str: String you want to get int from.
     * @return Int get from the string (int).
    */
    int ml_atoi(const char *str);

    /**
     * @brief ml_atof function get a double from 'str'.
     * The function doesn't verify if there is an error or no number
     * and return 0 in this case.
     *
     * @param str: String you want to get double from.
     * @return Double get from the string (double).
    */
    double ml_atof(const char *str);

    char *ml_itoa(int nb);

#endif /* !ml_INT_HEAD_ */
