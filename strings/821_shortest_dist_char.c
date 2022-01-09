/*
821. Shortest Distance to a Character
821_shortest_dist_char.c

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.

Example 2:
Input: s = "aaab", c = "b"
Output: [3,2,1,0]

Constraints:
1 <= s.length <= 10^4
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1

Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
*/
int* shortestToChar_1(char * s, char c, int* returnSize){
    int n = strlen(s);

    int *ans = calloc(n, sizeof(int));
    if (!ans) {
        printf("ans is NULL, calloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        int minDist = n - 1;
        for (int j = 0; j < n; j++) {
            int d;
            if (s[j] == c && (d = abs(j - i)) < minDist)
                minDist = d;
        }
        ans[i] = minDist;
    }

    *returnSize = n;
    return ans;    
}

/*
Version 1.1
Add an array of indices of c occurences to save some time.
*/
int* shortestToChar_1_1(char * s, char c, int* returnSize){
    int n = strlen(s);

    int *ans = calloc(n, sizeof(int));
    if (!ans) {
        printf("ans is NULL, calloc() failed!\n");
        exit(1);
    }

    int *cIndices = calloc(n, sizeof(int));
    if (!cIndices) {
        printf("cIndices is NULL, calloc() failed!\n");
        exit(1);
    }

    int cCnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == c)
            cIndices[cCnt++] = i;

    for (int i = 0; i < n; i++) {
        int minDist = n - 1;
        for (int j = 0; j < cCnt; j++) {
            int d = abs(cIndices[j] - i);
            if (d < minDist)
                minDist = d;
        }
        ans[i] = minDist;
    }

    free(cIndices);
    *returnSize = n;
    return ans;
}

/*
Version 2
O(n) time instead of O(n^2) time.
Notice that fact that for each char in s, the shortest dist to c is smaller one between the dist to the closest c to its left and the closest c to its right.
Thus we can figure out ans[] by two for loop passes:
1. Firstly do a forward pass to find out, for each char in s, the distance between it and the closest c to its left.
2. Secondly do a backward pass to find out, for each char in s, the smaller distance between it and the closest c to its right and left.
*/
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
int* shortestToChar(char * s, char c, int* returnSize){
    int n = strlen(s);

    int *ans = calloc(n, sizeof(int));
    if (!ans) {
        printf("ans is NULL, calloc() failed!\n");
        exit(1);
    }

    int pos = -n;   // pos is used to record the position of the closest c to the left.
    for (int i = 0; i < n; i++) {
        if (s[i] == c)
            pos = i;
        ans[i] = i - pos;
    }

    // here pos is used to record the position of the closest c to the right.
    for (int i = pos - 1; i >= 0; i--) {
        if (s[i] == c)
            pos = i;
        ans[i] = MIN(ans[i], pos - i);
    }

    *returnSize = n;
    return ans;
}

/*
Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]

Example 2:
Input: s = "aaab", c = "b"
Output: [3,2,1,0]
*/
int main() {
    int returnSize;
    int *ans;
    char *s1 = "loveleetcode";
    char c1 = 'e';
    char *s2 = "aaab";
    char c2 = 'b';

    ans = shortestToChar(s1, c1, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);
    printf("\n");
    free(ans);

    ans = shortestToChar(s2, c2, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);
    printf("\n");
    free(ans);

    return 0;
}


