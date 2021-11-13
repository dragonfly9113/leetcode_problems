/*
1221. Split a String in Balanced Strings
1221_split_in_balanced.c

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it in the maximum amount of balanced strings.
Return the maximum amount of split balanced strings.

Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Example 2:
Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Example 3:
Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Example 4:
Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'

Constraints:
1 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.
*/

#include <stdio.h>
#include <string.h>

/*
Version 1
*/
int balancedStringSplit_1(char * s){
    int rc = 0;
    int lc = 0;
    int count = 0;

    while (*s) {
        if (*s == 'R')
            rc++;
        else
            lc++;

        if (rc > 0 && lc > 0 && rc == lc) {
            rc = 0; lc = 0; 
            count++;
        }
        s++;
    }

    return count;
}

/*
Version 2
Simplify the if clause of rc == lc a little. There is no need to check rc > 0 && lc > 0.
*/
int balancedStringSplit_2(char * s){
    int rc = 0;
    int lc = 0;
    int count = 0;

    while (*s) {
        if (*s == 'R')
            rc++;
        else
            lc++;

        if (rc == lc) {
            rc = 0; lc = 0; 
            count++;
        }
        s++;
    }

    return count;
}

/*
Version 3
A more compact version. Use only one variable sum instead of rc and lc.
*/
int balancedStringSplit(char * s){
    int sum = 0;
    int count = 0;

    for ( ; *s; s++) {
        sum += ((*s == 'R') ? 1 : -1);
        if (sum == 0) count++;
    }

    return count;
}

/*
Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Example 2:
Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Example 3:
Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Example 4:
Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
*/
int main() {
    char s1[] = "RLRRLLRLRL";
    char s2[] = "RLLLLRRRLR";
    char s3[] = "LLLLRRRR";
    char s4[] = "RLRRRLLRLL";

    int count = 0;
    count = balancedStringSplit(s1);
    printf("count = %d\n", count);
    
    count = balancedStringSplit(s2);
    printf("count = %d\n", count);
    
    count = balancedStringSplit(s3);
    printf("count = %d\n", count);
    
    count = balancedStringSplit(s4);
    printf("count = %d\n", count);

    return 0;
}

