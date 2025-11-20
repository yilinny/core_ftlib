#include <stdlib.h>
#include "libft.h"
#include <limits.h>
#include <stdio.h>

int digits(int n)
{
    int digits;
    if (n < 0)
        n *= -1;
    digits = 0;
    while (n > 0)
    {
        digits += 1;
        n = n/10;
    }
    printf("%d", digits);
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
    if (n == INT_MIN)
        return(ft_strdup("-2147483648"));
    if (n == 0)
        return (ft_strdup("0"));
    if (n < 0)
    {
        final = (char *)malloc(length + 2);
        sign = 1;
    }
    else
        final = (char *)malloc(length + 1);
    
    if (final == NULL)
        return (NULL);
    if (sign == 1)
    {
        final[0] = '-';
        n = -n;
    }
    ctr = length + sign - 1;
    while (ctr >= sign)
    {
        final[ctr] = n % 10 + '0';
        n /= 10;
        ctr --;
    }
    final[length + sign] = '\0';
    return(final);
}