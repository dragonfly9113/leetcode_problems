/*
1160. Find Words That Can Be Formed by Characters
1160_find_words_formed_by_chars.c

You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

Constraints:
1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>


/*
Version 1

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
*/
#define MAX_LEN_LETTERS 26
int countCharacters(char ** words, int wordsSize, char * chars){
    int count[MAX_LEN_LETTERS] = {};
    int tmp[MAX_LEN_LETTERS] = {};

    for (char *p = chars; *p != '\0'; p++)
        count[*p - 'a']++;

    int cnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        int n = strlen(words[i]);
        memcpy(tmp, count, MAX_LEN_LETTERS * sizeof(int));
        int j;
        for (j = 0; j < n; j++) {
            if (tmp[words[i][j] - 'a'] == 0)
                break;
            tmp[words[i][j] - 'a']--;
        }
        if (j == n)
            cnt += n;
    }
    return cnt;
}

/*
Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
*/
int main() {
    char *words1[] = {"cat", "bt", "hat", "tree"};
    int wordsSize1 = sizeof(words1) / sizeof(char *);
    char *chars1 = "atach";
    char *words2[] = {"hello", "world", "leetcode"};
    int wordsSize2 = sizeof(words2) / sizeof(char *);
    char *chars2 = "welldonehoneyr";

    printf("ans = %d\n", countCharacters(words1, wordsSize1, chars1));
    printf("ans = %d\n", countCharacters(words2, wordsSize2, chars2));

    return 0;
}


