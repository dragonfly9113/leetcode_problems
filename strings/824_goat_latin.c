/*
824. Goat Latin
824_goat_latin.c

You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:
If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.

Example 1:
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Example 2:
Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

Constraints:
1 <= sentence.length <= 150
sentence consists of English letters and spaces.
sentence has no leading or trailing spaces.
All the words in sentence are separated by a single space.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
Version 1

Example 1:
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
*/
#define MAX_LEN_OUT 3150
bool isVowel(char ch) {
    char c = (char)tolower(ch);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char * toGoatLatin(char * sentence){
    char *out;

    out = (char *)calloc(MAX_LEN_OUT, sizeof(char));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }

    char *o = out;
    char firstLetter;
    int cnt = 0;
    for (char *p = sentence; *p != '\0'; p++) {
        if (p == sentence || *(p - 1) == ' ') {
            firstLetter = *p;
            if (!isVowel(firstLetter))
                continue;
        }

        *o++ = *p;
        if (*p == ' ') {
            cnt++;
            o--;
            if (!isVowel(firstLetter))
                *o++ = firstLetter;
            *o++ = 'm';
            *o++ = 'a';
            for (int i = 0; i < cnt; i++)
                *o++ = 'a';
            *o++ = ' ';
        }
    }
    cnt++;
    if (!isVowel(firstLetter))
        *o++ = firstLetter;
    *o++ = 'm';
    *o++ = 'a';
    for (int i = 0; i < cnt; i++)
        *o++ = 'a';
    *o = '\0';
    return out;
}

/*
Example 1:
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Example 2:
Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
*/
int main() {
    char *out;
    char *s1 = "I speak Goat Latin";
    char *s2 = "The quick brown fox jumped over the lazy dog";

    out = toGoatLatin(s1);
    printf("%s\n", out);
    free(out);

    out = toGoatLatin(s2);
    printf("%s\n", out);
    free(out);

    return 0;
}

