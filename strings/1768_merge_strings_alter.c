/*
1768. Merge Strings Alternately
1768_merge_strings_alter.c

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
*/
#define MAX_OUTPUT_LEN 201
char * mergeAlternately(char * word1, char * word2){
    char *out;

    out = calloc(MAX_OUTPUT_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }

    char *o = out;
    for (char *p = word1, *q = word2; *p != '\0' || *q != '\0'; ) {
        if (*p != '\0')
            *o++ = *p++;
        if (*q != '\0')
            *o++ = *q++;
    }
    return out;
}

/*
Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
*/
int main() {
    char *out;
    char *word11 = "abc";
    char *word21 = "pqr";
    char *word12 = "ab";
    char *word22 = "pqrs";
    char *word13 = "abcd";
    char *word23 = "pq";

    out = mergeAlternately(word11, word21);
    printf("out = %s\n", out);
    free(out);
    out = mergeAlternately(word12, word22);
    printf("out = %s\n", out);
    free(out);
    out = mergeAlternately(word13, word23);
    printf("out = %s\n", out);
    free(out);

    return 0;
}


