/*
1704. Determine if String Halves Are Alike
1704_if_string_halves_alike.c

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.

Example 3:
Input: s = "MerryChristmas"
Output: false

Example 4:
Input: s = "AbCdEfGh"
Output: true

Constraints:
2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
Version 1
*/
bool halvesAreAlike_1(char * s){
    char *vowels = "aeiouAEIOU";
    int n = strlen(s);
    const char *s1, *s2;
    int cnt1 = 0, cnt2 = 0;

    s1 = s;
    for (int i = 0; i < n/2; i++, s1++) {
        for (char *p = vowels; *p != '\0'; p++)
            if (*p == *s1) {
                cnt1++;
                break;
            }
    }
    for (s2 = s + n/2; *s2 != '\0'; s2++) {
        for (char *p = vowels; *p != '\0'; p++)
            if (*p == *s2) {
                cnt2++;
                break;
            }
    }
    return (cnt1 == cnt2);
}

/*
Version 2
Use an array to check if a character is vowel instead of for loop.
*/
#define MAX_ASCII_NUM 128
bool halvesAreAlike_2(char * s){
    bool vowels[MAX_ASCII_NUM] = {};
    int n = strlen(s);
    const char *s1, *s2;
    int cnt1 = 0, cnt2 = 0;

    vowels['A'] = true;
    vowels['E'] = true;
    vowels['I'] = true;
    vowels['O'] = true;
    vowels['U'] = true;
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;

    s1 = s;
    for (int i = 0; i < n/2; i++, s1++) {
        if (vowels[*s1])
            cnt1++;
    }
    for (s2 = s + n/2; *s2 != '\0'; s2++) {
        if (vowels[*s2])
            cnt2++;
    }
    return (cnt1 == cnt2);
}

/*
Version 2.1
Based on version 2. Use a seperate function to check if a char is a vowel.
*/
bool isVowel(char c) {
    bool vowels[MAX_ASCII_NUM] = {};

    vowels['A'] = true;
    vowels['E'] = true;
    vowels['I'] = true;
    vowels['O'] = true;
    vowels['U'] = true;
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;

    return vowels[c];
}

bool halvesAreAlike_2_1(char * s){
    int n = strlen(s);
    const char *s1, *s2;
    int cnt1 = 0, cnt2 = 0;

    s1 = s;
    for (int i = 0; i < n/2; i++, s1++) {
        if (isVowel(*s1))
            cnt1++;
    }
    for (s2 = s + n/2; *s2 != '\0'; s2++) {
        if (isVowel(*s2))
            cnt2++;
    }
    return (cnt1 == cnt2);
}

/*
Version 3
Only use one for loop and one counter.
*/
bool halvesAreAlike_3(char * s){
    bool vowels[MAX_ASCII_NUM] = {};
    int n = strlen(s);
    int cnt = 0;

    vowels['A'] = true;
    vowels['E'] = true;
    vowels['I'] = true;
    vowels['O'] = true;
    vowels['U'] = true;
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;

    for (int i = 0, j = n/2; i < n/2; i++, j++) {
        if (vowels[s[i]])
            cnt++;
        if (vowels[s[j]])
            cnt--;
    }
    return (cnt == 0);
}

/*
Version 4
With help of tolower(), can just use simple ORs to check if a character is a vowel.
Or can just use simple ORs w/o help of tolower(), better to add a seperate function in this case.
*/
bool halvesAreAlike(char * s){
    int n = strlen(s);
    int cnt = 0;

    for (int i = 0, j = n/2; i < n/2; i++, j++) {
        char ch = tolower(s[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cnt++;
        ch = tolower(s[j]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cnt--;
    }
    return (cnt == 0);
}

/*
Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.

Example 3:
Input: s = "MerryChristmas"
Output: false

Example 4:
Input: s = "AbCdEfGh"
Output: true
*/
int main() {
    char *s1 = "book";
    char *s2 = "textbook";
    char *s3 = "MerryChristmas";
    char *s4 = "AbCdEfGh";

    printf("ans = %d\n", halvesAreAlike(s1));
    printf("ans = %d\n", halvesAreAlike(s2));
    printf("ans = %d\n", halvesAreAlike(s3));
    printf("ans = %d\n", halvesAreAlike(s4));

    return 0;
}


