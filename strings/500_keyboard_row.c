/*
500. Keyboard Row
500_keyboard_row.c

Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

Example 2:
Input: words = ["omk"]
Output: []

Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]

Constraints:
1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Version 1

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
*/
#define MAX_NUM_WORDS 20
#define MAX_LEN_WORD 101
#define MAX_NUM_ASCII 128
char ** findWords(char ** words, int wordsSize, int* returnSize){
    char ** out;
    char *row1 = "qwertyuiopQWERTYUIOP";
    char *row2 = "asdfghjklASDFGHJKL";
    char *row3 = "zxcvbnmZXCVBNM";
    char rowMap1[MAX_NUM_ASCII] = {};
    char rowMap2[MAX_NUM_ASCII] = {};
    char rowMap3[MAX_NUM_ASCII] = {};

    for (char *p = row1; *p != '\0'; p++)
        rowMap1[*p]++;
    for (char *p = row2; *p != '\0'; p++)
        rowMap2[*p]++;
    for (char *p = row3; *p != '\0'; p++)
        rowMap3[*p]++;

    out = (char **)calloc(MAX_NUM_WORDS, sizeof(char *));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        out[i] = (char *)calloc(MAX_LEN_WORD, sizeof(char));
        if (!out[i]) {
            printf("out[%d] is NULL, calloc() failed!\n", i);
            exit(1);
        }
    }

    int cnt = 0;
    for (int i = 0; i < wordsSize; i++) {
        bool useRow1 = false, useRow2 = false, useRow3 = false;
        for (char *p = words[i]; *p != '\0'; p++) {
            if (rowMap1[*p] == 1)
                useRow1 = true;
            else if (rowMap2[*p] == 1)
                useRow2 = true;
            else
                useRow3 = true;
        }
        if (useRow1 && !useRow2 && !useRow3 || !useRow1 && useRow2 && !useRow3 || !useRow1 && !useRow2 && useRow3)
            strcpy(out[cnt++], words[i]);
    }
    *returnSize = cnt;
    return out;
}

/*
Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

Example 2:
Input: words = ["omk"]
Output: []

Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
*/
int main() {
    char ** out;
    int returnSize;
    char *words1[] = {"Hello", "Alaska", "Dad", "Peace"};
    int wordsSize1 = sizeof(words1) / sizeof(char *);
    char *words2[] = {"omk"};
    int wordsSize2 = sizeof(words2) / sizeof(char *);
    char *words3[] = {"adsdf", "sfd"};
    int wordsSize3 = sizeof(words3) / sizeof(char *);

    out = findWords(words1, wordsSize1, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%s\n", out[i]);
    for (int i = 0; i < MAX_NUM_WORDS; i++)
        free(out[i]);
    free(out);    

    out = findWords(words2, wordsSize2, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%s\n", out[i]);
    for (int i = 0; i < MAX_NUM_WORDS; i++)
        free(out[i]);
    free(out);    

    out = findWords(words3, wordsSize3, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%s\n", out[i]);
    for (int i = 0; i < MAX_NUM_WORDS; i++)
        free(out[i]);
    free(out);    

    return 0;
}



