/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr
*/

int is_neg(char const *str, int i)
{
    (void)i;
    int j = 0;
    int isneg = 0;
    while ((str[j] != '\0')) {
        if (str[j] == '-')
            isneg += 1;

        j = j + 1;
    }
    return isneg % 2 == 0 ? 1 : -1;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int result = 0;
    int sym = 1;

    while (str[i] != '\0' && (str[i] < '0' && str[i] > '9')) {
        i += 1;
    }
    sym = is_neg(str, (i - 1));

    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') {
        result = result * 10 + str[i] - '0';
        if ((sym == 1 && result > 2147483647)
        || (sym == -1 && result > 2147483648))
            return 0;
        i += 1;
    }
    return result * sym;
}
