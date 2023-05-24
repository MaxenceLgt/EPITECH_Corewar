/*
** EPITECH PROJECT, 2023
** ml_lib
** File description:
** macros header file
*/

#ifndef ML_MACROS_H
    #define ML_MACROS_H

    #define IS_UPR(c) ((c) >= 'A' && (c) <= 'Z')
    #define IS_LWR(c) ((c) >= 'a' && (c) <= 'z')
    #define IS_ALPHA(c) (IS_UPR(c) || IS_LWR(c))
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')
    #define IS_ALNUM(c) (IS_ALPHA(c) || IS_NUM(c))
    #define IS_ASCII(c) ((c) >= 0 && (c) <= 127)
    #define IS_PRINTABLE(c) ((c) >= 32 && (c) <= 126)
    #define IS_SIGN(c) ((c) == '+' || (c) == '-')

#endif /* !ML_MACROS_H */
