/*
** EPITECH PROJECT, 2023
** func_point_func_h
** File description:
** func_point_func_h
*/

#ifndef FUNC_POINT_FUNC_H_
    #define FUNC_POINT_FUNC_H_

    #include <stdlib.h>
    #include <stdarg.h>
    #include "func_point_struct.h"

    /*
    @brief display_char is a function that get the char
    argument from va_list list,call the function to display
    it and add to count the number of char displayed.
    @param list: list containing argument to display.
    @param count: counter you want to increment.
    @return display_char return 1 to say that the program is
    passed by this function.
    */
    int display_char(va_list list, size_t *count);

    /*
    @brief display_modulo is a function that call the function
    to display a % character and add to count the number of char
    displayed.
    @param list: list containing argument to display.
    @param count: counter you want to increment.
    @return display_modulo return 1 to say that the program is
    passed by this function.
    */
    int display_modulo(va_list list, size_t *count);

    /*
    @brief display_int is a function that get the int argument from
    va_list list, call the function to display it and add to
    count the number of digit displayed.
    @param list: list containing argument to display.
    @param count: counter you want to increment.
    @return display_int return 1 to say that the program is
    passed by this function.
    */
    int display_int(va_list list, size_t *count);

    /*
    @brief display_str is a function that get the char* argument
    from va_list list, call the function to display it and add
    to count the number of character displayed.
    @param list: list containing argument to display.
    @param count: counter you want to increment.
    @return display_str return 1 to say that the program is
    passed by this function.
    */
    int display_str(va_list list, size_t *count);

#endif /* !FUNC_POINT_FUNC_H_ */
