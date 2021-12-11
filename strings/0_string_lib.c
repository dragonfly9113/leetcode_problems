/*
My implementation of standard C string library functions.
0_string_lib_funcs.c
*/
#include <stdio.h>
#include <string.h>
       
/*
NAME
       strchr — string scanning operation
SYNOPSIS
       #include <string.h>
       char *strchr(const char *s, int c);
DESCRIPTION
       The strchr() function shall locate the first occurrence of c
       (converted to a char) in the string pointed to by s.  The
       terminating NUL character is considered to be part of the string.
RETURN VALUE
       Upon completion, strchr() shall return a pointer to the byte, or
       a null pointer if the byte was not found.
*/
/*
Version 1
*/
char *my_strchr_1(const char *s, int c) {
    for (; *s != '\0'; s++)
        if (*s == (char)c)
            return (char *)s;
    return NULL;
}

/*
Version 2
P. J. Plauger version
*/
char *my_strchr(const char *s, int c) {
    const char ch = c;

    for (; *s != ch; s++)
        if (*s == '\0')
            return (NULL);
    return ((char *)s);
}

int main_strchr() {
    char *s1 = "Hello, World!";
    char c1 = 'H';
    char c2 = 'l';
    char c3 = 'W';
    char c4 = 'w';

    printf("s: %s, c: %c\n", s1, c1);
    printf("First occurence of c: %s\n", my_strchr(s1, c1));
    printf("s: %s, c: %c\n", s1, c2);
    printf("First occurence of c: %s\n", my_strchr(s1, c2));
    printf("s: %s, c: %c\n", s1, c3);
    printf("First occurence of c: %s\n", my_strchr(s1, c3));
    printf("s: %s, c: %c\n", s1, c4);
    printf("First occurence of c: %s\n", my_strchr(s1, c4));

    return 0;
}

/*
NAME
       strstr - locate a substring
SYNOPSIS
       #include <string.h>
       char *strstr(const char *haystack, const char *needle);
DESCRIPTION
       The strstr() function finds the first occurrence of the substring
       needle in the string haystack.  The terminating null bytes ('\0')
       are not compared.
RETURN VALUE
       These functions return a pointer to the beginning of the located
       substring, or NULL if the substring is not found.
       If needle is the empty string, the return value is always
       haystack itself.
Example:
    haystack = "abcollomg", needle = "omg"
    ans = "omg"
*/
/*
Version 1
1. First use strchr() to find the first occurrence of *needle (first char of needle);
2. Then check if needle is a substring;
    a. If yes, return the proper pointer.
    b. If no, find the next occurrence of *needle and repeat step 2.
*/
char *my_strstr_1(const char *haystack, const char *needle) {
    if (*needle == '\0')
        return (char *)haystack;

    for (const char *h = haystack; (h = my_strchr(h, (int)*needle)) != NULL; h++) {
        const char *n = needle;
        for (const char *h1 = h; *n != '\0'; h1++, n++)
            if (*n != *h1) break;
        if (*n == '\0') 
            return (char *)h;
    }
    return NULL;
}

/*
Version 2
P. J. Plauger version
*/
char *my_strstr(const char *s1, const char *s2) {
    if (*s2 == '\0')
        return ((char *)s1);
    for (; (s1 = my_strchr(s1, *s2)) != NULL; ++s1) {
        for (const char *sc1 = s1, *sc2 = s2; ; ) {
            if (*++sc2 == '\0')
                return (char *)s1;
            else if (*++sc1 != *sc2)
                break;
        }
    }
    return NULL;
}

int main() {
    char *h1 = "abclloomg";
    char *n1 = "abc";
    char *n2 = "acb";
    char *n3 = "LL";
    char *n4 = "omg";
    char *n5 = "";

    printf("ans = %s\n", my_strstr(h1, n1));
    printf("ans = %s\n", my_strstr(h1, n2));
    printf("ans = %s\n", my_strstr(h1, n3));
    printf("ans = %s\n", my_strstr(h1, n4));
    printf("ans = %s\n", my_strstr(h1, n5));

    return 0;
}



