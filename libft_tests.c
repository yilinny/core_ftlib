#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Helper function for string comparison
void assert_str(const char *test_name, const char *output, const char *expected)
{
    if (strcmp(output, expected) == 0)
    {
        printf("%s: %sTest passed%s\n", test_name, GREEN, RESET);
    }
    else
    {
        printf("%s: %sFAIL%s, got '%s', expected '%s'\n", test_name, RED, RESET, output, expected);
    }
}

void assert_int(const char *test_name, int output, int expected)
{
    if (output == expected)
    {
        printf("%s: %sTest passed%s\n", test_name, GREEN, RESET);
    }
    else
    {
        printf("%s: %sFAIL%s, got %d, expected %d\n", test_name, RED, RESET, output, expected);
    }
}

void assert_size_t(const char *test_name, size_t output, size_t expected)
{
    if (output == expected)
    {
        printf("%s: %sTest passed%s\n", test_name, GREEN, RESET);
    }
    else
    {
        printf("%s: %sFAIL%s, got %zu, expected %zu\n", test_name, RED, RESET, output, expected);
    }
}

void check_null_ptr(void *ptr)
{
    if (ptr == NULL)
    {
        printf("%sTest passed: NULL correct%s\n", GREEN, RESET);
    }
    else
    {
        printf("%sFAIL: NULL expected, but got a non-NULL pointer%p%s\n", RED, ptr, RESET);
    }
}

// -------------------- Tests --------------------

void test_isalpha()
{
    assert_int("isalpha('a')", ft_isalpha('a'), 1);
    assert_int("isalpha('Z')", ft_isalpha('Z'), 1);
    assert_int("isalpha('1')", ft_isalpha('1'), 0);
    assert_int("isalpha('@')", ft_isalpha('@'), 0);
}

void test_isdigit()
{
    assert_int("isdigit('0')", ft_isdigit('0'), 1);
    assert_int("isdigit('9')", ft_isdigit('9'), 1);
    assert_int("isdigit('a')", ft_isdigit('a'), 0);
}

void test_isalnum()
{
    assert_int("isalnum('a')", ft_isalnum('a'), 1);
    assert_int("isalnum('9')", ft_isalnum('9'), 1);
    assert_int("isalnum('@')", ft_isalnum('@'), 0);
}

void test_isascii()
{
    assert_int("isascii(0)", ft_isascii(0), 1);
    assert_int("isascii(127)", ft_isascii(127), 1);
    assert_int("isascii(128)", ft_isascii(128), 0);
}

void test_isprint()
{
    assert_int("isprint(' ')", ft_isprint(' '), 1);
    assert_int("isprint('A')", ft_isprint('A'), 1);
    assert_int("isprint('\\n')", ft_isprint('\n'), 0);
}

void test_strlen()
{
    assert_size_t("strlen('Hello')", ft_strlen("Hello"), 5);
    assert_size_t("strlen('')", ft_strlen(""), 0);
    assert_size_t("strlen('Long string')", ft_strlen("Long string"), 11);
}

void test_memset()
{
    char buf[6] = "Hello";
    ft_memset(buf, 'A', 3);
    buf[5] = '\0';
    assert_str("memset test", buf, "AAAlo");
}

void test_bzero()
{
    char buf[6] = "Hello";
    ft_bzero(buf, 3);
    if (buf[0] == 0 && buf[1] == 0 && buf[2] == 0)
    {
        printf("bzero test: %sTest passed%s\n", GREEN, RESET);
    }
    else
    {
        printf("bzero test: %sFAIL%s\n", RED, RESET);
    }
}

void test_memcpy()
{
    char src[] = "Hello";
    char dest[6];
    ft_memcpy(dest, src, 5);
    dest[5] = '\0';
    assert_str("memcpy test", dest, "Hello");
}

void test_memmove()
{
    char buf[10] = "abcdef";
    ft_memmove(buf + 2, buf, 4); // overlapping
    char ori_buf[10] = "abcdef";
    memmove(ori_buf + 2, ori_buf, 4);
    buf[6] = '\0';
    ori_buf[6] = '\0';
    assert_str("memmove test", buf, ori_buf);
}

void test_strlcpy()
{
    char dest[6];
    size_t ret = ft_strlcpy(dest, "HelloWorld", sizeof(dest));
    assert_str("strlcpy content", dest, "Hello");
    assert_size_t("strlcpy return", ret, 10);
}

void test_strlcat()
{
    char dest[20] = "Hello";
    size_t ret = ft_strlcat(dest, "banana", sizeof(dest));
    assert_str("strlcat content", dest, "Hellobanana");
    assert_size_t("strlcat return", ret, 11);
}

