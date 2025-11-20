#include <unistd.h>
#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putstr_fd (char *s, int fd)
{
    if (!s)
        return;
    write (fd, s, ft_strlen(s));
}

void ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return;
    write (fd, s, ft_strlen(s));
    write (fd, "\n", 1);
}

void ft_putnbr_fd(int n, int fd)
{
    char c;
    long num;
    num = n;

    if (num < 0)
    {
        num = -num;
        write (fd, "-", 1);
    }
    if (num >= 10)
        ft_putnbr_fd(num/10, fd);
    c = num % 10 + '0';
    write (fd, &c, 1);
}

