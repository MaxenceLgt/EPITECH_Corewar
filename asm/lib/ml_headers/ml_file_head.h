/*
** EPITECH PROJECT, 2023
** ml_file_head
** File description:
** ml_file_head
*/

#ifndef ML_FILE_HEAD_
    #define ML_FILE_HEAD_

    #include <sys/types.h>

    /**
     * @brief ml_get_file_size function get the size of a readable file.
     *
     * @param file File to get the size of
     * @return Size in bytes of the file (ssize_t).
     */
    ssize_t ml_get_file_size(char const *file);

#endif /* !ML_FILE_HEAD_ */
