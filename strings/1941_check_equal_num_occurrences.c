/*
1941. Check if All Characters Have Equal Number of Occurrences
1941_check_equal_num_occurrences.c

Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Version 1

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
*/
#define MAX_NUM_LETTERS 26
bool areOccurrencesEqual_1(char * s){
    int freqTbl[MAX_NUM_LETTERS] = {0};

    for (char *sc = s; *sc != '\0'; sc++)
        ++freqTbl[*sc - 'a'];

    int cnt = 0, i;
    for (i = 0; i < MAX_NUM_LETTERS; i++) {
        if (freqTbl[i] > 0 && cnt == 0)
            cnt = freqTbl[i];
        if (freqTbl[i] > 0 && cnt != freqTbl[i] )
            break;
    }
    return i == MAX_NUM_LETTERS;
}

/*
Version 1.1 - Not OK! 
The for loop will NOT check all entries in freqTble and will end prematurely!
This function will always return false!
*/
#define MAX_NUM_LETTERS 26
bool areOccurrencesEqual_1_1(char * s){
    int freqTbl[MAX_NUM_LETTERS] = {0};

    for (char *sc = s; *sc != '\0'; sc++)
        ++freqTbl[*sc - 'a'];

    int cnt = 0, i;
    for (i = 0; i < MAX_NUM_LETTERS && freqTbl[i] > 0; i++) {
        if (cnt == 0)
            cnt = freqTbl[i];
        else if (cnt != freqTbl[i])
            break;        
    }
    return i == MAX_NUM_LETTERS;
}

/*
Version 1.2
Set the initial value of cnt in a more straightforward way. Then we only need do one check in the for loop.
*/
#define MAX_NUM_LETTERS 26
bool areOccurrencesEqual(char * s){
    int freqTbl[MAX_NUM_LETTERS] = {0};

    for (char *sc = s; *sc != '\0'; sc++)
        ++freqTbl[*sc - 'a'];

    int i;
    int cnt = freqTbl[s[0] - 'a'];
    for (i = 0; i < MAX_NUM_LETTERS; i++) {
        if (freqTbl[i] > 0 && cnt != freqTbl[i] )
            return false;
    }
    return true;
}

/*
Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
*/
int main() {
    char *s1 = "abacbc";
    char *s2 = "aaabb";
    char *s3 = "zzz";

    printf("ans = %d\n", areOccurrencesEqual(s1));
    printf("ans = %d\n", areOccurrencesEqual(s2));
    printf("ans = %d\n", areOccurrencesEqual(s3));

    return 0;
}


