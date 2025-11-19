#include <stddef.h>
#include "libft.h"
#include <stdio.h>

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    i = 0;
    unsigned char *p;
    p = (unsigned char *)s;
    while (i < n)
    {
        p[i] = (unsigned char)c;
        i ++;
    }
    return (s);
}

void ft_bzero(void *s, size_t n)
{
    unsigned char *p;
    size_t i;
    i = 0;
    p = (unsigned char *)s;
    while (i < n)
    {
        p[i] = '\0';
        i++;
    }
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *d;
    unsigned char *s;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *d;
    unsigned char *s;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (dest < src)
    {
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else if (dest > src)
    {
        i = n - 1;
        while (i > 0)
        {
            d[i] = s[i];
            i--;
        }
        d[i] = s[i];
    }
    return (dest);
}