/*
1021. Remove Outermost Parentheses
1021_remove_outermost_parentheses.c

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

Constraints:
1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1
*/
char * removeOuterParentheses_1(char * s) {
    char *out = (char *)malloc((strlen(s) + 1) * sizeof(char));
    if (!out) {
        printf("out is null. malloc() failed!\n");
        exit(1);
    }

    char *o = out;
    int cnt = 0;
    for (char *p = s, *q = s; *p != '\0'; p++) {
        cnt += (*p == '(' ? 1 : -1);
        if (cnt == 0) {
            int len = p - q - 1;
            strncpy(o, q + 1, len);
            q = p + 1;
            o += len;
        }
    }
    *o = '\0';

    return out;
}

/*
Version 2   -   Not OK!
Try to use the input s array as output buffer also. 

This version runs OK in my local Cygwin terminal but failed in the online verifier. I got the following memory ranges overlap runtime errors:
=================================================================
==31==ERROR: AddressSanitizer: strncpy-param-overlap: memory ranges [0x602000000010,0x602000000014) and [0x602000000011, 0x602000000015) overlap
    #0 0x7f189d058630 in __interceptor_strncpy (/lib/x86_64-linux-gnu/libasan.so.5+0xba630)
    #3 0x7f189c4660b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x602000000010 is located 0 bytes inside of 11-byte region [0x602000000010,0x60200000001b)
allocated by thread T0 here:
    #0 0x7f189d0abbc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
    #3 0x7f189c4660b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x602000000011 is located 1 bytes inside of 11-byte region [0x602000000010,0x60200000001b)
allocated by thread T0 here:
    #0 0x7f189d0abbc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
    #3 0x7f189c4660b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
SUMMARY: AddressSanitizer: strncpy-param-overlap (/lib/x86_64-linux-gnu/libasan.so.5+0xba630) in __interceptor_strncpy
==31==ABORTING

In this version, it is true that the source region pointed to by q + 1 overlaps with the destination region pointed to by o. Maybe the online tester has a stronger compiler/runtime check which doesn't allow this behaviour? I can imagine this kind of strncpy-param-overlap might cause nasty unknown behvaiour in multithread program.
We should stick with version 1 which is safe.
*/
char * removeOuterParentheses_2(char * s) {
    char *o = s;
    int cnt = 0;
    for (char *p = s, *q = s; *p != '\0'; p++) {
        cnt += (*p == '(' ? 1 : -1);
        if (cnt == 0) {
            int len = p - q - 1;
            strncpy(o, q + 1, len);
            q = p + 1;
            o += len;
        }
    }
    *o = '\0';

    return s;
}

/*
Version 3
Note the values of old cnt (before update) and new cnt (after update):
s =         (()())(())
old cnt =   0121210121
new cnt =   1212101210

We can see that the value of old cnt (before update) can be used to tell the first '(' and the last ')' of a primitive parentheses string:
                old cnt
the first '('   0
the last ')'    1

We can use the above information to exclue the first '(' and the last ')' from a primitive parentheses string!
Improvements:
1. No need to keep two pointers p and q. Only one pointer p is enough.
2. No need to use strncpy() to copy a sub-string.
*/
char * removeOuterParentheses_3(char * s) {
    char *out = (char *)malloc((strlen(s) + 1) * sizeof(char));
    if (!out) {
        printf("out is null. malloc() failed!\n");
        exit(1);
    }

    char *o = out;
    int cnt = 0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '(' && cnt++ > 0 || *p == ')' && cnt-- > 1) 
            *o++ = *p;     
    }
    *o = '\0';

    return out;
}

/*
Version 4
Use the same idea as in version 3.
Improvements:
1. No need to allocate an extra storage for an output array: just use input array s for output also.
2. This is possible because we no longer use strncpy(). Now we are copying one char each time and we are sure that the source pointer p is always ahead of destination pointer o.
*/
char * removeOuterParentheses(char * s) {
    char *o = s;
    int cnt = 0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '(' && cnt++ > 0 || *p == ')' && cnt-- > 1) 
            *o++ = *p;     
    }
    *o = '\0';

    return s;
}

/* Version 1
Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
*/
int main_1() {
    char *s1 = "(()())(())";
    char *s2 = "(()())(())(()(()))";
    char *s3 = "()()";
    char *out;

    out = removeOuterParentheses(s1);
    printf("out = %s\n", out);
    free(out);
    out = removeOuterParentheses(s2);
    printf("out = %s\n", out);
    free(out);
    out = removeOuterParentheses(s3);
    printf("out = %s\n", out);
    free(out);

    return 0;
}

/*
Version 2
*/
int main() {
    char s1[] = "(()())(())";
    char s2[] = "(()())(())(()(()))";
    char s3[] = "()()";
    char *out;

    out = removeOuterParentheses(s1);
    printf("out = %s\n", out);
    out = removeOuterParentheses(s2);
    printf("out = %s\n", out);
    out = removeOuterParentheses(s3);
    printf("out = %s\n", out);

    return 0;
}


