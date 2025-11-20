#include "libft.h";
#include <stdlib.h>

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *final;
    final = (char *)malloc(len + 1);
    if (final == NULL)
        return (NULL);
    ft_strlcpy(final, s, len);
    return (final);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    char *final;
    final = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (final == NULL)
        return (NULL);
    i = 0;

    while (i < ft_strlen(s1))
    {
        final[i] = s1[i];
        i++;
    }
    ft_strlcat(final, s2, ft_strlen(s2) + 1);
    return (final);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *final;
    int i;
    i = 0;
    final = (char *)malloc(ft_strlen(s1) + 1);

    while (s1[i])
    {
        if (ft_strchr(set, (int)s1[i]) == NULL)
            final[i] = s1[i];
        i++;
    }
    final[i] = '\0';
    return (s1);
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
    count = 1;
    while (s[index])
    {
        if (s[index] == c)
            count++;
        index++;
    }
    final = (char **)malloc((count + 1) * sizeof(char *));
    if (final == NULL)
        return (NULL);
    index = 0;
    last = (char *)s;
    while (index < count - 1)
    {
        next = ft_strchr(last, c);
        if (next == NULL)
            next = ft_strlen(s) + (char *)s;
        final[index] = (char *)malloc(next - last + 1);
        if (final[index] == NULL)
        {
            free_split(final, index);
            return (NULL);
        }
        ft_strlcpy(final[index], last, next - last - 1);
        last = next + 1;
        index++;
    }
    final[index] = NULL;
    return (final);
}