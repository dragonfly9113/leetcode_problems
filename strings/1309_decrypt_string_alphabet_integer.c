/*
1309. Decrypt String from Alphabet to Integer Mapping
1309_decrypt_string_alphabet_integer.c

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:
Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.
It's guaranteed that a unique mapping will always exist.

Example 1:
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:
Input: s = "1326#"
Output: "acz"

Example 3:
Input: s = "25#"
Output: "y"

Example 4:
Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

Constraints:
1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1 - NOT OK!

It passed all 4 examples on local PC. But cannot run on Leetcode online tester. I got the following error:
==31== Error: AddressSanitizer: heap-buffer-overflow on address....
I cannot figure out what went wrong on LeetCode tester!
*/
#define MAX_LEN 1001
char * freqAlphabets_1(char * s){
    int n = strlen(s);
    char *alphabets = "0abcdefghijklmnopqrstuvwxyz";
    char *s1, *s2, *p;

    char *out = calloc(MAX_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL. calloc() failed!\n");
        exit(1);
    }

    p = out;
    for (s1 = s, s2 = s + 2; ; ) {
        if (*s2 == '#') {
            int d = (*s1 - '0') * 10 + (*(s1 + 1) - '0');
            *p++ = alphabets[d];
            s1 += 3;
            s2 += 3;
        }
        else if (n < s2 - s) {
            if (*s1 == '\0')
                break;
            *p++ = alphabets[*s1 - '0'];
            s1++;
        }
        else if (*(s2 + 1) == '#') {
            *p++ = alphabets[*s1 - '0'];
            s1++;
            s2++;
        }
        else {
            *p++ = alphabets[*s1 - '0'];
            *p++ = alphabets[*(s1 + 1) - '0'];
            s1 += 2;
            s2 += 2;
        }
    }
    return out;
}

/*
Version 2

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Example 1:
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
*/
#define MAX_LEN 1001
char * freqAlphabets_2(char * s){
    int n = strlen(s);
    char *alphabets = "0abcdefghijklmnopqrstuvwxyz";
    char *p;

    char *out = calloc(MAX_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL. calloc() failed!\n");
        exit(1);
    }

    p = out;
    int i;
    for (i = 0; i < n - 2; ) {
        int idx;
        if (s[i + 2] == '#') {
            idx = (s[i] - '0') * 10 + (s[i + 1] - '0');
            *p++ = alphabets[idx];
            i += 3;
            continue;
        }
        idx = s[i] - '0';
        *p++ = alphabets[idx];
        i++;
    }
    for ( ; s[i] != '\0'; i++) {
        int idx = s[i] - '0';
        *p++ = alphabets[idx];
    }
    return out;    
}

/*
Version 2.1 - NOT OK!

Still cannot pass online tester. I think there are some test cases of online tester will espcate the condition check in for loop and will cause the out buffer to overflow. But I'm not sure which case(s)?
*/
char * freqAlphabets_2_1(char * s){
    int n = strlen(s);
    char *alphabets = "0abcdefghijklmnopqrstuvwxyz";
    char *p;

    char *out = calloc(MAX_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL. calloc() failed!\n");
        exit(1);
    }

    p = out;
    for (int i = 0; i < n - 2 || s[i] != '\0'; ) {
        int idx;
        if (s[i + 2] == '#') {
            idx = (s[i] - '0') * 10 + (s[i + 1] - '0');
            *p++ = alphabets[idx];
            i += 3;
            continue;
        }
        idx = s[i] - '0';
        *p++ = alphabets[idx];
        i++;
    }
    return out;    
}

/*
Version 2.2
A more compact version of version 2.
Note the key here is the below condifion within the for loop:
        if (i < n - 2 && s[i + 2] == '#') {

I'm still not sure why we need i < n - 2 in the above condition. There might be a test case that warrants the necessity but I'm not sure which one?
*/
char * freqAlphabets(char * s){
    int n = strlen(s);
    char *alphabets = "0abcdefghijklmnopqrstuvwxyz";
    char *p;

    char *out = calloc(MAX_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL. calloc() failed!\n");
        exit(1);
    }

    p = out;
    for (int i = 0; i < n; ) {
        int idx;
        if (i < n - 2 && s[i + 2] == '#') {
            idx = (s[i] - '0') * 10 + (s[i + 1] - '0');
            *p++ = alphabets[idx];
            i += 3;
            continue;
        }
        idx = s[i] - '0';
        *p++ = alphabets[idx];
        i++;
    }
    return out;    
}

/*
Example 1:
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:
Input: s = "1326#"
Output: "acz"

Example 3:
Input: s = "25#"
Output: "y"

Example 4:
Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
*/
int main() {
    char *out;
    char *s1 = "10#11#12";
    char *s2 = "1326#";
    char *s3 = "25#";
    char *s4 = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";

    out = freqAlphabets(s1);
    printf("out = %s\n", out);
    free(out);
    out = freqAlphabets(s2);
    printf("out = %s\n", out);
    free(out);
    out = freqAlphabets(s3);
    printf("out = %s\n", out);
    free(out);
    out = freqAlphabets(s4);
    printf("out = %s\n", out);
    free(out);

    return 0;
}

