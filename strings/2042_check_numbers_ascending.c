/*
2042. Check if Numbers Are Ascending in a Sentence
2042_check_numbers_ascending.c

A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.
For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other tokens such as "puppy" are words.
Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from left to right (i.e., other than the last number, each number is strictly smaller than the number on its right in s).
Return true if so, or false otherwise.

Example 1:
Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
Output: true
Explanation: The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.

Example 2:
Input: s = "hello world 5 x 5"
Output: false
Explanation: The numbers in s are: 5, 5. They are not strictly increasing.

Example 3:
Input: s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
Output: false
Explanation: The numbers in s are: 7, 51, 50, 60. They are not strictly increasing.

Constraints:
3 <= s.length <= 200
s consists of lowercase English letters, spaces, and digits from 0 to 9, inclusive.
The number of tokens in s is between 2 and 100, inclusive.
The tokens in s are separated by a single space.
There are at least two numbers in s.
Each number in s is a positive number less than 100, with no leading zeros.
s contains no leading or trailing spaces.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Version 1 : Not OK!

Only works for example 1, failed example 2 & 3. It is getting messy very quickly!

Example 1:
Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
Output: true
Explanation: The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.
*/
bool areNumbersAscending_1(char * s){
    char *p,*q = s;
    int pre = 0, num;
    for (p = s; *p != '\0'; p++) {
        if (*p == ' ') {
            if (*q >= 'a' && *q <= 'z') {
                q = p + 1;
                continue;
            }
            num = 0;
            for ( ; q < p; q++)
                num = num * 10 + (*q - '0');
            printf("%d\n", num);
            if (num <= pre)
                return false;
            pre = num;
            q = p + 1;
        }
    }
    if (*q >= 'a' && *q <= 'z') {
        return true;
    }
    for ( ; q < p; q++)
        num = num * 10 + (*q - '0');
    if (num <= pre)
        return false;
    else
        return true;
}


/*
Version 2

A much better and simpler approach:
1. No need to keep the second pointer q, which makes things much more complicated.
2. No need to differentiate ' ' from other non-digit chars.
*/
bool areNumbersAscending_2(char * s){
    int prev = 0, curr = 0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p >= '0' && *p <= '9')
            curr = curr * 10 + (*p - '0');
        else {
            if (curr != 0) {
                if (curr <= prev)
                    return false;
                prev = curr;
                curr = 0;
            }
        }
    }
    if (curr != 0 && curr <= prev)
        return false;
    return true;
}

/*
Version 2.1

A little bit more compact.
*/
bool areNumbersAscending(char * s){
    int prev = 0, curr = 0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p >= '0' && *p <= '9')
            curr = curr * 10 + (*p - '0');
        else if (curr != 0) {
            if (curr <= prev)
                return false;
            prev = curr;
            curr = 0;
        }
    }
    return (curr == 0 || curr > prev);
}

/*
Example 1:
Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
Output: true
Explanation: The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.

Example 2:
Input: s = "hello world 5 x 5"
Output: false
Explanation: The numbers in s are: 5, 5. They are not strictly increasing.

Example 3:
Input: s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
Output: false
Explanation: The numbers in s are: 7, 51, 50, 60. They are not strictly increasing.
*/
int main() {
    char *s1 = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    char *s2 = "hello world 5 x 5";
    char *s3 = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";

    printf("ans = %d\n", areNumbersAscending(s1));
    printf("ans = %d\n", areNumbersAscending(s2));
    printf("ans = %d\n", areNumbersAscending(s3));

    return 0;
}


