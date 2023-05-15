/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "display_pf_head.h"
#include "func_point_func_h.h"


static int exec_param_function(const char *str, va_list list, size_t *count,
size_t *parse)
{
    m_func tab_func[] = {{'d', display_int}, {'i', display_int},
    {'c', display_char}, {'s', display_str}, {'%', display_modulo}};

    for (size_t i = 0; i < 5; i++){
        if (str[(*parse) + 1] == tab_func[i].param){
            (*parse) += 2;
            return (tab_func[i].display(list, count));
        }
    }
    return (0);
}

size_t ml_printf(const char *str, ...)
{
    size_t parse = 0;
    size_t count = 0;
    va_list list;

    va_start(list, str);
    while (str[parse] != '\0'){
        if (str[parse] != '%'){
            display_char_pf(str[parse], &count);
            parse++;
            continue;
        }
        if (!exec_param_function(str, list, &count, &parse))
            return (-84);
    }
    va_end(list);
    return (count);
}
