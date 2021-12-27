/*
1370. Increasing Decreasing String
1370_increasing_decreasing_string.c

You are given a string s. Reorder the string using the following algorithm:

1. Pick the smallest character from s and append it to the result.
2. Pick the smallest character from s which is greater than the last appended character to the result and append it.
3. Repeat step 2 until you cannot pick more characters.
4. Pick the largest character from s and append it to the result.
5. Pick the largest character from s which is smaller than the last appended character to the result and append it.
6. Repeat step 5 until you cannot pick more characters.
7. Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.
Return the result string after sorting s with this algorithm.

Example 1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

Example 2:
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1: NOT OK!

Tried to use straightforward method but not sure how to do so.
*/
#define MAX_STR_LEN 501
char * sortString_1(char * s){
    int n = strlen(s);
    char *si, *sm, *sd;
    char last;

    char *out = calloc(MAX_STR_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL. calloc() failed!\n");
        exit(1);
    }

    char *o = out;
    last = 0;
    while (1) {
        for (si = s, sm = si; *si != '\0'; si++)
            if (*si >= 'a' && *si <= 'z' && *si > last && *si < *sm)
                sm = si;
        *o++ = *sm;
        last = *sm;
        *sm = 127;
    }
    return out;
}

/*
Version 2
Use an alpabet count array to help.
*/
#define MAX_NUM_LETTERS 26
char * sortString_2(char * s){
    int cnt[MAX_NUM_LETTERS] = {0};

    char *out = calloc(MAX_STR_LEN, sizeof(char));
    if (!out) {
        printf("out is null. calloc() failed!\n");
        exit(1);
    }

    for (char *p = s; *p != '\0'; p++)
        ++cnt[*p - 'a'];

    char *o = out;
    while (1) {
        for (int i = 0; i < MAX_NUM_LETTERS; i++)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }

        for (int i = MAX_NUM_LETTERS - 1; i >= 0; i--)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }    

        int sum = 0;
        for (int i = 0; i < MAX_NUM_LETTERS; i++)
            sum += cnt[i];
        if (sum == 0)
            break;
    }
    return out;
}

/*
Example 1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

Example 2:
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
*/
int main_2() {
    char *out;
    char *s1 = "aaaabbbbcccc";
    char *s2 = "rat";

    out = sortString_2(s1);
    printf("out = %s\n", out);
    free(out);

    out = sortString_2(s2);
    printf("out = %s\n", out);
    free(out);

    return 0;
}

/*
Version 2.1
No need to allocate an output buffer, just use the input s.
*/
#define MAX_NUM_LETTERS 26
char * sortString_2_1(char * s){
    int cnt[MAX_NUM_LETTERS] = {0};

    for (char *p = s; *p != '\0'; p++)
        ++cnt[*p - 'a'];

    char *o = s;
    while (1) {
        for (int i = 0; i < MAX_NUM_LETTERS; i++)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }

        for (int i = MAX_NUM_LETTERS - 1; i >= 0; i--)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }    

        int sum = 0;
        for (int i = 0; i < MAX_NUM_LETTERS; i++)
            sum += cnt[i];
        if (sum == 0)
            break;
    }
    return s;
}

/*
Version 2.2
Use a better way to check if it is done.
*/
#define MAX_NUM_LETTERS 26
char * sortString_2_2(char * s){
    int n = strlen(s);
    int cnt[MAX_NUM_LETTERS] = {0};

    for (char *p = s; *p != '\0'; p++)
        ++cnt[*p - 'a'];

    char *o = s;
    while (1) {
        for (int i = 0; i < MAX_NUM_LETTERS; i++)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }
        if (o -s >= n)
            break;

        for (int i = MAX_NUM_LETTERS - 1; i >= 0; i--)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }    
        if (o -s >= n)
            break;
    }
    return s;
}

/*
Version 2.3
A more compact way than v2.2.
*/
#define MAX_NUM_LETTERS 26
char * sortString(char * s){
    int n = strlen(s);
    int cnt[MAX_NUM_LETTERS] = {0};

    for (char *p = s; *p != '\0'; p++)
        ++cnt[*p - 'a'];

    char *o = s;
    while (o -s < n) {
        for (int i = 0; i < MAX_NUM_LETTERS; i++)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }
        for (int i = MAX_NUM_LETTERS - 1; i >= 0; i--)
            if (cnt[i] > 0) {
                *o++ = 'a' + i;
                --cnt[i];
            }    
    }
    return s;
}

/*
Example 1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

Example 2:
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
*/
int main() {
    char *out;
    char s1[] = "aaaabbbbcccc";
    char s2[] = "rat";

    out = sortString(s1);
    printf("out = %s\n", out);
    out = sortString(s2);
    printf("out = %s\n", out);

    return 0;
}



