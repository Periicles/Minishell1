/*
** EPITECH PROJECT, 2022
** strlen
** File description:
** count_and_return
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }

    return (i);
}
