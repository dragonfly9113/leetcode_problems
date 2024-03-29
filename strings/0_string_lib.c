/*
My implementation of standard C string library functions.
0_string_lib_funcs.c

Version1s are usually my own versions and version2s are usually the implementations borrowed from P. J. Plauger's standard C library.
*/
/*
You use the functions declared in <string.h> to manipulate strings of characters. You characterize each string by an argument (call it s) which is a pointer to the start of the string.
* If a string can contain null characters, you must also specify its length (call it n) as an additional argument. n can be zero. Use the functions whose names begin with mem.
* If a string may or may not have a terminating null character, you must similarly specify its maximum length n, which can be zero. Use the functions whose names begin with strn.
* If a string assuredly has a terminating null character, you specify only s. Use the remaining functions whose names begin with str.
*/
#include <stdio.h>
#include <string.h>

/*
NAME
       memchr, memrchr, rawmemchr - scan memory for a character
SYNOPSIS
       #include <string.h>

       void *memchr(const void *s, int c, size_t n);
       void *memrchr(const void *s, int c, size_t n);
       void *rawmemchr(const void *s, int c);

   Feature Test Macro Requirements for glibc (see
   feature_test_macros(7)):

       memrchr(), rawmemchr():
           _GNU_SOURCE
DESCRIPTION
       The memchr() function scans the initial n bytes of the memory
       area pointed to by s for the first instance of c.  Both c and the
       bytes of the memory area pointed to by s are interpreted as
       unsigned char.

       The memrchr() function is like the memchr() function, except that
       it searches backward from the end of the n bytes pointed to by s
       instead of forward from the beginning.

       The rawmemchr() function is similar to memchr(): it assumes
       (i.e., the programmer knows for certain) that an instance of c
       lies somewhere in the memory area starting at the location
       pointed to by s, and so performs an optimized search for c (i.e.,
       no use of a count argument to limit the range of the search).  If
       an instance of c is not found, the results are unpredictable.
       The following call is a fast means of locating a string's
       terminating null byte:

           char *p = rawmemchr(s, '\0');
RETURN VALUE
       The memchr() and memrchr() functions return a pointer to the
       matching byte or NULL if the character does not occur in the
       given memory area.

       The rawmemchr() function returns a pointer to the matching byte,
       if one is found.  If no matching byte is found, the result is
       unspecified.
*/
/*
Version 1
*/
void *my_memchr_1(const void *s, int c, size_t n) {
    const unsigned char ch = c;
    const unsigned char *sc = s;

    for (size_t i = 0; *sc != ch; sc++, i++)
        if (i == n)
            return NULL;
    return (void *)sc;
}

/*
Version 2
P. J. Plauger version

The major concern of function memchr is to get various types right. You must assign both the pointer and the character arguments to dynamic data objects with different types. That lets you compare the array elements as type unsigned char correctly and efficiently. I wrote the (void *) type cast in the return expression for clarity, not out of necessity.
*/
void *my_memchr(const void *s, int c, size_t n) {
    const unsigned char uc = c;
    const unsigned char *su;

    for (su = s; 0 < n; ++su, --n)
        if (*su == uc)
            return ((void *)su);
    return (NULL);
}

int main_memchr() {
    char *s1 = "Hello, World!";
    char c1 = 'H';
    char c2 = 'l';
    char c3 = 'W';
    char c4 = 'w';

    printf("s = %s\n",s1);
    printf("c = %c  %s\n", c1, my_memchr(s1, c1, 5));
    printf("c = %c  %s\n", c2, my_memchr(s1, c2, 5));
    printf("c = %c  %s\n", c3, my_memchr(s1, c3, 5));
    printf("c = %c  %s\n", c4, my_memchr(s1, c4, 13));

    return 0;
}

