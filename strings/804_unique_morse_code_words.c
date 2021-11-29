/*
804. Unique Morse Code Words
804_unique_morse_code_words.c

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.

Example 1:
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

Example 2:
Input: words = ["a"]
Output: 1

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 12
words[i] consists of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORDS_LEN 100
#define MAX_TRANS_LEN 50

/*
Version 1

For function uniqueMorseRepresentations(), words can be passed in as char ** since it is defined as an array of pointers in the main():
    char *words1[] = {"gin", "zen", "gig", "msg"};
While for function checkUnique(), uniqueTrans can NOT be passed in as char ** since it is defined as a 2D array in the calling function uniqueMorseRepresentations():
    char uniqueTransforms[MAX_WORDS_LEN][MAX_TRANS_LEN] = {{}};
The thing about 2D array is that it is easy to define and initialize in the calling funciton but it can only be passed to another function as 2D array (all array bounds execept for the first dimension have to be provided). This will make the function signature of checkUnique() not flexible: it can only accept a 2D array parameter with specific dimension!
*/
bool checkUnique_1(char *newTrans, char uniqueTrans[][MAX_TRANS_LEN], int cnt) {
    for (int i = 0; i < cnt; i++)
        if (!strcmp(newTrans, uniqueTrans[i])) 
            return false;
    return true;
}

int uniqueMorseRepresentations_1(char ** words, int wordsSize){
    int cnt = 0;
    char newTransform[MAX_TRANS_LEN] = {};
    char uniqueTransforms[MAX_WORDS_LEN][MAX_TRANS_LEN] = {{}};
    char *morseTbl[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    for (int i = 0; i < wordsSize; i++) {
        for (char *p = words[i], *q = newTransform; *p != '\0'; p++) {
            strcpy(q, morseTbl[*p - 'a']);
            q += strlen(morseTbl[*p - 'a']);
        }

        if (checkUnique_1(newTransform, uniqueTransforms, cnt)) {
            strcpy(uniqueTransforms[cnt], newTransform);
            cnt++;
        }
    }
    return cnt;
}

/*
Version 2
Another way is to avoid defining a seperate function checkUnique() and thus avoid passing uniqueTransforms as a 2D array. But we need a new flag isUnique.
*/
int uniqueMorseRepresentations_2(char ** words, int wordsSize){
    int cnt = 0;
    char newTransform[MAX_TRANS_LEN] = {};
    char uniqueTransforms[MAX_WORDS_LEN][MAX_TRANS_LEN] = {{}};
    char *morseTbl[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    for (int i = 0; i < wordsSize; i++) {
        for (char *p = words[i], *q = newTransform; *p != '\0'; p++) {
            strcpy(q, morseTbl[*p - 'a']);
            q += strlen(morseTbl[*p - 'a']);
        }

        bool isUnique = true;
        for (int i = 0; i < cnt; i++)
            if (!strcmp(newTransform, uniqueTransforms[i])) {
                isUnique = false;
                break;
            }
        if (isUnique)
            strcpy(uniqueTransforms[cnt++], newTransform);
    }
    return cnt;
}

/*
Version 3
Define uniqueTransforms as an array of pointers and then allocate storage dynamically for each pointer. This way it can be passed to checkUnique_3() as char ** type. This way we also don't need to allocate a big chunk of memory upfront (50 * 1000 = 5000 bytes) as in the case of 2D array. The storage for each entry in uniqueTransforms is allocated dynamically if in need.
*/
bool checkUnique_3(char *newTrans, char **uniqueTrans, int cnt) {
    for (int i = 0; i < cnt; i++)
        if (!strcmp(newTrans, uniqueTrans[i])) 
            return false;
    return true;
}

int uniqueMorseRepresentations(char ** words, int wordsSize){
    int cnt = 0;
    char newTransform[MAX_TRANS_LEN] = {};
    char *uniqueTransforms[MAX_WORDS_LEN] = {};

    char *morseTbl[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    for (int i = 0; i < wordsSize; i++) {
        for (char *p = words[i], *q = newTransform; *p != '\0'; p++) {
            strcpy(q, morseTbl[*p - 'a']);
            q += strlen(morseTbl[*p - 'a']);
        }

        if (checkUnique_3(newTransform, (char **)uniqueTransforms, cnt)) {
            char *p = (char *)malloc(MAX_TRANS_LEN * sizeof(char));
            if (!p) {
                printf("malloc() failed in checkUnique_3()!\n");
                exit(1);
            }
            strcpy(p, newTransform);
            uniqueTransforms[cnt++] = p;
        }
    }
    for (int i = 0; i < cnt; i++)
        free(uniqueTransforms[i]);

    return cnt;
}

/*
Example 1:
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

Example 2:
Input: words = ["a"]
Output: 1
*/
int main() {
    int ans;
    char *words1[] = {"gin", "zen", "gig", "msg"};
    int wordsSize1 = sizeof(words1) / sizeof(char *);
    char *words2[] = {"a"};
    int wordsSize2 = sizeof(words2) / sizeof(char *);

    printf("wordsSize = %d\n", wordsSize1);
    ans = uniqueMorseRepresentations((char **)words1, wordsSize1);
    printf("ans = %d\n", ans);
    printf("wordsSize = %d\n", wordsSize2);
    ans = uniqueMorseRepresentations((char **)words2, wordsSize2);
    printf("ans = %d\n", ans);

    return 0;
}



