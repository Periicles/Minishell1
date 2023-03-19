/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <stddef.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);

int my_flag(char const *format, va_list list, int i)
{
    if (format[i] == 'c') {
        my_putchar(va_arg(list, int));
    }
    if (format[i] == 's') {
        my_putstr(va_arg(list, char const *));
    }
    if (format[i] == 'i' || format[i] == 'd') {
        my_put_nbr(va_arg(list, int));
    }
    if (format[i] == '%') {
        my_putchar('%');
    }
    i += 1;
    return i;
}

int mini_printf(const char *format, ...)
{
    int i = 0;

    va_list list;
    va_start(list, format);

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i = my_flag(format, list, (i + 1));
        } else {
            my_putchar(format[i]);
            i += 1;
        }
    }
    va_end(list);
    return 0;
}
