/*
1967. Number of Strings That Appear as Substrings in Word
1967_number_of_substrings_word.c

Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.

Example 2:
Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.

Example 3:
Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".

Constraints:
1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] and word consist of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>

/*
Version 1
*/
int numOfStrings_1(char ** patterns, int patternsSize, char * word){
     int cnt = 0;

    for (int i = 0; i < patternsSize; i++)
        if (strstr(word, patterns[i])) cnt++;

    return cnt;
}

/*
Version 2 - Not OK!
It doesn't work for the following test case:
Input:
["hvzoo","r","hyjcrgzr","yvqahvz","org","yvqahvz","org","oor","gxe","zo","ahvzoo","ahvzo","r","o","caviikty","pkxlcaams"]
"tyvqahvzoorg"
Output:
10
Expected:
12
*/
char *myStrstr(const char * big, const char * little) {
    const char *q = big, *l = little;
    for (const char *p = big; *p != '\0'; p++) {
        if (*p == *l) {
            if (l == little) q = p;
            if (*++l == '\0') return (char *)q;
        } else {
            l = little;
        }
    }
    return NULL;
}

int numOfStrings_2(char ** patterns, int patternsSize, char * word){
    int cnt = 0;
    for (int i = 0; i < patternsSize; i++)
        if (myStrstr(word, patterns[i])) cnt++;

    return cnt;
}

/*
Version 3
Use string lib functions based on P. J. Plauger implementation.
*/
char *my_strchr(const char *s, int c) {
    const char ch = c;

    for (; *s != ch; s++)
        if (*s == '\0')
            return (NULL);
    return ((char *)s);
}

char *my_strstr(const char *s1, const char *s2) {
    if (*s2 == '\0')
        return ((char *)s1);
    for (; (s1 = my_strchr(s1, *s2)) != NULL; ++s1) {
        for (const char *sc1 = s1, *sc2 = s2; ; ) {
            if (*++sc2 == '\0')
                return (char *)s1;
            else if (*++sc1 != *sc2)
                break;
        }
    }
    return NULL;
}

int numOfStrings(char ** patterns, int patternsSize, char * word){
    int cnt = 0;
    for (int i = 0; i < patternsSize; i++)
        if (my_strstr(word, patterns[i])) 
            cnt++;

    return cnt;
}

/*
Example 1:
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.

Example 2:
Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.

Example 3:
Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".
*/
int main() {
    char *patterns1[] = {"a","abc","bc","d"};
    int patternsSize1 = sizeof(patterns1) / sizeof(char *);
    char *word1 = "abc";
    char *patterns2[] = {"a","b","c"};
    int patternsSize2 = sizeof(patterns2) / sizeof(char *);
    char *word2 = "aaaaabbbbb";
    char *patterns3[] = {"a","a","a"};
    int patternsSize3 = sizeof(patterns3) / sizeof(char *);
    char *word3 = "ab";
    char *patterns4[] = {"hvzoo","r","hyjcrgzr","yvqahvz","org","yvqahvz","org","oor","gxe","zo","ahvzoo","ahvzo","r","o","caviikty","pkxlcaams"};
    int patternsSize4 = sizeof(patterns4) / sizeof(char *);
    char *word4 = "tyvqahvzoorg";
    int ans;

    ans = numOfStrings((char **)patterns1, patternsSize1, word1);
    printf("ans = %d\n", ans);
    ans = numOfStrings((char **)patterns2, patternsSize2, word2);
    printf("ans = %d\n", ans);
    ans = numOfStrings((char **)patterns3, patternsSize3, word3);
    printf("ans = %d\n", ans);
    ans = numOfStrings((char **)patterns4, patternsSize4, word4);
    printf("ans = %d\n", ans);

    for (int i = 0; i < patternsSize4; i++) {
        printf("p[%d] = %s\n", i, myStrstr(word4, patterns4[i]));
    }

    return 0;
}

