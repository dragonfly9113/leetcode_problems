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

int main() {
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



