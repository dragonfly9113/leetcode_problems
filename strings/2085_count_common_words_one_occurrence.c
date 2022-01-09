/*
2085. Count Common Words With One Occurrence
2085_count_common_words_one_occurrence.c

Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

Example 1:
Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.

Example 2:
Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.

Example 3:
Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".

Constraints:
1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] and words2[j] consists only of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>

/*
Version 1

Example 1:
Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
*/
int wordOccurence(char ** words, int wordsSize, char *word) {
    int cnt = 0;

    for (int i = 0; i < wordsSize; i++)
        if (!strcmp(word, words[i]))
            cnt++;
    return cnt;
}

int countWords(char ** words1, int words1Size, char ** words2, int words2Size){
    int cnt = 0;

    for (int i = 0; i < words1Size; i++)
        if (1 == wordOccurence(words1, words1Size, words1[i]) && (1 == wordOccurence(words2, words2Size, words1[i])))
            cnt++;
    return cnt;
}

/*
Version 2

This can be done more efficiently if a hash map is used. So a version in C++ or Java can do this much faster. In C, since there is no hash table in C standard library, we need to add a hash table implementation in order to use it.
*/

/*
Example 1:
Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2

Example 2:
Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.

Example 3:
Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
*/
int main() {
    char *words11[] = {"leetcode", "is", "amazing", "as", "is"};
    int words11Size = sizeof(words11) / sizeof(char *);
    char *words21[] = {"amazing", "leetcode", "is"};
    int words21Size = sizeof(words21) / sizeof(char *);

    char *words12[] = {"b", "bb", "bbb"};
    int words12Size = sizeof(words12) / sizeof(char *);
    char *words22[] = {"a", "aa", "aaa"};
    int words22Size = sizeof(words22) / sizeof(char *);

    char *words13[] = {"a", "ab"};
    int words13Size = sizeof(words13) / sizeof(char *);
    char *words23[] = {"a", "a", "a", "ab"};
    int words23Size = sizeof(words23) / sizeof(char *);

    printf("ans = %d\n", countWords(words11, words11Size, words21, words21Size));
    printf("ans = %d\n", countWords(words12, words12Size, words22, words22Size));
    printf("ans = %d\n", countWords(words13, words13Size, words23, words23Size));

    return 0;
}




