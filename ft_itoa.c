#include <stdlib.h>
#include "libft.h"
#include <limits.h>

int power_10(int n)
{
    int a;
    int final;
    a = 1;
    final = 1;
    while (a <= n) // 10 ^11 will cause an int overflow
    {
        a++;
        if (a == 11)
            return(INT_MAX); //10 ^11 will cause overflow. In cases of this only used for comparison in root fn, no actual maths 
        final *= 10;
    }
    return (final);
}

int digits(int n)
{
    int digits;
    if (n < 0)
        n *= -1;
    digits = 0;
    if (power_10(digits) < n)
    {
        n++;
    }
    return (digits);
}

char *ft_itoa(int n)
{
    char *final;
    int length;
    int ctr;
    int sign;

    ctr = 0;
    sign = 0;
    length = digits(n);
    if (n < 0)
    {
        final = (char *)malloc(length + 2);
        sign = 1;
    }
    else
        final = (char *)malloc(length + 1);
    
    if (final == NULL)
    {
        free(final);
        return (NULL);
    }
    if (sign)
        final[0] = '-';
    
    while (ctr < length + sign)
    {
        final[ctr + sign] = n /(power_10(length + sign - ctr - 1)) + '0';
        ctr ++;
    }
    return(final);
}