#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *c);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dest, const char *src, size_t size);
int ft_toupper (int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp (const char *s1, const char *s2, size_t n);
void *ft_memchr (const void *s, int c, size_t n);
int ft_memcmp (const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *big, const char *small, size_t len);
int ft_atoi (const char *s);


// list of commands
/*
 * isalpha - checks for an alphabetic character
 • isdigit - checks for a digit
 • isalnum - check if it is alphabetical or digit
 • isascii - checks whether c is a 7-bit unsigned char value that fits into the ASCII character set
 // values return non-zero if true, returns zro if false
 • isprint - checks if it is a printable chracter
 • strlen - calculate the len of string pointed to by string, exclues the terminating byte
 • memset - fill first n bytes of memory area pointed to by s with constant byte c
 • bzero - erases the data in the first n bytes of the mrmory pointed to by s by writing \0 to the area
 • memcpy - copies n bytes from src to dest. the memory areas must not overlap. memmove should be used instead if the areas overlap. -- the function itself does not check for overlap. it does not pad with '\0', and it does not check if n > src, if it is, it copies rubbish in the memory
 • memmove - copies n bytes from src to dest. however src and dest may overlap, behaves AS THOUGH it copies from src to a temp buffer, then copies into dst. however using a temp buffer is memory inefficient.
 • strlcpy - copies up to size - 1 characters from src to dst, and nul terminates the result. length of string they tried to create - ie. src.
 • strlcat - appends src to end of dst. appends at most size - dst - 1 (ie size includes length of dst), nul terminating the result. however if dst > n, the string returned would not be nul terminating, and the output would be size. Else, output would be dst + src
 • toupper - returns upper case, or returns back the same character if it is not possible 
 • tolower
 • strchr- returns a pointer to the byte where c first occurs in a string, otherwise, returns null pointer 
 • strrchr - returns a pointer to the byte where character c last occurs in a string. returns null pointer if not found
 • strncmp - compares byte by byte. returns difference in the first pair of byte that differes. **comparison need to be done with unsigned char (accoutns for ascii > 128)
 • memchr scans first n bytes of memory space for first instance of c. comparison done with unsigned char (allows for byte by byte)
 • memcmp - similar to strncmp, hwoever compares byte by byte and in a memory area vs string 
 • strnstr - looks for small string in big string, where not more than len characters are searched. Characters that appear ater a '\0' are not searched. Pointer to the first occurance of small is returned. if little is nothing, big is returned. if small not in big, a null pointer is returned. 
 • atoi - converts string to integer. skips leading whitespace, has negative sign parses digi until the first non digit character, undefined on overflow 
 */
#endif