void test_tolower()
{
    char test1 = 'a';
    char test2 = '2';
    char test3 = 'Z';

    assert_int("to_lower test", ft_tolower(test1), 'a');
    assert_int("to_lower test", ft_tolower(test2), '2');
    assert_int("to_lower test", ft_tolower(test3), 'z');

}
void test_toupper()
{
    char test1 = 'a';
    char test2 = '2';
    char test3 = 'Z';

    assert_int("to_upper test", ft_toupper(test1), 'A');
    assert_int("to_upper test", ft_toupper(test2), '2');
    assert_int("to_upper test", ft_toupper(test3), 'Z');

}

void test_ftstrchr()
{
    char *ft_one = ft_strchr("aaaaaa", 'b');;
    if (ft_one == NULL)
    {
       printf("Character not found\n");
    }
    else
    {
        printf("Test one failed. Output: %s\n", ft_one);
    }
    char *ft_two = ft_strchr("abbbbdhfcje", 'b');
    char *ori_two= strchr("abbbbdhfcje", 'b');
    char *ft_three = ft_strchr("gw242v@", '@');
    char *ori_three = strchr("gw242v@", '@');

    assert_str("test ftstrchr", ft_two, ori_two);
    assert_str("test ftstrchr", ft_three, ori_three);
}


void test_ftstrrchr()
{
    char *ft_one = ft_strrchr("aaaaaa", 'b');;
    if (ft_one == NULL)
    {
       printf("Character not found\n");
    }
    else
    {
        printf("Test one failed. Output: %s\n", ft_one);
    }
    char *ft_two = ft_strrchr("abbbbdhfcje", 'b');
    char *ori_two= strrchr("abbbbdhfcje", 'b');
    char *ft_three = ft_strrchr("gw242v@", '@');
    char *ori_three = strrchr("gw242v@", '@');
    char *ft_four = ft_strrchr("gw242v@", '\0');
    char *ori_four = strrchr("gw242v@", '\0');

    assert_str("test ftstrrchr", ft_two, ori_two);
    assert_str("test ftstrrchr", ft_three, ori_three);
    assert_str("test ftstrrchr", ft_four, ori_four);

}

void test_memchr()
{
    void *ft1 = ft_memchr("abcdef", 'd', 6);
    void *ori1 = memchr("abcdef", 'd', 6);
    void *ft2 = ft_memchr("abcdef", 'a', 6);
    void *ori2 = memchr("abcdef", 'a', 6);
    void *ft3 = ft_memchr("abcdef", 'x', 6);
    check_null_ptr(ft3);
    void *ft4= ft_memchr("ab\0cd", '\0', 5);
    void *ori4= memchr("ab\0cd", '\0', 5);
    void *ft5= ft_memchr("abcdef", 'd', 0);
    check_null_ptr(ft5);

    assert_str("memchr test", ft1, ori1);
    assert_str("memchr test", ft2, ori2);
    assert_str("memchr test", ft4, ori4);
}

void test_strncmp()
{
    int ft1 = ft_strncmp("abcdef", "abcxyz", 3);
    int ft2 = ft_strncmp("abc", "abd", 5);
    int ft3 = ft_strncmp("abcx", "abcy", 3);
    int ft4 = ft_strncmp("ab", "abc", 5);
    int ft5 = ft_strncmp("abc", "xyz", 0);

    assert_int("strncmp test 1", ft1, strncmp("abcdef", "abcxyz", 3));
    assert_int("strncmp test 2", ft2, strncmp("abc", "abd", 5));
    assert_int("strncmp test 3", ft3, strncmp("abcx", "abcy", 3));
    assert_int("strncmp test 4", ft4, strncmp("ab", "abc", 5));
    assert_int("strncmp test 5", ft5, strncmp("abc", "xyz", 0));
}

void test_memcmp()
{
    unsigned char a1[] = "abcdef";
    unsigned char b1[] = "abcdef";

    unsigned char a2[] = "abcXef";
    unsigned char b2[] = "abcYef";

    unsigned char a3[] = {'a','b','\0','c'};
    unsigned char b3[] = {'a','b','\0','d'};

    unsigned char a4[] = "\xFF";
    unsigned char b4[] = "\x01";

    unsigned char a5[] = "abc";
    unsigned char b5[] = "xyz";

    assert_int("memcmp test 1", ft_memcmp(a1, b1, 6), memcmp(a1, b1, 6));
    assert_int("memcmp test 2", ft_memcmp(a2, b2, 6), memcmp(a2, b2, 6));
    assert_int("memcmp test 3", ft_memcmp(a3, b3, 4), memcmp(a3, b3, 4));
    assert_int("memcmp test 4", ft_memcmp(a4, b4, 1), memcmp(a4, b4, 1));
    assert_int("memcmp test 5", ft_memcmp(a5, b5, 0), memcmp(a5, b5, 0));
}

