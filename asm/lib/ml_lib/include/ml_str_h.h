/*
** EPITECH PROJECT, 2023
** ml_str_h
** File description:
** ml_str_h
*/

#ifndef ml_STR_H_
    #define ml_STR_H_


    #include <stdbool.h>
    #include <sys/types.h>

    /**
     * @brief Verify if 'c' is alpha or num character.
     * @param c: Char to verify.
     * @return True if it is. False otherwise (bool).
    */
    bool ml_char_isalphanum(const char c);

    /**
     * @brief Verify if 'c' is num character.
     *
     * @param c: Char to verify.
     * @return True if it is. False otherwise (bool).
    */
    bool ml_char_isnum(const char c);

    /**
     * @brief Verify if 'c' is alpha character.
     *
     * @param c: Char to verify.
     * @return True if it is. False otherwise (bool).
    */
    bool ml_char_isalpha(const char c);

    /**
     * @brief Verify if 'c' is upcase alpha character.
     *
     * @param c: Char to verify.
     * @return True if it is. False otherwise (bool).
    */
    bool ml_char_isup(const char c);

    /**
     * @brief Verify if 'c' is lowcase alpha character.
     *
     * @param c: Char to verify.
     * @return True if it is. False otherwise (bool).
    */
    bool ml_char_islow(const char c);

    /**
     * @brief ml_strlen function get the length of 'str'.
     *
     * @param str: String to get length from.
     * @return Length in bytes of 'str'. (size_t)
    */
    size_t ml_strlen(char const *str);

    /**
     * @brief ml_strcmp compare 's1' and 's2' strings.
     *
     * @param s1: First string to compare.
     * @param s2: Second string to compare.
     * @return Integer less than, equal to, or greater than zero if s1 is
     * found, respectively, to be less than, to match, or be greater than
     * s2. (int)
    */
    int ml_strcmp(char const *s1, char const *s2);

    /**
     * @brief ml_strncmp compare the first 'n' bytes of
     * 's1' and 's2' strings.
     *
     * @param s1: First string to compare.
     * @param s2: Second string to compare.
     * @param n: Number of bytes to compare.
     * @return Integer less than, equal to, or greater than zero if
     * s1 (or the first n bytes) is found, respectively, to be less than,
     * to match, or be greater than s2. (int).
    */
    int ml_strncmp(char const *s1, char const *s2, size_t n);

    /**
     * @brief ml_putstr function display 'str' content in standar
     * output.
     *
     * @param str: String to display.
     * @return Nothing.
    */
    void ml_putstr(char const *str);

    /**
     * @brief ml_putstr_error function display 'str' content in standar error
     * output.
     *
     * @param str: String to display.
     * @return Nothing.
    */
    void ml_putstr_error(char const *str);

    /**
     * @brief ml_putchar function display 'c' into standar output.
     *
     * @param c: Character to display.
     * @return Nothing.
    */
    void ml_putchar(char const c);

    /**
     * @brief ml_strcat function concatenate the content of 'src' into
     * 'dest' string considering that 'dest' has enough space allocated
     * to get 'src' content.
     *
     * @param dest: Pointer to the string to be concatenated.
     * @param src: The string you want to add to dest.
     * @returns Nothing.
    */
    void ml_strcat(char **dest, char const *src);

    /**
     * @brief ml_strcpy function copy the content of 'src' into
     * 'dest' string considering that 'dest' has enough space allocated
     * to copy 'src'.
     *
     * @param dest: Pointer to the destination string.
     * @param src: String to be copied.
     * @returns Nothing.
    */
    void ml_strcpy(char **dest, char const *src);

    /**
     * @brief ml_char_is_in_lst function verify if 'c' char is present
     * in 'lst' string.
     *
     * @param c: Character to find.
     * @param lst: List of char to verify.
     * @returns return true if 'c' is in 'lst'. False otherwise. (bool)
    */
    bool ml_char_is_in_lst(const char c, const char *lst);

    /**
     * @brief ml_strndup function duplicate the first 'n' bytes of 'src'
     * into a new string.
     *
     * @param src: The string to be duplicated.
     * @param size: Number of bytes to duplicate.
     * @return New string that is a duplication of 'n' bytes of 'src' (char *).
     * NULL in case of error.
    */
    char *ml_strndup(char const *src, size_t size);

    /**
     * @brief ml_strdup function duplicate 'string' into a new one
     * and return it.
     *
     * @param str: String to be duplicated.
     * @return New string that is a duplication of 'src' (char *).
     * NULL in case of error.
    */
    char *ml_strdup(char const *src);

    /**
     * @brief ml_revstr function reverse 'str' string content.
     *
     * @param str: Pointer to the string to reverse.
     * @return Nothing.
    */
    void ml_revstr(char **str);

#endif /* !ml_STR_H_ */
