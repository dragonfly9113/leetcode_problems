/*
1002. Find Common Characters
1002_find_common_chars.c

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
*/
#define MAX_LEN_LETTERS 26
#define MAX_NUM_WORDS 100
#define MAX_NUM_CHARS 100
char ** commonChars_1(char ** words, int wordsSize, int* returnSize){
    int hashMaps[MAX_NUM_WORDS][MAX_LEN_LETTERS] = {{}};

    char **out = (char **)calloc(MAX_NUM_CHARS, sizeof(char *));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }
    for (int i = 0; i < MAX_NUM_CHARS; i++) {
        out[i] = (char *)calloc(2, sizeof(char));     // If using size = 1 here, online tester reports buffer overflow. I'm not sure why.
        if (!out[i]) {
            printf("out[%d] is NULL, calloc() failed!\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < wordsSize; i++)
        for (char *p = words[i]; *p != '\0'; p++)
            hashMaps[i][*p - 'a']++;

    int cnt = 0;
    for (char *p = words[0]; *p != '\0'; p++) {
        int i;
        for (i = 1; i < wordsSize; i++) {
            if (hashMaps[i][*p - 'a'] == 0)
                break;
            hashMaps[i][*p - 'a']--;
        }
        if (i < wordsSize)
            continue;
        out[cnt][0] = *p;
        cnt++;
    }
    *returnSize = cnt;
    return out;
}

/*
Version 1.1

Instead of returning char ** out, pass in out as a 2D array as a parameter. This way we can avoid the hassle of dynamic allocations and thus make it simpler.
But this version will not work in online tester as its signature doesn't comply to the requirement.
*/
#define MAX_LEN_LETTERS 26
#define MAX_NUM_WORDS 100
#define MAX_NUM_CHARS 100
void commonChars_1_1(char ** words, int wordsSize, int* returnSize, char out[][1]){
    int hashMaps[MAX_NUM_WORDS][MAX_LEN_LETTERS] = {{}};

    for (int i = 0; i < wordsSize; i++)
        for (char *p = words[i]; *p != '\0'; p++)
            hashMaps[i][*p - 'a']++;

    int cnt = 0;
    for (char *p = words[0]; *p != '\0'; p++) {
        int i;
        for (i = 1; i < wordsSize; i++) {
            if (hashMaps[i][*p - 'a'] == 0)
                break;
            hashMaps[i][*p - 'a']--;
        }
        if (i < wordsSize)
            continue;
        out[cnt][0] = *p;
        cnt++;
    }
    *returnSize = cnt;
}

int main_1_1() {
    char *words1[] = {"bella", "label", "roller"};
    int wordsSize1 = sizeof(words1) / sizeof(char *);
    char *words2[] = {"cool", "lock", "cook"};
    int wordsSize2 = sizeof(words2) / sizeof(char *);
    int returnSize;
    char out[MAX_NUM_CHARS][1] = {{}};

    commonChars_1_1((char **)words1, wordsSize1, &returnSize, out);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%c ", out[i][0]);
    printf("\n");

    commonChars_1_1((char **)words2, wordsSize2, &returnSize, out);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%c ", out[i][0]);
    printf("\n");

    return 0;
}

/*
Version 2

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
*/
#define MAX_LEN_LETTERS 26
#define MAX_NUM_WORDS 100
#define MAX_NUM_CHARS 100
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int hashMaps[MAX_NUM_WORDS][MAX_LEN_LETTERS] = {{}};

    char **out = (char **)calloc(MAX_NUM_CHARS, sizeof(char *));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }
    for (int i = 0; i < MAX_NUM_CHARS; i++) {
        out[i] = (char *)calloc(2, sizeof(char));     // If using size = 1 here, online tester reports buffer overflow. I'm not sure why.
        if (!out[i]) {
            printf("out[%d] is NULL, calloc() failed!\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < wordsSize; i++)
        for (char *p = words[i]; *p != '\0'; p++)
            hashMaps[i][*p - 'a']++;

    int cnt = 0;
    for (char *p = words[0]; *p != '\0'; p++) {
        int i;
        for (i = 1; i < wordsSize; i++) {
            if (hashMaps[i][*p - 'a'] == 0)
                break;
            hashMaps[i][*p - 'a']--;
        }
        if (i < wordsSize)
            continue;
        out[cnt][0] = *p;
        cnt++;
    }
    *returnSize = cnt;
    return out;
}


/*
Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
*/
int main() {
    char ** out;
    int returnSize;
    char *words1[] = {"bella", "label", "roller"};
    int wordsSize1 = sizeof(words1) / sizeof(char *);
    char *words2[] = {"cool", "lock", "cook"};
    int wordsSize2 = sizeof(words2) / sizeof(char *);

    out = commonChars((char **)words1, wordsSize1, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%c ", out[i][0]);
    printf("\n");
    for (int i = 0; i < MAX_NUM_CHARS; i++)
        free(out[i]);
    free(out);

    out = commonChars((char **)words2, wordsSize2, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%c ", out[i][0]);
    printf("\n");
    for (int i = 0; i < MAX_NUM_CHARS; i++)
        free(out[i]);
    free(out);

    return 0;
}



