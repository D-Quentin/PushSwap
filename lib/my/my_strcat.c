/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** kkjdk
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;

    j = 0;
    i = my_strlen(dest);
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}
