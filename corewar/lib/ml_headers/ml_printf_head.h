/*
** EPITECH PROJECT, 2023
** ml_printf_head
** File description:
** ml_printf_head
*/

#ifndef ml_PRINTF_HEAD_
    #define ml_PRINTF_HEAD_

    #include <unistd.h>

    /**
     * @brief ml_printf function displays a string with arguments
     * enter as parameter (%i, %s, %c, %%).
     *
     * @param str: The string to be displayed.
     * @param ...: Arguments to be displayed.
     * @return Number of bytes write.
    */
    size_t ml_printf(char const *str, ...);

#endif /* !ml_PRINTF_HEAD_ */
