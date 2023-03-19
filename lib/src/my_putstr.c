/*
** EPITECH PROJECT, 2022
** putstr
** File description:
** characters on strings
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
