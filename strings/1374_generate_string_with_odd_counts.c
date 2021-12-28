/*
1374. Generate a String With Characters That Have Odd Counts
1374_generate_string_with_odd_counts.c

Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.
The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  

Example 1:
Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".

Example 2:
Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".

Example 3:
Input: n = 7
Output: "holasss"

Constraints:
1 <= n <= 500
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1
*/
#define MAX_STR_LEN 501
char * generateTheString(int n){
    char *out;

    out = calloc(MAX_STR_LEN, sizeof(char));
    if (!out) {
        printf("out is null. calloc() failed!\n");
        exit(1);
    }

    char *o = out;
    for (int i = 0; i < n; i++)
        *o++ = 'p';
    if (n % 2 == 0)
        *out = 'z';
    return out;
}

/*
Example 1:
Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".

Example 2:
Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".

Example 3:
Input: n = 7
Output: "holasss"
*/
int main() {
    char *out;
    int n1 = 4;
    int n2 = 2;
    int n3 = 7;

    out = generateTheString(n1);
    printf("ans = %s\n", out);
    free(out);
    out = generateTheString(n2);
    printf("ans = %s\n", out);
    free(out);
    out = generateTheString(n3);
    printf("ans = %s\n", out);
    free(out);

    return 0;
}


