/*
** EPITECH PROJECT, 2023
** define_head
** File description:
** define_head
*/

#ifndef DEFINE_HEAD_
    #define DEFINE_HEAD_

    #define CHAR_IS(c, lst) ml_char_is_in_lst(c, lst) == true
    #define CHAR_IS_ALNUM(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') \
|| (c >= 'A' && c <= 'Z'))
    #define PASS ml_printf("Je passe par ici\n")
    #define CONST (const char **)

#endif /* !DEFINE_HEAD_ */
