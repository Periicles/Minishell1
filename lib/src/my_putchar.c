/*
** EPITECH PROJECT, 2022
** putchar
** File description:
** test
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
