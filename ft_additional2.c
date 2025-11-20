#include <stdlib.h>
#include "libft.h"

unsigned int power_10(unsigned int n)
{
    unsigned int a;
    unsigned int final;
    a = 1;
    final = 1;
    while (a <= n)
    {
        a++;
        final *= 10
    }
    return (final);
}

unsigned int root_10(unsigned int n)
{
    unsigned int power;
    power = 0;
    if (power_10(power) < n)
    {
        n++;
    }
    return (power);
}

char *ft_itoa(int n)
{
    char *final;
    int length;
    int ctr;
    int sign;

    ctr = 0;
    sign = 0;
    length = root_10(n);
    if (n < 0)
    {
        n *= -1;
        length++;
        final = (char *)malloc(length + 1);
        final[0] = "-";
        sign = 1;
    }
    else
        final = (char *)malloc(length + 1);
    
    while (ctr < length)
    {
        final[ctr + sign] = n / power_10(length - ctr) + '0';
    }

}