/*
NAME
       memcmp - compare memory areas
SYNOPSIS
       #include <string.h>

       int memcmp(const void *s1, const void *s2, size_t n);
DESCRIPTION
       The memcmp() function compares the first n bytes (each
       interpreted as unsigned char) of the memory areas s1 and s2.
RETURN VALUE
       The memcmp() function returns an integer less than, equal to, or
       greater than zero if the first n bytes of s1 is found,
       respectively, to be less than, to match, or be greater than the
       first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign of
       the difference between the first pair of bytes (interpreted as
       unsigned char) that differ in s1 and s2.

       If n is zero, the return value is zero.
*/
/*
Version 1
*/
int my_memcmp_1(const void *s1, const void *s2, size_t n) {
    const unsigned char *su1;
    const unsigned char *su2;

    for (su1 = s1, su2 = s2; 0 < n; --n, ++su1, ++su2)
        if (*su1 != *su2)
            return (int)(*su1 - *su2);
    return 0;
}

/*
Version 2
P. J. Plauger version

The memcmp function is also careful to perform unsigned char comparisons to meeting the requirements of the C Standard.
*/
int my_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *su1, *su2;

    for (su1 = s1, su2 = s2; 0 < n; --n, ++su1, ++su2)
        if (*su1 != *su2)
            return (*su1 < *su2 ? -1 : +1);
    return 0;
}

int main_memcmp() {
    char *s1 = "abcdef";
    char *s21 = "abc";
    char *s22 = "bcdefgh";
    char *s23 = "abcaaa";

    printf("ans = %d\n", my_memcmp(s1, s21, 6));
    printf("ans = %d\n", my_memcmp(s1, s22, 6));
    printf("ans = %d\n", my_memcmp(s1, s23, 6));
    printf("ans = %d\n", my_memcmp(s1, s21, 3));
    printf("ans = %d\n", my_memcmp(s1, s23, 0));

    return 0;
}


/*
NAME
       memcpy - copy memory area
SYNOPSIS
       #include <string.h>

       void *memcpy(void *restrict dest, const void *restrict src, size_t n);
DESCRIPTION
       The memcpy() function copies n bytes from memory area src to
       memory area dest.  The memory areas must not overlap.  Use
       memmove(3) if the memory areas do overlap.
RETURN VALUE
       The memcpy() function returns a pointer to dest.
NOTES
       Failure to observe the requirement that the memory areas do not
       overlap has been the source of significant bugs.  (POSIX and the
       C standards are explicit that employing memcpy() with overlapping
       areas produces undefined behavior.)  Most notably, in glibc 2.13
       a performance optimization of memcpy() on some platforms
       (including x86-64) included changing the order in which bytes
       were copied from src to dest.

       This change revealed breakages in a number of applications that
       performed copying with overlapping areas.  Under the previous
       implementation, the order in which the bytes were copied had
       fortuitously hidden the bug, which was revealed when the copying
       order was reversed.  In glibc 2.14, a versioned symbol was added
       so that old binaries (i.e., those linked against glibc versions
       earlier than 2.14) employed a memcpy() implementation that safely
       handles the overlapping buffers case (by providing an "older"
       memcpy() implementation that was aliased to memmove(3)).
*/
/*
Version 1
*/
void *my_memcpy_1(void *restrict dest, const void *restrict src, size_t n) {
    const unsigned char *s;
    unsigned char *d;

    for (s = src, d = dest; 0 < n; --n, ++s, ++d)
        *d = *s;
    return dest;
}

/*
Version 2
P. J. Plauger version

I chose char as the working type within memcpy in the off chance that some computer architectures may favor it over unsigned char. (That's one of the justifications for having a "plain" character type.) memcpy can assume that its source and destination areas do not overlap.
*/
void *my_memcpy(void *s1, const void *s2, size_t n) {
    char *su1;
    const char *su2;

    for (su1 = s1, su2 = s2; 0 < n; --n, ++su1, ++su2)
        *su1 = *su2;
    return s1;
}

#define MAX_MEM_LEN 100
int main_memcpy() {
    char *s = "Hello, World!";
    char d[MAX_MEM_LEN] = {};

    printf("dest = %s\n", my_memcpy(d, s, MAX_MEM_LEN));

    return 0;
}


