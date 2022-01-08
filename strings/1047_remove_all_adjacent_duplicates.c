/*
1047. Remove All Adjacent Duplicates In String
1047_remove_all_adjacent_duplicates.c

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Version 1 : NOT OK!
Runs ok on local pc, but cannot pass online tester!
Got heap buffer overflow error in online tester.
*/
char * removeDuplicates_1(char * s) {
    int n = strlen(s);

    char *in = calloc(n + 1, sizeof(char));
    if (!in) {
        printf("in is NULL, calloc() failed!\n");
        exit(1);
    }
    char *out = calloc(n + 1, sizeof(char));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }
    strcpy(in, s);

    if (n == 1) {
        *out++ = *s;
        *out = '\0';
        return out;
    }

    char *o;
    bool flag;
    do {
        o = out;
        flag = false;
        for (int i = 0; i < n; i++) {
            if ((i == 0 && in[i] != in[i + 1]) || (i == n - 1 && in[i] != in[i - 1]) || (in[i] != in[i - 1] && in[i] != in[i + 1]))
                *o++ = in[i];
            else
                flag = true;
        }    
        *o = '\0';
        n = strlen(out);
        strcpy(in, out);
    } while (flag);

    free(in);
    return out;
}

/*
Version 2: NOT OK!
No need to use dynamic allocation, just use the original array s.
Still cannot pass the online tester! Same heap buffer overflow error!
*/
char * removeDuplicates_2(char * s) {
    int n = strlen(s);

    if (n == 1) {
        return s;
    }

    char *o;
    bool flag;
    do {
        o = s;
        flag = false;
        for (int i = 0; i < n; i++) {
            if ((i == 0 && s[i] != s[i + 1]) || (i == n - 1 && s[i] != s[i - 1]) || (s[i] != s[i - 1] && s[i] != s[i + 1]))
                *o++ = s[i];
            else
                flag = true;
        }    
        *o = '\0';
        n = strlen(s);
    } while (flag && n > 1);

    return s;
}

/*
Version 3
Use two pointers. Remove the unwanted chars by manipulating dest pointer.
Key tricks:
1. Only compare with the previous char (not the next one);
2. Do the comparison with dest pointer instead of source pointer. This is the key trick: this way we can remove the newly-created adjacent duplicates in one round.
*/
char * removeDuplicates(char * s) {
    int n = strlen(s);

    int j = 0;
    for (int i = 0; i < n; i++, j++) {
        s[j] = s[i];
        if (j > 0 && s[j] == s[j - 1])
            j -= 2;
    }
    s[j] = '\0';
    return s;
}

/*
Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"
*/
int main() {
    char *out;
    char s1[] = "abbaca";
    char s2[] = "azxxzy";

    out = removeDuplicates(s1);
    printf("out = %s\n", out);
    out = removeDuplicates(s2);
    printf("out = %s\n", out);

    return 0;
}


