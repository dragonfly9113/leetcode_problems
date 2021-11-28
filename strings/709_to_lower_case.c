/*
709. To Lower Case
709_to_lower_case.c

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

Example 1:
Input: s = "Hello"
Output: "hello"

Example 2:
Input: s = "here"
Output: "here"

Example 3:
Input: s = "LOVELY"
Output: "lovely"

Constraints:
1 <= s.length <= 100
s consists of printable ASCII characters.
*/

#include <stdio.h>
#include <string.h>

/*
Verison 1
*/
char * toLowerCase(char * s){
    for (char *p = s; *p != '\0'; p++)
        if (*p >= 'A' && *p <= 'Z')
            *p += 'a' - 'A';

    return s;
}

/*
Example 1:
Input: s = "Hello"
Output: "hello"

Example 2:
Input: s = "here"
Output: "here"

Example 3:
Input: s = "LOVELY"
Output: "lovely"
*/
int main() {
    char s1[] = "Hello";

    printf("ret = %s\n", toLowerCase(s1));

}


