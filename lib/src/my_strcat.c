/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    if (str == NULL)
        return NULL;

    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        str[i] = src[j];
        i++;
        j++;
    }

    str[my_strlen(dest) + my_strlen(src)] = '\0';
    return str;
}
