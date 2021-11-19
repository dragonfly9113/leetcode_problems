/*
1859. Sorting the Sentence
1859_sorting_sentence.c

A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

Example 1:
Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.

Example 2:
Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

Constraints:
2 <= s.length <= 200
s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
The number of words in s is between 1 and 9.
The words in s are separated by a single space.
s contains no leading or trailing spaces.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_WORDS 9
#define MAX_WORD_LEN 200

/*
Version 1
*/
char * sortSentence(char * s){
    char temp[MAX_NUM_WORDS][MAX_WORD_LEN] = {};
    int temp_word_len[MAX_NUM_WORDS] = {0};
    char* out = (char *)malloc(MAX_WORD_LEN * sizeof(char));
    int cnt = 0;

    for (char *p = s, *q = s; p - s <= strlen(s); p++) {
        if (*p != ' ' && *p != '\0') continue;
        int i = *(p - 1) - 1;
        int len = p - q - 1;
        strncpy(temp[i], q, len);
        temp_word_len[temp[i]] = len;
        cnt++;
        q = p + 1;
    }

    char* p = out;
    for (int i = 0; i < cnt; i++) {
        strncpy(p, temp[i], temp_word_len[i]);
        p += temp_word_len[i];
        *p = ' '; p++;
    }
    *(--p) = '\0';

    return out;
}

int main() {

    return 0;
}





