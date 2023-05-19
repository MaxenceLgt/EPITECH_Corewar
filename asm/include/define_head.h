/*
** EPITECH PROJECT, 2023
** define_head
** File description:
** define_head
*/

#ifndef DEFINE_HEAD_
    #define DEFINE_HEAD_

    #define UNUSED __attribute__((__unused__))
    #define CHAR_IS(c, lst) ml_char_is_in_lst(c, lst) == true
    #define CHAR_IS_NUM(c) (c >= '0' && c <= '9')
    #define CHAR_IS_ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    #define CHAR_IS_ALNUM(c) (CHAR_IS_NUM(c) || CHAR_IS_ALPHA(c))
    #define CONST (const char **)
    #define DEBUG ml_printf("Je passe par ici\n")

#endif /* !DEFINE_HEAD_ */
