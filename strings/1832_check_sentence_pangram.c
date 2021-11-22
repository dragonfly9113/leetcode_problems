/*
1832. Check if the Sentence Is Pangram
1832_check_sentence_pangram.c

A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:
Input: sentence = "leetcode"
Output: false

Constraints:
1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_ENG_LETTER 26

/*
Version 1
*/
bool checkIfPangram_1(char * sentence){
    int engLetters[NUM_ENG_LETTER] = {0};

    for (int i = 0; i < strlen(sentence); i++)
        engLetters[sentence[i] - 'a'] = 1;

    for (int i = 0; i < NUM_ENG_LETTER; i++)
        if (engLetters[i] == 0) return false;

    return true;
}

/*
Version 2
Just use one loop.
*/
bool checkIfPangram(char * sentence){
    int cnt = 0;
    int engLetters[NUM_ENG_LETTER] = {0};

    for (int i = 0; i < strlen(sentence); i++) {
        int idx = sentence[i] - 'a';
        if (!engLetters[idx]) cnt++;
        engLetters[idx] = 1;
    }
        
    return (cnt == NUM_ENG_LETTER ? true : false);
}

/*
Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:
Input: sentence = "leetcode"
Output: false
*/
int main() {
    bool ans;
    char *s1 = "thequickbrownfoxjumpsoverthelazydog";
    char *s2 = "leetcode";

    ans = checkIfPangram(s1);
    printf("ans = %s\n", ans ? "true" : "false");
    ans = checkIfPangram(s2);
    printf("ans = %s\n", ans ? "true" : "false");

    return 0;
}


