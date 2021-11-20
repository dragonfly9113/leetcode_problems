/*
1614. Maximum Nesting Depth of the Parentheses
1614_max_nesting_parentheses.c

A string is a valid parentheses string (denoted VPS) if it meets one of the following:
It is an empty string "", or a single character not equal to "(" or ")",
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.

We can similarly define the nesting depth depth(S) of any VPS S as follows:
depth("") = 0
depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS represented as string s, return the nesting depth of s.
Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3

Example 3:
Input: s = "1+(2*3)/(2-1)"
Output: 1

Example 4:
Input: s = "1"
Output: 0

Constraints:
1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1
*/
int maxDepth_1(char * s){
    int max = 0, pCnt = 0;

    for (char *p = s; *p != '\0'; p++) {
        if (*p != '(' && *p != ')')
            continue;

        if (*p == '(') {
            pCnt++;            
            if (max < pCnt) max = pCnt;
        }
        else
            pCnt--;
    }

    if (pCnt != 0) {
        printf("pCnt is not equal to 0, s is not VPS?\n");
        exit(1);
    }

    return max;
}

/*
Version 2
A little more compact code.
*/
int maxDepth(char * s){
    int max = 0, pCnt = 0;

    for (char *p = s; *p != '\0'; p++) {
        if (*p == '(') {
            pCnt++;            
            if (max < pCnt) max = pCnt;
        }
        else if (*p == ')')
            pCnt--;
    }

    if (pCnt != 0) {
        printf("pCnt is not equal to 0, s is not VPS?\n");
        exit(1);
    }

    return max;
}

/*
Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3

Example 3:
Input: s = "1+(2*3)/(2-1)"
Output: 1

Example 4:
Input: s = "1"
Output: 0
*/
int main() {
    int depth;
    char *s1 = "(1+(2*3)+((8)/4))+1";
    char *s2 = "(1)+((2))+(((3)))";
    char *s3 = "1+(2*3)/(2-1)";
    char *s4 = "1";

    depth = maxDepth(s1);
    printf("depth = %d\n", depth);
    depth = maxDepth(s2);
    printf("depth = %d\n", depth);
    depth = maxDepth(s3);
    printf("depth = %d\n", depth);
    depth = maxDepth(s4);
    printf("depth = %d\n", depth);

    return 0;
}

