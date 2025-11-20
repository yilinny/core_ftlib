#include <stdlib.h>
#include <stdint.h>

void *ft_memchr(const char *s, int c, size_t n)
{
    size_t index;
    index = 0;
    unsigned char *final;
    final = (unsigned char *)s;
    while (index < n)
    {
        if ((unsigned char)s[index] == (unsigned char)c)
            return ((void *)(final + index));
        index++;
    }
    return (NULL);
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t index;
    unsigned char *s_one;
    unsigned char *s_two;

    index = 0;
    s_one = (unsigned char *)s1;
    s_two = (unsigned char *)s2;
    while (index < n)
    {
        if (s_one[index] != s_two[index])
            return (s_one[index] - s_two[index]);
        index++;
    }
    return (0);
}

int ft_atoi(const char *s)
{
    int final;
    int sign;
    char *str;

    final = 0;
    sign = 1;
    str = (char *)s;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
    {
        str++;
    }
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        final = (final * 10) + (*str - '0');
        str++;
    }
    return (final * sign);
}

void *ft_calloc(size_t n, size_t esize)
{
    unsigned char *final;
    size_t i;

    if (n == 0 || esize == 0)
        return (malloc(1));
    if (n > SIZE_MAX / esize)
        return (NULL);
    i = 0;
    final = malloc(n * esize);
    if (final == NULL)
        return (final);
    while (i < n * esize)
    {
        final[i] = 0;
        i++;
    }
    return ((void *) final);
}

char *ft_strdup(const char *s)
{
    char *final;
    size_t length;

    length = ft_strlen(s);
    final = (char *)malloc((length + 1) * sizeof(char));
    if (final == NULL)
        return (NULL);
    ft_strlcpy(final, s, length + 1);
    return (final);
}