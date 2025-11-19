#include <stdlib.h>
#include "libft.h"

size_t ft_strlen(const char *s)
{
    size_t index;
    index = 0;
    while (s[index])
    {
        index++;
    }
    return (index);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t count;
    size_t index;
    index = 0;
    count = ft_strlen(src);

    if (size == 0)
        return (count);
    while (index < count && index < size - 1)
    {
        dst[index] = src[index];
        index++;
    }
    dst[index] = '\0';
    return (count);
}

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t d_size;
    size_t i;
    size_t j;
    d_size = ft_strlen(dest);
    if (d_size > size)
        return (size);
    i = d_size;
    j = 0;
    while (i < size - 1 && src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (d_size + ft_strlen(src));
}

char *ft_strchr(const char *s, int c)
{
    int index;
    index = 0;
    char *final;
    final = (char *)s;
    while (s[index] != '\0')
    {
        if (s[index] == c)
            return (final + index);
        index ++;
    }
    return(NULL);
}

char *ft_strrchr(const char *s, int c)
{
    int index;
    char *final;
    index = (int)ft_strlen(s);
    final = (char *)s;
    while (index >= 0)
    {
        if (s[index] == c)
            return(final + index);
        index --;
    }
    return (NULL);
}