void test_atoi()
{
    int ft1 = ft_atoi("1234");
    int ft2 = ft_atoi("   -42");
    int ft3 = ft_atoi("4193 with words");
    int ft4 = ft_atoi("words and 987");
    int ft5 = ft_atoi("--23468");

    assert_int("atoi test 1", ft1, atoi("1234"));
    assert_int("atoi test 2", ft2, atoi("   -42"));
    assert_int("atoi test 3", ft3, atoi("4193 with words"));
    assert_int("atoi test 4", ft4, atoi("words and 987"));
    assert_int("atoi test 5", ft5, atoi("--23468"));
}

void test_strnstr()
{
    // ft_strnstr(input, needle, len)
    char *ft1 = ft_strnstr("abcdef", "cd", 6);
    char *ft2 = ft_strnstr("abcdef", "gh", 6);
    char *ft3 = ft_strnstr("abcdef", "", 6);
    char *ft4 = ft_strnstr("abcdef", "def", 2);
    char *ft5 = ft_strnstr("abcdef", "abc", 0);

    // Expected outputs
    char *exp1 = "cdef";      // "cd" found at index 2
    char *exp2 = NULL;        // "gh" not found
    char *exp3 = "abcdef";    // empty needle returns full string
    char *exp4 = NULL;        // len too short to match "def"
    char *exp5 = NULL;        // n = 0 → cannot match

    assert_str("strnstr test 1", ft1 ? ft1 : "(null)", exp1 ? exp1 : "(null)");
    assert_str("strnstr test 2", ft2 ? ft2 : "(null)", exp2 ? exp2 : "(null)");
    assert_str("strnstr test 3", ft3 ? ft3 : "(null)", exp3 ? exp3 : "(null)");
    assert_str("strnstr test 4", ft4 ? ft4 : "(null)", exp4 ? exp4 : "(null)");
    assert_str("strnstr test 5", ft5 ? ft5 : "(null)", exp5 ? exp5 : "(null)");
}

