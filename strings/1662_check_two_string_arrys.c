/*
1662. Check If Two String Arrays are Equivalent
1662_check_two_string_arrys.c

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.

Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true

Constraints:
1 <= word1.length, word2.length <= 10^3
1 <= word1[i].length, word2[i].length <= 10^3
1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
word1[i] and word2[i] consist of lowercase letters.
*/

/*
Difference between ++*p, *p++ and *++p in C
Precedence of prefix ++ and * is same the both are right to left associative. Precedence of postfix ++ is higher than both prefix ++ and * and is left to right associative.

// Value of p incremented by 1 and returned
// Equal to: ++(*p)
q = ++*p;

// Value of p is returned and pointer is incremented by 1
// Equal to: *(p++)
q = *p++;

// Pointer is incremented by 1 and value returned
// Equal to: *(++p)
q = *++p;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 1000

/*
Version 1
*/
bool arrayStringsAreEqual_1(char ** word1, int word1Size, char ** word2, int word2Size){
    char str1[MAX_STR_LEN] = {}, str2[MAX_STR_LEN] = {};

    char *p = str1;
    for (int i = 0; i < word1Size; i++) {
        strcpy(p, word1[i]);
        p += strlen(word1[i]);
    }
    *p = '\0';

    p = str2;
    for (int i = 0; i < word2Size; i++) {
        strcpy(p, word2[i]);
        p += strlen(word2[i]);
    }
    *p = '\0';

    return !strcmp(str1, str2) ? true : false;
}

/*
Version 2
Just treat two string arrays as two strings and compare chars one by one. Just need to update p and q in a special way when any of them reaches the end of each word. At this point, either p or q should be updated to point to the first char of the next word.

Improvement:
1. No need to allocate str1 and str2 in stack, each array is of length 1000 chars.
2. No need to do two loops, just one loop is OK.
3. If char difference is found earlier, no need to check all chars.
4. No need to call std functions like strcpy() and strcmp().
*/
bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    char *p, *q;
    int i1 = 0, i2 = 0;

    for (p = word1[i1], q = word2[i2]; *p != '\0' && *p != '\0'; ) {
        if (*p != *q) return false;
        if (*++p == '\0') {
            i1++;
            if (i1 < word1Size) p = word1[i1];
        }
        if (*++q == '\0') {
            i2++;
            if (i2 < word2Size) q = word2[i2];
        }
    }
    if (*p == '\0' && *q == '\0') return true;
    
    return false;
}

/*
Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
*/
int main() {
    bool ret;
    char *word11[] = {"ab", "c"};
    int word11Size = sizeof(word11) / sizeof(char *);
    char *word12[] = {"a", "bc"};
    int word12Size = sizeof(word12) / sizeof(char *);

    char *word21[] = {"a", "cb"};
    int word21Size = sizeof(word21) / sizeof(char *);
    char *word22[] = {"ab", "c"};
    int word22Size = sizeof(word22) / sizeof(char *);

    char *word31[] = {"abc", "d", "defg"};
    int word31Size = sizeof(word31) / sizeof(char *);
    char *word32[] = {"abcddefg"};
    int word32Size = sizeof(word32) / sizeof(char *);

    ret = arrayStringsAreEqual((char **)word11, word11Size, (char **)word12, word12Size);
    printf("ret = %s\n", ret ? "true" : "false");
    ret = arrayStringsAreEqual((char **)word21, word21Size, (char **)word22, word22Size);
    printf("ret = %s\n", ret ? "true" : "false");
    ret = arrayStringsAreEqual((char **)word31, word31Size, (char **)word32, word32Size);
    printf("ret = %s\n", ret ? "true" : "false");

    return 0;
}