/*
NAME
       memmove - copy memory area
SYNOPSIS
       #include <string.h>

       void *memmove(void *dest, const void *src, size_t n);
DESCRIPTION
       The memmove() function copies n bytes from memory area src to
       memory area dest.  The memory areas may overlap: copying takes
       place as though the bytes in src are first copied into a
       temporary array that does not overlap src or dest, and the bytes
       are then copied from the temporary array to dest.
RETURN VALUE
       The memmove() function returns a pointer to dest.
*/
/*
Version 1
*/
void *my_memmove_1(void *dest, const void *src, size_t n) {
    char tmp[n];
    char *d, *t;
    const char *s;
    size_t nu = n;

    for (t = tmp, s = src; 0 < nu; --nu, ++t, ++s)
        *t = *s;
    nu = n;
    for (d = dest, t = tmp; 0 < nu; --nu, ++d, ++t)
        *d = *t;
    return dest;
}

/*
Version 2
Still my version but based on P. J. Plauger idea!

The function memmove must work properly even when its operands overlap. Hence, it first checks for an overlap that would prevent the correct operation of an ascending copy. In that case, it copies elements in descending order.

The following condition is the only condition that the overlap matters. Even the condition of sc1 == sc2 is fine because that will just mean each element will overwrite itself, which is still ok.
sc2 < sc1 && sc1 < sc2 + n
[sc2 .................... sc2+n-1]
    [sc1 .................... sc1+n-1]
This is OK:
    [sc2 .................... sc2+n-1]
 [sc1 .................... sc1+n-1]
This is OK:
[sc2 .................... sc2+n-1]
[sc1 .................... sc1+n-1]
This is OK:
[sc2 .................... sc2+n-1]
                                  [sc1 .................... sc1+n-1]
*/
void *my_memmove_2(void *s1, const void *s2, size_t n) {
    char *sc1;
    const char *sc2;

    if (s2 < s1 && s1 < s2 + n) {
        sc1 = s1 + n - 1;
        sc2 = s2 + n - 1;
        for (; 0 < n; --n, --sc1, --sc2)
            *sc1 = *sc2;
    } else {
        sc1 = s1;
        sc2 = s2;
        for (; 0 < n; --n, ++sc1, ++sc2)
            *sc1 = *sc2;
    }
    return s1;
}

/*
Version 3
P. J. Plauger version
*/
void *my_memmove(void *s1, const void *s2, size_t n) {
    char *sc1;
    const char *sc2;

    sc1 = s1;
    sc2 = s2;
    if (sc2 < sc1 && sc1 < sc2 + n)
        for (sc1 += n, sc2 += n; 0 < n; --n)
            *--sc1 = *--sc2;    /* copy backwards */
    else
        for (; 0 < n; --n)
            *sc1++ = *sc2++;    /* copy forwards */
    return s1;
}

int main_memmove() {
    char *s = "Hello, World!";
    char d[MAX_MEM_LEN] = {};

    printf("dest = %s\n", my_memmove(d, s, MAX_MEM_LEN));

    return 0;
}

/*
NAME
       memset - fill memory with a constant byte
SYNOPSIS
       #include <string.h>

       void *memset(void *s, int c, size_t n);
DESCRIPTION
       The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
RETURN VALUE
       The memset() function returns a pointer to the memory area s.
*/
/*
Version 1
*/
void *my_memset_1(void *s, int c, size_t n) {
    unsigned char *su;
    const unsigned char cu = c;

    for (su = s; 0 < n; --n, ++su)
        *su = cu;
    return s;
}

/*
Version 2
P. J. Plauger version

I chose unsigned char as the working type within memset in the off chance that some implementation might generate an overflow storing certain int values in the other character types.
*/
void *my_memset(void *s, int c, size_t n) {
    const unsigned char uc = c;
    unsigned char *su;

    for (su = s; 0 < n; ++su, --n)
        *su = uc;
    return s;
}

int main_memset() {
    char s[MAX_MEM_LEN];

    printf("s = %s\n", my_memset(s, 'o', 20)); 

    return 0;
}


