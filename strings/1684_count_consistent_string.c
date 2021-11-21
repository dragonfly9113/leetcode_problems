/*
1684. Count the Number of Consistent Strings
1684_count_consistent_string.c

You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.

Example 1:
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

Constraints:
1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/

#include <stdio.h>
#include <string.h>

#define MAX_HASH_LEN 128

/*
Version 1
*/
int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int cnt = 0;
    int allowedHash[MAX_HASH_LEN] = {0};

    for (int i = 0; i < strlen(allowed); i++)
        allowedHash[allowed[i]] = 1;

    for (int i = 0; i < wordsSize; i++) {
        char *p;
        for (p = words[i]; *p != '\0'; p++)
            if (!allowedHash[*p]) 
                break;
        if (*p == '\0') cnt++;
    }

    return cnt;
}

/*
Example 1:
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
*/
int main () {
    int ans;
    char *allowed1 = "ab";
    char *words1[] = {"ad","bd","aaab","baa","badab"};
    int wordsSize1 = sizeof(words1) / sizeof(char *);

    char *allowed2 = "abc";
    char *words2[] = {"a","b","c","ab","ac","bc","abc"};
    int wordsSize2 = sizeof(words2) / sizeof(char *);

    char *allowed3 = "cad";
    char *words3[] = {"cc","acd","b","ba","bac","bad","ac","d"};
    int wordsSize3 = sizeof(words3) / sizeof(char *);

    ans = countConsistentStrings(allowed1, (char **)words1, wordsSize1);
    printf("wordsSize1 = %d, ans = %d\n", wordsSize1, ans);
    ans = countConsistentStrings(allowed2, (char **)words2, wordsSize2);
    printf("wordsSize2 = %d, ans = %d\n", wordsSize2, ans);
    ans = countConsistentStrings(allowed3, (char **)words3, wordsSize3);
    printf("wordsSize3 = %d, ans = %d\n", wordsSize3, ans);

    return 0;
}