void test_strdup()
{
    // ft_strdup(input)
    char *ft1 = ft_strdup("hello");
    char *ft2 = ft_strdup("");
    char *ft3 = ft_strdup("  abc 123!? ");
    char *ft4 = ft_strdup("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"); // long
    char *ft5 = ft_strdup("hi\0hi");

    // Expected outputs
    char *exp1 = strdup("hello");
    char *exp2 = strdup("");
    char *exp3 = strdup("  abc 123!? ");
    char *exp4 = strdup("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    char *exp5 = strdup("hi\0hi");

    assert_str("strdup test 1", ft1 ? ft1 : "(null)", exp1 ? exp1 : "(null)");
    assert_str("strdup test 2", ft2 ? ft2 : "(null)", exp2 ? exp2 : "(null)");
    assert_str("strdup test 3", ft3 ? ft3 : "(null)", exp3 ? exp3 : "(null)");
    assert_str("strdup test 4", ft4 ? ft4 : "(null)", exp4 ? exp4 : "(null)");
    assert_str("strdup test 5", ft5 ? ft5 : "(null)", exp5 ? exp5 : "(null)");


    // Free all allocated memory
    free(ft1); free(exp1);
    free(ft2); free(exp2);
    free(ft3); free(exp3);
    free(ft4); free(exp4);
    free (ft5); free(exp5);
}

void test_substr()
{
    //ft_substr
    char *ft1 = ft_substr("hello", 1 , 2);
    char *ft2 = ft_substr("hello", 0, 5);
    char *ft3 = ft_substr("hello", 3, 6);
    char *ft4 = ft_substr("hello", 6, 2);
    char *ft5 = ft_substr("hello", 1, 0);

    // Expected outputs
    char *exp1 = "el";
    char *exp2 = "hello";
    char *exp3 = "lo";
    char *exp4 = "";
    char *exp5 = "";

    assert_str("substr test 1", ft1 ? ft1 : "(null)", exp1 ? exp1 : "(null)");
    assert_str("substr test 2", ft2 ? ft2 : "(null)", exp2 ? exp2 : "(null)");
    assert_str("substr test 3", ft3 ? ft3 : "(null)", exp3 ? exp3 : "(null)");
    assert_str("substr test 4", ft4 ? ft4 : "(null)", exp4 ? exp4 : "(null)");
    assert_str("substr test 5", ft5 ? ft5 : "(null)", exp5 ? exp5 : "(null)");


    // Free all allocated memory
    free(ft1); 
    free(ft2); 
    free(ft3); 
    free(ft4); 
    free (ft5);
}

void test_strjoin()
{
    //ft_strjoin
    char *ft1 = ft_strjoin("hello", "banana");
    char *ft2 = ft_strjoin("hello", "");
    char *ft3 = ft_strjoin("", "hello");

    // Expected outputs
    char *exp1 = "hellobanana";
    char *exp2 = "hello";
    char *exp3 = "hello";

    assert_str("strjoin test 1", ft1 ? ft1 : "(null)", exp1 ? exp1 : "(null)");
    assert_str("strjoin test 2", ft2 ? ft2 : "(null)", exp2 ? exp2 : "(null)");
    assert_str("strjoin test 3", ft3 ? ft3 : "(null)", exp3 ? exp3 : "(null)");

    // Free all allocated memory
    free(ft1); 
    free(ft2); 
    free(ft3); 
}

void test_strtrim()
{
    //input
    char *ft1 = ft_strtrim("hello", "banana");
    char *ft2 = ft_strtrim("hello", "");
    char *ft3 = ft_strtrim("", "hello");
    char *ft4 = ft_strtrim("hello", "le");

    // Expected outputs
    char *exp1 = "hello";
    char *exp2 = "hello";
    char *exp3 = "";
    char *exp4 = "ho";

    assert_str("strtrim test 1", ft1 ? ft1 : "(null)", exp1 ? exp1 : "(null)");
    assert_str("strtrim test 2", ft2 ? ft2 : "(null)", exp2 ? exp2 : "(null)");
    assert_str("strtrim test 3", ft3 ? ft3 : "(null)", exp3 ? exp3 : "(null)");
    assert_str("strtrim test 4", ft4? ft4 : "(null)", exp4 ? exp4 : "(null)");

    // Free all allocated memory
    free(ft1); 
    free(ft2); 
    free(ft3); 
    free(ft4);
}

void assert_split(const char *msg, char **ft_arr, char **exp_arr)
{
    printf("%s\n", msg);

    int i = 0;
    while (exp_arr[i] || ft_arr[i])  // loop until both hit NULL
    {
        if (!exp_arr[i] || !ft_arr[i])
        {
            printf("  ❌ Mismatch: one of the arrays ended early\n");
            printf("%s", exp_arr[i]);
            printf("%s", ft_arr[i]);
            return;
        }
        assert_str("  element", ft_arr[i], exp_arr[i]);
        i++;
    }

    printf("  ✓ OK\n");
}

void test_split()
{
    // ------------------
    // Test case 1: basic split
    // ------------------
    char **ft1 = ft_split("hello world test", ' ');
    char *exp1[] = {"hello", "world", "test", NULL};
    assert_split("split test 1", ft1, exp1);

    // ------------------
    // Test case 2: multiple consecutive delimiters
    // ------------------
    char **ft2 = ft_split("a--b---c-", '-');
    char *exp2[] = {"a", "b", "c", NULL};
    assert_split("split test 2", ft2, exp2);

    // ------------------
    // Test case 3: empty string input
    // ------------------
    char **ft3 = ft_split("", ',');
    char *exp3[] = {NULL};   // no substrings
    assert_split("split test 3", ft3, exp3);

    // ------------------
    // Test case 4: delimiter not found
    // ------------------
    char **ft4 = ft_split("abcdef", ' ');
    char *exp4[] = {"abcdef", NULL};
    assert_split("split test 4", ft4, exp4);

    // ------------------
    // Test case 5: string is all delimiters (edge case)
    // ------------------
    char **ft5 = ft_split(";;;;;;", ';');
    char *exp5[] = {NULL};
    assert_split("split test 5", ft5, exp5);


    // ------------------
    // Free all allocated memory
    // ------------------
    int i;

    i = 0; while (ft1 && ft1[i]) free(ft1[i++]); free(ft1);
    i = 0; while (ft2 && ft2[i]) free(ft2[i++]); free(ft2);
    i = 0; while (ft3 && ft3[i]) free(ft3[i++]); free(ft3);
    i = 0; while (ft4 && ft4[i]) free(ft4[i++]); free(ft4);
    i = 0; while (ft5 && ft5[i]) free(ft5[i++]); free(ft5);
}


// -------------------- Main --------------------

int main()
{
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_tolower();
    test_toupper();
    test_ftstrchr();
    test_ftstrrchr();
    test_memchr();
    test_strncmp();
    test_memcmp();
    test_strnstr();
    test_atoi();
    test_strdup();
    test_substr();
    test_strjoin();
    test_strtrim();
    test_split();
    return 0;
}
