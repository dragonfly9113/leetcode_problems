/*
1816. Truncate Sentence
1816_truncate_sentence.c

A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).
For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.

Example 1:
Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"
Explanation:
The words in s are ["Hello", "how" "are", "you", "Contestant"].
The first 4 words are ["Hello", "how", "are", "you"].
Hence, you should return "Hello how are you".

Example 2:
Input: s = "What is the solution to this problem", k = 4
Output: "What is the solution"
Explanation:
The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
The first 4 words are ["What", "is", "the", "solution"].
Hence, you should return "What is the solution".

Example 3:
Input: s = "chopper is not a tanuki", k = 5
Output: "chopper is not a tanuki"

Constraints:
1 <= s.length <= 500
k is in the range [1, the number of words in s].
s consist of only lowercase and uppercase English letters and spaces.
The words in s are separated by a single space.
There are no leading or trailing spaces.
*/
#include <stdio.h>
#include <string.h>

/*
Version 1
Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"
*/
char * truncateSentence(char * s, int k) {
    int cnt = 0;

    for (char *p = s; *p != '\0'; p++)
        if (*p == ' ' && ++cnt == k) {
            *p = '\0';
            break;
        }

    return s;
}

/*
Example 1:
Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"
Explanation:
The words in s are ["Hello", "how" "are", "you", "Contestant"].
The first 4 words are ["Hello", "how", "are", "you"].
Hence, you should return "Hello how are you".

Example 2:
Input: s = "What is the solution to this problem", k = 4
Output: "What is the solution"
Explanation:
The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
The first 4 words are ["What", "is", "the", "solution"].
Hence, you should return "What is the solution".

Example 3:
Input: s = "chopper is not a tanuki", k = 5
Output: "chopper is not a tanuki"
*/
int main() {
    char s1[] = "Hello how are you Contestant";
    char s2[] = "What is the solution to this problem";
    char s3[] = "chopper is not a tanuki";
    int k1 = 4, k2 = 4, k3 = 5;
    char *out;

    out = truncateSentence(s1, k1);
    printf("out = %s\n", out);
    out = truncateSentence(s2, k2);
    printf("out = %s\n", out);
    out = truncateSentence(s3, k3);
    printf("out = %s\n", out);

    return 0;
}

