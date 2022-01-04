/*
1880. Check if Word Equals Summation of Two Words
1880_check_word_equals_summation.c

The letter value of a letter is its position in the alphabet starting from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).
The numerical value of some string of lowercase English letters s is the concatenation of the letter values of each letter in s, which is then converted into an integer.
For example, if s = "acb", we concatenate each letter's letter value, resulting in "021". After converting it, we get 21.
You are given three strings firstWord, secondWord, and targetWord, each consisting of lowercase English letters 'a' through 'j' inclusive.
Return true if the summation of the numerical values of firstWord and secondWord equals the numerical value of targetWord, or false otherwise.

Example 1:
Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
Output: true
Explanation:
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.

Example 2:
Input: firstWord = "aaa", secondWord = "a", targetWord = "aab"
Output: false
Explanation: 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.

Example 3:
Input: firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
Output: true
Explanation: 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aaaa" -> "0000" -> 0.
We return true because 0 + 0 == 0.

Constraints:
1 <= firstWord.length, secondWord.length, targetWord.length <= 8
firstWord, secondWord, and targetWord consist of lowercase English letters from 'a' to 'j' inclusive.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Version 1

Example 1:
Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
Output: true
Explanation:
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.
*/
bool isSumEqual_1(char * firstWord, char * secondWord, char * targetWord){
    int nf = strlen(firstWord);
    int ns = strlen(secondWord);
    int nt = strlen(targetWord);

    int numf = 0;
    for (int i = 0; i < nf; i++) {
        int prod = 1;
        for (int j = 0; j < nf - 1 - i; j++)
            prod *= 10;
        numf += (firstWord[i] - 'a') * prod;
    }

    int nums = 0;
    for (int i = 0; i < ns; i++) {
        int prod = 1;
        for (int j = 0; j < ns - 1 - i; j++)
            prod *= 10;
        nums += (secondWord[i] - 'a') * prod;
    }

    int numt = 0;
    for (int i = 0; i < nt; i++) {
        int prod = 1;
        for (int j = 0; j < nt - 1 - i; j++)
            prod *= 10;
        numt += (targetWord[i] - 'a') * prod;
    }

    return (numt == numf + nums);
}

/*
Version 1.1
Add a seperate function to handle atoi calculations.
*/
int my_atoi_1_1(const char *s) {
    int n = strlen(s);
    int num = 0;
    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = 0; j < n - 1 - i; j++)
            prod *= 10;
        num += (s[i] - 'a') * prod;
    }
    return num;
}

bool isSumEqual_1_1(char * firstWord, char * secondWord, char * targetWord){
    return my_atoi_1_1(targetWord) == my_atoi_1_1(firstWord) + my_atoi_1_1(secondWord);
}


/*
Version 1.2
A much better way to do atoi. No need for two for loops!
*/
int my_atoi(const char *s) {
    int num = 0;
    for (int i = 0; i < strlen(s); i++)
        num = num * 10 + s[i] - 'a';
    return num;
}

bool isSumEqual(char * firstWord, char * secondWord, char * targetWord){
    return my_atoi(targetWord) == my_atoi(firstWord) + my_atoi(secondWord);
}

/*
Example 1:
Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
Output: true
Explanation:
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.

Example 2:
Input: firstWord = "aaa", secondWord = "a", targetWord = "aab"
Output: false
Explanation: 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.

Example 3:
Input: firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
Output: true
Explanation: 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aaaa" -> "0000" -> 0.
We return true because 0 + 0 == 0.
*/
int main() {
    char *firstWord1 = "acb";
    char *secondWord1 = "cba";
    char *targetWord1 = "cdb";
    
    char *firstWord2 = "aaa";
    char *secondWord2 = "a";
    char *targetWord2 = "aab";
    
    char *firstWord3 = "aaa";
    char *secondWord3 = "a";
    char *targetWord3 = "aaaa";

    printf("ans = %d\n", isSumEqual(firstWord1, secondWord1, targetWord1));
    printf("ans = %d\n", isSumEqual(firstWord2, secondWord2, targetWord2));
    printf("ans = %d\n", isSumEqual(firstWord3, secondWord3, targetWord3));

    return 0;
}