/*
NAME
       strncat — concatenate a string with part of another
SYNOPSIS
       #include <string.h>

       char *strncat(char *restrict s1, const char *restrict s2, size_t n);
DESCRIPTION
       The functionality described on this reference page is aligned
       with the ISO C standard. Any conflict between the requirements
       described here and the ISO C standard is unintentional. This
       volume of POSIX.1‐2017 defers to the ISO C standard.

       The strncat() function shall append not more than n bytes (a NUL
       character and bytes that follow it are not appended) from the
       array pointed to by s2 to the end of the string pointed to by s1.
       The initial byte of s2 overwrites the NUL character at the end of
       s1.  A terminating NUL character is always appended to the
       result. If copying takes place between objects that overlap, the
       behavior is undefined.
RETURN VALUE
       The strncat() function shall return s1; no return value shall be
       reserved to indicate an error.
*/
/*
Version 1
*/
char *my_strncat_1(char *restrict s1, const char *restrict s2, size_t n) {
    int len = strlen(s1);
    char *sc1 = s1;

    for (sc1 += len; 0 < n; --n, ++sc1, ++s2) {
        if (*s2 == '\0')
            break;
        *sc1 = *s2;
    }
    *sc1 = '\0';
    return s1;
}

/*
Version 2
P. J. Plauger version

The function strncat first locates the end of the destination string. Then it concatenates at most n additional from the source string. Note that the function always supplies a terminating null character.
*/
char *my_strncat(char *s1, const char *s2, size_t n) {
    char *s;

    for (s = s1; *s != '\0'; s++)    
        ;
    for (; 0 < n && *s2 != '\0'; n--)
        *s++ = *s2++;
    *s = '\0';
    return s1;
}

int main_strncat() {
    char s11[MAX_MEM_LEN] = "abc";
    char s12[MAX_MEM_LEN] = "abc";
    char s13[MAX_MEM_LEN] = "abc";
    char s14[MAX_MEM_LEN] = "abc";
    char *s2 = "efg";

    printf("ans = %s\n", my_strncat(s11, s2, 0));
    printf("ans = %s\n", my_strncat(s12, s2, 2));
    printf("ans = %s\n", my_strncat(s13, s2, 3));
    printf("ans = %s\n", my_strncat(s14, s2, 5));

    return 0;
}

/*
NAME
       strncmp — compare part of two strings
SYNOPSIS
       #include <string.h>

       int strncmp(const char *s1, const char *s2, size_t n);
DESCRIPTION
       The functionality described on this reference page is aligned
       with the ISO C standard. Any conflict between the requirements
       described here and the ISO C standard is unintentional. This
       volume of POSIX.1‐2017 defers to the ISO C standard.

       The strncmp() function shall compare not more than n bytes (bytes
       that follow a NUL character are not compared) from the array
       pointed to by s1 to the array pointed to by s2.

       The sign of a non-zero return value is determined by the sign of
       the difference between the values of the first pair of bytes
       (both interpreted as type unsigned char) that differ in the
       strings being compared.
RETURN VALUE
       Upon successful completion, strncmp() shall return an integer
       greater than, equal to, or less than 0, if the possibly null-
       terminated array pointed to by s1 is greater than, equal to, or
       less than the possibly null-terminated array pointed to by s2
       respectively.
*/
/*
Version 1
*/
int my_strncmp_1(const char *s1, const char *s2, size_t n) {
    const unsigned char *su1;
    const unsigned char *su2;

    for (su1 = s1, su2 = s2; 0 < n && *su1 != '\0' && *su2 != '\0'; n--, su1++, su2++) {
        if (*su1 == *su2)
            continue;
        return (*su1 > *su2 ? 1 : -1);
    }
    if (n == 0 || (*su1 == '\0' && *su2 == '\0'))
        return 0;
    return (*su1 > *su2 ? 1 : -1);    
}

