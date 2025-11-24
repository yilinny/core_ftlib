#include "libft.h"
#include "stdlib.h"

t_list *ft_lstnew(void *content)
{
    t_list *final;
    final = (t_list *)malloc(sizeof(t_list *));
    if (!final)
        return (NULL);
    final -> content = content;
    final -> next = NULL;
    return (final);
}

void ft_lstadd_front (t_list **lst, t_list *new)
{
    if (!lst ||new)
        return (NULL);
    new->next = *lst;
    *lst = new;
}

int ft_lstsize (t_list *lst)
{
    int count;
    count = 0;

    while(lst)
    {
        count ++;
        lst = lst-> next;
    }
    return (count);
}

t_list *ft_lstlast(t_list *lst)
{
    t_list *final;

    final = lst;
    while(final && final-> next != NULL)
    {
        final = final-> next;
    }
    return (final);
}