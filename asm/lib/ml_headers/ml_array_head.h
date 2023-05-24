/*
** EPITECH PROJECT, 2023
** ml_array_head
** File description:
** ml_array_head
*/

#ifndef ML_ARRAY_HEAD_
    #define ML_ARRAY_HEAD_


    #include <sys/types.h>

    /**
     * @brief The ml_print_str_array function display the content of
     * an array of strings in the standard output.
     *
     * @param tab: The string array to be displayed.
     * @return Nothing.
    */
    void ml_display_str_array(char **tab);

    /**
     * @brief ml_add_str_to_array function add a string into a string
     * array "array" by destroying the array enter in parameter and returning a
     * new one with the copy of the previous one and the string inside.
     *
     * @param array: The string array that will stock the string.
     * @param str: the string to add.
     * @return New array containing the string (char **).
     * NULL in case of error.
    */
    char **ml_add_str_to_array(char **array, const char *str);

    /**
     * @brief ml_copy_array function copies the content of a string array
     * `array_src` into another string array `array_dest` considering that
     * 'array_dest' haves enough space allocated to get the content.
     *
     * @param array_dest: The array that will get the 'array_src' content.
     * @param array_src: The array to be copied.
     * @return 'array_dest' with the content of 'array_src' in it (char **).
     * NULL in case of error.
    */
    char **ml_copy_array(char **array_dest, const char **array_src);

    /**
     * @brief ml_count_array_size function count the number of string
     * that contain 'array'
     *
     * @param array: The array you want to count the size.
     * @return size of the array (size_t).
    */
    size_t ml_count_array_size(const char **array);

    /**
     * @brief ml_create_str_array function create a new allocated array
     * filled of NULL strings;
     *
     * @param size: the number of string you want to allocate
     * @return an array allocated with the number of string 'size' (char**)
     * NULL in case of error.
    */
    char **ml_create_str_array(size_t size);

    /**
     * @brief ml_destroy_str_array function free the content of a string array
     * 'array' and the array itself.
     *
     * @param array The array you want to destroy.
     * @return Nothing.
    */
    void ml_destroy_str_array(char **array);

    /**
     * @brief ml_dup_array is a function that duplicate a string array 'array'
     * and it's content and return it.
     *
     * @param array The array you want to duplicate.
     * @return A new allocated array that is the same as 'array' (char**).
     * NULL in case of error.
    */
    char **ml_dup_array(const char **array);

    /**
     * @brief ml_str_tok function separate 'string' into an array of strings
     * with for separator a string 'token' containing all the separators.
     *
     * @param str The string you want to split.
     * @param token The list of token spliters.
     * @return An array containing all the splited strings (char**).
     * NULL in case of error.
    */
    char **ml_str_tok(char const *str, char const *token);

#endif /* !ML_ARRAY_HEAD_ */