/*
Version 2
P. J. Plauger version

The function strncmp is similar to memcmp, except that it also stops on a terminating null charater. And unlike memcmp, strncmp can use its pointer arguments directly. It type casts them to pointer to unsigned char only to compute a nonzero return value.
*/
int my_strncmp(const char *s1, const char *s2, size_t n) {
    for (; 0 < n; n--, s1++, s2++)
        if (*s1 != *s2)
            return (*(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1);
        else if (*s1 == '\0')
            return 0;
    return 0;
}

int main_strncmp() {
    char *s11 = "abc";
    char *s21 = "abcdef";
    char *s22 = "aba";

    printf("ans = %d\n", my_strncmp(s11, s21, 3));
    printf("ans = %d\n", my_strncmp(s11, s21, 4));
    printf("ans = %d\n", my_strncmp(s11, s22, 3));
    printf("ans = %d\n", my_strncmp(s11, s11, 4));

    return 0;
}

/*
NAME
       stpncpy, strncpy — copy fixed length string, returning a pointer
       to the array end
SYNOPSIS
       #include <string.h>

       char *stpncpy(char *restrict s1, const char *restrict s2, size_t n);
       char *strncpy(char *restrict s1, const char *restrict s2, size_t n);
DESCRIPTION
       The stpncpy() and strncpy() functions shall copy not more than n
       bytes (bytes that follow a NUL character are not copied) from the
       array pointed to by s2 to the array pointed to by s1.

       If the array pointed to by s2 is a string that is shorter than n
       bytes, NUL characters shall be appended to the copy in the array
       pointed to by s1, until n bytes in all are written.

       If copying takes place between objects that overlap, the behavior
       is undefined.
RETURN VALUE
       If a NUL character is written to the destination, the stpncpy()
       function shall return the address of the first such NUL
       character.  Otherwise, it shall return &s1[n].

       The strncpy() function shall return s1.

       No return values are reserved to indicate an error.
*/
char *my_strncpy_1(char *restrict s1, const char *restrict s2, size_t n) {
    char *sc1;

    for (sc1 = s1; 0 < n; n--) {
        if (*s2 == '\0')
            break;
        *sc1++ = *s2++;
    }
    if (n == 0) {
        *sc1 = '\0';
        return s1;
    }
    for (; 0 < n; n--)
        *sc1++ = '\0';
    return s1;
}

/*
Version 2
P. J. Plauger version

The function strncpy is similar to memcpy, except that it stops on a terminating null. strncpy also has the unfortunate requirement that it must supply null padding characters for a string whose length is less than n.
*/
char *my_strncpy(char *s1, const char *s2, size_t n) {
    char *s;

    for (s = s1; 0 < n && *s2 != '\0'; --n)
        *s++ = *s2++;
    for (; 0 < n; --n)
        *s++ = '\0';
    return s1;
}

//#define MAX_MEM_LEN 100
int main_strncpy() {
    char *s2 = "Hello, World!";
    char s1[MAX_MEM_LEN] = {};

    printf("s1 = %s\n", my_strncpy(s1, s2, 5));
    printf("s1 = %s\n", my_strncpy(s1, s2, 13));
    printf("s1 = %s\n", my_strncpy(s1, s2, 14));
    printf("s1 = %s\n", my_strncpy(s1, s2, 15));

    return 0;
}

/*
Three of the str functions are direct analogs of the strn functions. The functions strcat, strcmp and strcpy differ only in not worring about a limiting string length n. Of cause, strcpy has no padding to contend with.
*/
/*
Version 1: strcat
*/
char *my_strcat_1(char *s1, const char *s2) {
    char *s;

    for (s = s1; *s != '\0'; s++)
        ;
    for (; *s2 != '\0'; )
        *s++ = *s2++;
    *s = '\0';
    return s1;
}

/*
Version 2
P. J. Plauger version
*/
char *my_strcat(char *s1, const char *s2) {
    char *s;

    for (s = s1; *s != '\0'; ++s)
        ;
    for (; (*s = *s2) != '\0'; ++s, ++s2)
        ;
    return s1;
}

/*
Version 1: strcmp
*/
int my_strcmp_1(const char *s1, const char *s2) {
    for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
        if (*s1 != *s2)
            return (*s1 < *s2 ? -1 : 1);
    if (*s1 != *s2)
        return (*s1 < *s2 ? -1 : 1);
    else
        return 0;
}

/*
Version 2
P. J. Plauger version
*/
int my_strcmp(const char *s1, const char *s2) {
    for (; *s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return 0;
    return (*(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1);
}

/*
Version 1: strcpy
*/
char *my_strcpy_1(char *s1, const char *s2) {
    char *s;

    for (s = s1; *s2 != '\0'; )
        *s++ = *s2++;
    *s = '\0';
    return s1;
}

/*
Version 2
P. J. Plauger version
*/
char *my_strcpy(char *s1, const char *s2) {
    char *s = s1;

    for (s = s1; (*s++ = *s2++) != '\0'; )
        ;
    return s1;
}

/*
Version 1: strlen
*/
size_t my_strlen_1(const char *s) {
    size_t cnt = 0;

    for (; *s != '\0'; s++)
        cnt++;
    return cnt;
}

/*
Version 2
P. J. Plauger version
*/
size_t my_strlen(const char *s) {
    const char *sc;

    for (sc = s; *sc != '\0'; ++sc)
        ;
    return (sc - s);
}

int main_strlen() {
    char *s1 = "Hello";
    char *s2 = "Hello, world!";
    char *s3 = "";

    printf("len = %d\n", my_strlen(s1));
    printf("len = %d\n", my_strlen(s2));
    printf("len = %d\n", my_strlen(s3));
}

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
       strcspn — get the length of a complementary substring
SYNOPSIS
       #include <string.h>

       size_t strcspn(const char *s1, const char *s2);
DESCRIPTION
       The strcspn() function shall compute the length (in bytes) of the
       maximum initial segment of the string pointed to by s1 which
       consists entirely of bytes not from the string pointed to by s2.
RETURN VALUE
       The strcspn() function shall return the length of the computed
       segment of the string pointed to by s1; no return value is
       reserved to indicate an error.
Example
    s1 = "abcdefg"
    s2 = "xyzdt"
    ans = 3 because the initial segment of s1 "abc" consitss entirely of bytes not from s2 = "xyzdt".
*/
/*
Version 1
*/
size_t my_strcspn(const char *s1, const char *s2) {
    const char *sc1;
    const char *sc2;

    for (sc1 = s1; *sc1 != '\0'; sc1++)
        for (sc2 = s2; *sc2 != '\0'; sc2++)
            if (*sc1 == *sc2)
                return (sc1 - s1);
    return (sc1 - s1);
}

/*
Version 2
P. J. Plauger version
Almost the same as version 1!
*/

int main_strcspn() {
    char *s1 = "abcdefg";
    char *s21 = "xyzdt";
    char *s22 = "yscha";
    char *s23 = "xyz";

    printf("ans = %d\n", my_strcspn(s1, s21));
    printf("ans = %d\n", my_strcspn(s1, s22));
    printf("ans = %d\n", my_strcspn(s1, s23));

    return 0;
}

/*
NAME
       strpbrk - search a string for any of a set of bytes
SYNOPSIS
       #include <string.h>

       char *strpbrk(const char *s, const char *accept);
DESCRIPTION
       The strpbrk() function locates the first occurrence in the string
       s of any of the bytes in the string accept.
RETURN VALUE
       The strpbrk() function returns a pointer to the byte in s that
       matches one of the bytes in accept, or NULL if no such byte is
       found.
Example
    s = "abcdefg"
    accept = "xyzdt"
    returns a pointer to 'd' in s, which matches one of the bytes in accept.
*/
char *my_strpbrk_1(const char *s, const char *accept) {
    const char *sc, *ac;

    for (sc = s; *sc != '\0'; sc++)
        for (ac = accept; *ac != '\0'; ac++)
            if (*sc == *ac)
                return (char *)sc;
    return NULL;
}

/*
Version 2
P. J. Plauger version
*/
char *my_strpbrk(const char *s1, const char *s2) {
    const char *sc1, *sc2;

    for (sc1 = s1; *sc1 !='\0'; ++sc1)
        for (sc2 = s2; *sc2 != '\0'; ++sc2)
            if (*sc1 == *sc2)
                return (char *)sc1;
    return NULL;
}

int main_strpbrk() {
    char *s1 = "abcdefg";
    char *s21 = "xyzdt";
    char *s22 = "rstabc";
    char *s23 = "xyzrstuvy";

    printf("ans = %s\n", my_strpbrk(s1, s21));
    printf("ans = %s\n", my_strpbrk(s1, s22));
    printf("ans = %s\n", my_strpbrk(s1, s23));

    return 0;
}

/*
NAME
       strspn, strcspn - get length of a prefix substring
SYNOPSIS
       #include <string.h>

       size_t strspn(const char *s, const char *accept);
       size_t strcspn(const char *s, const char *reject);
DESCRIPTION
       The strspn() function calculates the length (in bytes) of the
       initial segment of s which consists entirely of bytes in accept.

       The strcspn() function calculates the length of the initial
       segment of s which consists entirely of bytes not in reject.
RETURN VALUE
       The strspn() function returns the number of bytes in the initial
       segment of s which consist only of bytes from accept.

       The strcspn() function returns the number of bytes in the initial
       segment of s which are not in the string reject.
Example
    s = "abcdefg"
    accept = "xyzabc"
    ans = 3 because "abc" is the initial segment of s which consist only of bytes from accept.
*/
size_t my_strspn_1(const char *s, const char *accept) {
    const char *sc, *ac;

    for (sc = s; *sc != '\0'; sc++) {
        for (ac = accept; *ac != '\0' && *sc != *ac; ac++)
            ;
        if (*ac == '\0')
            return (sc - s);
    }
    return (sc -s);
}

/*
Version 2
P. J. Plauger version

Example
    s = "abcdefg"
    accept = "xyzabc"
    ans = 3 because "abc" is the initial segment of s which consist only of bytes from accept.
*/
size_t my_strspn(const char *s1, const char *s2) {
    const char *sc1, *sc2;

    for (sc1 = s1; *sc1 != '\0'; ++sc1)
        for (sc2 = s2; ; ++sc2)
            if (*sc2 == '\0')
                return (sc1 - s1);
            else if (*sc1 == *sc2)
                break;
    return (sc1 - s1);
}

int main_strspn() {
    char *s1 = "abcdefg";
    char *s21 = "xyzcba";
    char *s22 = "rstabcopqefgd";
    char *s23 = "xyzrstuvy";

    printf("ans = %d\n", my_strspn(s1, s21));
    printf("ans = %d\n", my_strspn(s1, s22));
    printf("ans = %d\n", my_strspn(s1, s23));

    return 0;
}

/*
NAME
       strrchr — string scanning operation
SYNOPSIS
       #include <string.h>

       char *strrchr(const char *s, int c);
DESCRIPTION
       The strrchr() function shall locate the last occurrence of c
       (converted to a char) in the string pointed to by s.  The
       terminating NUL character is considered to be part of the string.
RETURN VALUE
       Upon successful completion, strrchr() shall return a pointer to
       the byte or a null pointer if c does not occur in the string.
EXAMPLES
   Finding the Base Name of a File
       The following example uses strrchr() to get a pointer to the base
       name of a file. The strrchr() function searches backwards through
       the name of the file to find the last '/' character in name.
       This pointer (plus one) will point to the base name of the file.

           #include <string.h>
           ...
           const char *name;
           char *basename;
           ...
           basename = strrchr(name, '/') + 1;
           ...
*/
char *my_strrchr_1(const char *s, int c) {
    const char ch = c;
    size_t n = strlen(s);

    for (s += n - 1; 0 < n; --n, --s)
        if (*s == ch)
            return (char *)s;
    return NULL;
}

/*
Version 2
P. J. Plauger version

The function strrchr is a useful complement to strchr. It memorizes the pointer to the rightmost orrurrence (in any) in sc. The type cast in the return statement is necessary, in this case, because sc points to a constant type.
*/
char *my_strrchr_2(const char *s, int c) {
    const char ch = c;
    const char *sc;

    for (sc = NULL; ;++s) {
        if (*s == ch)
            sc = s;
        if (*s == '\0')
            return (char *)sc;
    }
}

/*
Version 3
P. J. Plauger version + my touch
*/
char *my_strrchr(const char *s, int c) {
    const char ch = c;
    const char *sc;

    for (sc = NULL; *s != '\0' ;++s)
        if (*s == ch)
            sc = s;
    return (char *)sc;
}

int main_strrchr() {
    char *s = "Hello, World!";
    int c1 = 'H';
    int c2 = 'W';
    int c3 = 'w';

    printf("ans = %s\n", my_strrchr(s, c1));
    printf("ans = %s\n", my_strrchr(s, c2));
    printf("ans = %s\n", my_strrchr(s, c3));

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

int main_strstr() {
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
