/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int check_char(char *separator, char c);

int len_word(char const *str, int index, char *separator)
{
    int len = 0;

    for (int i = index; check_char(separator, str[i]) == 0 &&
    str[i] != '\0'; i += 1) {
        len += 1;
    }
    return len;
}

int nb_word(char const *str, int index, char *separator)
{
    int nb = 0;
    if (str == NULL)
        return 0;
    while (str[index] != '\0' && str[index] != '\n') {
        if (check_char(separator, str[index]) == 0 &&
        (check_char(separator, str[index + 1]) == 1 ||
        str[index + 1] == '\0')) {
            nb += 1;
        }
        index += 1;
    }
    return nb;
}

int find_index(char const *str, int index, char *separator)
{
    for (int i = index; str[i] != '\0'; i += 1) {
        if (check_char(separator, str[i]) == 1 &&
        check_char(separator, str[i + 1]) == 0)
            return i + 1;
    }
    return 0;
}

int init_index(char const *str, int index, char *separator)
{
    if (str == NULL)
        return 0;
    if (check_char(separator, str[0]) == 0) {
        index = 0;
    } else {
        index = find_index(str, 0, separator);
    }
    return index;
}

char **my_str_to_word_array(char const *str, char *separator)
{
    int index = 0;
    index = init_index(str, index, separator);
    int nb_w = nb_word(str, index, separator);
    if (str == NULL) return NULL;
    char **array = malloc(sizeof(char *) * (nb_w + 1));
    if (array == NULL || nb_w == 0)
        return NULL;
    for (int i = 0, index_prev = 0; i < nb_w; i += 1) {
        int len_w = len_word(str, index, separator);
        index_prev = index;
        array[i] = malloc(sizeof(char) * (len_w + 1));
        for (int j = 0; j < len_w; j += 1) {
            array[i][j] = str[index_prev];
            index_prev += 1;
        }
        array[i][len_w] = '\0';
        index = find_index(str, (index + 1), separator);
    }
    array[nb_w] = NULL;
    return array;
}
