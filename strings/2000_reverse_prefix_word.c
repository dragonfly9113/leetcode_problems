/*
2000. Reverse Prefix of Word
2000_reverse_prefix_word.c

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

Example 1:
Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

Example 2:
Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

Example 3:
Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".

Constraints:
1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.
*/
#include <stdio.h>
#include <string.h>

/*
Version 1

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
*/
char * reversePrefix(char * word, char ch){
    char *s1, *s2;

    s2 = strchr(word, ch);
    if (!s2)
        return word;

    for (s1 = word; s1 < s2; s1++, s2--) {
        char t = *s2;
        *s2 = *s1;
        *s1 = t;
    }
    return word;
}

/*
Example 1:
Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

Example 2:
Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

Example 3:
Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
*/
int main() {
    char word1[] = "abcdefd";
    char ch1 = 'd';
    char word2[] = "xyxzxe";
    char ch2 = 'z';
    char word3[] = "abcd";
    char ch3 = 'z';

    printf("ans = %s\n", reversePrefix(word1, ch1));
    printf("ans = %s\n", reversePrefix(word2, ch2));
    printf("ans = %s\n", reversePrefix(word3, ch3));

    return 0;
}





