/*
** EPITECH PROJECT, 2023
** delivery [WSL: Ubuntu]
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

    void my_putchar(char c);
    void my_putstr(char *str);

    char **my_str_to_word_array(char const *str, char *separator);
    char *my_strcat(char *dest, char const *src);

    int my_strcmp(char const *s1, char const *s2);
    int my_strlen(char const *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_getnbr(char const *str);

    int my_env(char **env);
    char *my_strdup(char *str);

#endif /* !LIB_H_ */
