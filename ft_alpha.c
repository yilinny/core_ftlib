#include "libft.h"

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return(c - 32);
    return (c);
}

int ft_tolower(int c)
{
    if (c>= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int ft_strncmp (const char *s1, const char *s2, size_t n)
{
    size_t index;
    index = 0;
    unsigned char a;
    unsigned char b;
    while (index < n)
    {
        a = (unsigned char)s1[index];
        b = (unsigned char)s2[index];
        if (a != b)
            return (a - b);
        if (a == '\0')
            return (0);
        index ++;
    }
    return (0);
}

char *ft_strnstr(const char *big, const char *small, size_t len)
{
    char *final;
    size_t index;
    size_t small_index;

    final = (char *)big;

    index = 0;
    if (small[0] == '\0')
        return(final);

    while (big[index] && index < len)
    {
        small_index = 0;
        while (big[index + small_index] == small[small_index] && index + small_index < len)
        {
            small_index ++;
            if (small[small_index] == '\0')
                return (final + index);
        }
        index ++;
    }
    return (NULL);
}