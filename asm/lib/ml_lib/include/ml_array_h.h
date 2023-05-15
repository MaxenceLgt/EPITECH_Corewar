/*
** EPITECH PROJECT, 2023
** ml_array_h
** File description:
** ml_array_h
*/

#ifndef ML_ARRAY_H_
    #define ML_ARRAY_H_

    #include <sys/types.h>

    /**
     * @brief ml_count_array_size function count the number of string
     * that contain 'array'
     *
     * @param array: The array you want to count the size.
     * @return size of the array (size_t).
    */
    size_t ml_count_array_size(const char **array);

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

#endif /* !ML_ARRAY_H_ */
