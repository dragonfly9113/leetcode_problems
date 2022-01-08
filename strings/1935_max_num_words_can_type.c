/*
1935. Maximum Number of Words You Can Type
1935_max_num_words_can_type.c

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

Example 1:
Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.

Example 2:
Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.

Example 3:
Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.

Constraints:
1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or trailing spaces.
Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.
*/
#include <stdio.h>
#include <string.h>

/*
Version 1
*/
#define MAX_NUM_LETTERS 26
int canBeTypedWords_1(char * text, char * brokenLetters){
    char broken[MAX_NUM_LETTERS] = {};
    for (char *p = brokenLetters; *p != '\0'; p++)
        broken[*p - 'a'] = 1;

    int wordCnt = 0;
    int brokenCnt = 0;
    for (char *p = text; *p != '\0'; p++) {
        if (*p == ' ') {
            if (brokenCnt == 0)
                wordCnt++;
            brokenCnt = 0;
            continue;
        }
        if (broken[*p - 'a'] == 1)
            brokenCnt++;
    }
    if (brokenCnt == 0)
        wordCnt++;
    return wordCnt;
}

/*
Version 1.1
In the second for loop, use if...else if... instead of continue.
*/
#define MAX_NUM_LETTERS 26
int canBeTypedWords_1_1(char * text, char * brokenLetters){
    char broken[MAX_NUM_LETTERS] = {};
    for (char *p = brokenLetters; *p != '\0'; p++)
        broken[*p - 'a'] = 1;

    int wordCnt = 0;
    int brokenCnt = 0;
    for (char *p = text; *p != '\0'; p++) {
        if (*p == ' ') {
            if (brokenCnt == 0)
                wordCnt++;
            brokenCnt = 0;
        } else if (broken[*p - 'a'] == 1)
            brokenCnt++;
    }
    if (brokenCnt == 0)
        wordCnt++;
    return wordCnt;
}

/*
Version 1.2
Use bit mask instead of array.
*/
int canBeTypedWords(char * text, char * brokenLetters){
    int brokenMask = 0;

    for (char *p = brokenLetters; *p != '\0'; p++)
        brokenMask |= 1 << (*p - 'a');

    int wordCnt = 0;
    int letterMask = 0;
    for (char *p = text; *p != '\0'; p++) {
        if (*p == ' ') {
            if ((letterMask & brokenMask) == 0)
                wordCnt++;
            letterMask = 0;
        } else
            letterMask |= 1 << (*p - 'a');
    }
    if ((letterMask & brokenMask) == 0)
        wordCnt++;
    return wordCnt;
}

/*
Example 1:
Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.

Example 2:
Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.

Example 3:
Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
*/
int main() {
    char *text1 = "hello world";
    char *brokenLetters1 = "ad";
    char *text2 = "leet code";
    char *brokenLetters2 = "lt";
    char *text3 = "leet code";
    char *brokenLetters3 = "e";

    printf("ans = %d\n", canBeTypedWords(text1, brokenLetters1));
    printf("ans = %d\n", canBeTypedWords(text2, brokenLetters2));
    printf("ans = %d\n", canBeTypedWords(text3, brokenLetters3));

    return 0;
}



