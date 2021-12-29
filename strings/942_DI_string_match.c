/*
942. DI String Match
942_DI_string_match.c

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

Example 1:
Input: s = "IDID"
Output: [0,4,1,3,2]

Example 2:
Input: s = "III"
Output: [0,1,2,3]

Example 3:
Input: s = "DDI"
Output: [3,2,0,1]

Constraints:
1 <= s.length <= 10^5
s[i] is either 'I' or 'D'.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Version 1

Example 1:
Input: s = "IDID"
Output: [0,4,1,3,2]
*/
int findNextInt(bool *taken, int takenSize, int start, char direction) {
    if (direction == 'I') {
        for (int i = start; i < takenSize; i++)
            if (!taken[i])
                return i;
    }
    else {
        for (int i = start; i >= 0; i--)
            if (!taken[i])
                return i;
    }
    return -1;
}

int* diStringMatch_1(char * s, int* returnSize) {
    int n = strlen(s);
    bool taken[n + 1];
    int *out;

    out = calloc(n + 1, sizeof(int));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }    

    for (int i = 0; i < n + 1; i++)
        taken[i] = false;

    int cntI = 0;
    for (char *p = s; *p != '\0'; p++)
        if (*p == 'I')
            cntI++;

    int *o = out;
    int start = n - cntI;
    taken[start] = true;
    *o++ = start;
    int next = start;
    for (char *p = s; *p != '\0'; p++) {
        next = findNextInt(taken, n + 1, next, *p);
        taken[next] = true;
        *o++ = next;
    }

    *returnSize = n + 1;
    return out;
}

/*
Version 2
Start from inside and move out.
*/
int* diStringMatch_2(char * s, int* returnSize) {
    int n = strlen(s);
    int *out;

    out = calloc(n + 1, sizeof(int));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }    

    int left, right;
    int cntD = 0;
    for (char *p = s; *p != '\0'; p++)
        if (*p == 'D')
            cntD++;
    left = right = cntD;    // from inside out

    int *o = out;
    *o++ = left;
    for (char *p = s; *p != '\0'; p++)
        *o++ = (*p == 'I' ? ++right : --left);
    
    *returnSize = n + 1;
    return out;
}

/*
Version 2.1
Start from outside and move in.
*/
int* diStringMatch(char * s, int* returnSize) {
    int n = strlen(s);
    int *out;

    out = calloc(n + 1, sizeof(int));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }    

    int left = 0, right = n;
    int *o = out;
    for (char *p = s; *p != '\0'; p++)
        *o++ = (*p == 'I' ? left++ : right--);
    *o = left;
    *returnSize = n + 1;
    return out;
}

/*
Example 1:
Input: s = "IDID"
Output: [0,4,1,3,2]

Example 2:
Input: s = "III"
Output: [0,1,2,3]

Example 3:
Input: s = "DDI"
Output: [3,2,0,1]
*/
int main() {
    int *out;
    int returnSize;
    char *s1 = "IDID";
    char *s2 = "III";
    char *s3 = "DDI";

    out = diStringMatch(s1, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", out[i]);
    printf("returnSize = %d\n", returnSize);
    free(out);

    out = diStringMatch(s2, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", out[i]);
    printf("returnSize = %d\n", returnSize);
    free(out);

    out = diStringMatch(s3, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", out[i]);
    printf("returnSize = %d\n", returnSize);
    free(out);

    return 0;
}


