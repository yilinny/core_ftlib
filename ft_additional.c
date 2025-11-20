#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *final;
    char *copy;
    copy = (char *)s;
    if (ft_strlen(copy) <= start)
        return(ft_strdup(""));
    final = (char *)malloc(len + 1);
    if (final == NULL)
        return (NULL);
    ft_strlcpy(final, copy + start, len + 1);
    return (final);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t i;
    char *final;
    size_t length;

    length = ft_strlen(s1) + ft_strlen(s2) + 1;
    final = (char *)calloc(length, 1);
    if (final == NULL)
        return (NULL);
    i = 0;
    ft_strlcat(final, s1, length);
    ft_strlcat(final, s2, length);
    return (final);
}

char *ft_strtrim(const char *s1, const char *set)
{
    char *final;
    int i;
    int j;
    i = 0;
    j = 0;
    final = (char *)malloc(ft_strlen(s1) + 1);

    while (s1[i])
    {
        if (ft_strchr(set, (int)s1[i]) == NULL)
        {
            final[j] = s1[i];
            j ++;
        }
        i++;
    }
    final[j] = '\0';
    return (final);
}

void free_split(char **array, int index)
{
    int j;
    j = 0;
    while (j < index)
    {
        free(array[j]);
        j++;
    }
    free(array);
}
char **ft_split(const char *s, char c)
{
    char **final;
    char *next;
    char *last;
    int count;
    int index;

    index = 0;
    count = 0;
    if (s[0] == '\0')
    {
        final = malloc(sizeof(char *));
        final[0] = NULL;
        return (final);
    }
    while (s[index])
    {
        if (count == 0 && s[index] != c)
            count ++;
        if (s[index] == c && s[index + 1] && s[index + 1] != c)
            count++;
        index++;
    }
    final = (char **)malloc((count + 1) * sizeof(char *));
    if (final == NULL)
        return (NULL);
    index = 0;
    last = (char *)s;

    while (index < count)
    {
        next = ft_strchr(last, c);
        while (next == last)
        {
            last = next + 1;
            next = ft_strchr(last, c);
        }
        if (next == NULL)
            next = ft_strlen(s) + (char *)s;
        final[index] = (char *)malloc(next - last + 1);
        if (final[index] == NULL)
        {
            free_split(final, index);
            return (NULL);
        }
        ft_strlcpy(final[index], last, next - last + 1);
        last = next + 1;
        index++;
    }

    final[count] = NULL;
    return (final);
}