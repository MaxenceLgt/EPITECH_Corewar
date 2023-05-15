/*
** EPITECH PROJECT, 2023
** display_pf_head
** File description:
** display_pf_head
*/

#ifndef DISPLAY_PF_HEAD_
    #define DISPLAY_PF_HEAD_

    #include <unistd.h>

    /*
    @brief strlen_pf is a function that count the lenght of a string.
    @param str: The string you want to know the length.
    @return The length of the string enter as parameter.
    */
    size_t strlen_pf(char const *str);

    /*
    @brief display_str_pf is a function that display into the standard output
    the content of the string enter as parameter and add to count the number of
    displayed characters.
    @param str: The string you want to display.
    @param count: The counter incremented for every character displayed.
    @return Nothing.
    */
    void display_str_pf(char const *str, size_t *counter);

    /*
    @brief display_char_pf is a function that display into the standard output
    a single character enter as parameter and add to count the number of
    displayed characters.
    @param char: The character you want to display.
    @param count: The counter incremented for every character displayed.
    @return Nothing.
    */
    void display_char_pf(const char c, size_t *counter);

    /*
    @brief display_int_pf is a function that display into the standard output
    an integer enter as parameter and add to count the number of
    displayed digit.
    @param char: The integer you want to display.
    @param count: The counter incremented for every digit displayed.
    @return Nothing.
    */
    int display_int_pf(int nb, size_t *counter);

#endif /* !DISPLAY_PF_HEAD_ */
