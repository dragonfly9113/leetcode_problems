/*
557. Reverse Words in a String III
557_reverse_words_in_string_III.c

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"

Constraints:
1 <= s.length <= 5 * 10^4
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/
#include <stdio.h>
#include <string.h>


/*
Version 1
*/
char * reverseWords_1(char * s){
    char *p, *q;

    p = s;
    q = strchr(p, ' ');
    for (; q != NULL; ) {
        for (char *p1 = p, *q1 = q - 1; p1 < q1; p1++, q1--) {
            char t = *q1;
            *q1 = *p1;
            *p1 = t;
        }
        p = q + 1;
        q = strchr(p, ' ');
    }
    for (char *p1 = p, *q1 = s + strlen(s) - 1; p1 < q1; p1++, q1--) {
        char t = *q1;
        *q1 = *p1;
        *p1 = t;
    }
    return s;
}

/*
Version 1.1
Use a seperate function to handle reverse within a word.
*/
void reverse(char *p, char *q) {
    for (; p < q; p++, q--) {
        char t = *q;
        *q = *p;
        *p = t;
    }
}

char * reverseWords_1_1(char * s){
    char *p, *q;

    p = s;
    q = strchr(p, ' ');
    for (; q != NULL; ) {
        reverse(p, q - 1);
        p = q + 1;
        q = strchr(p, ' ');
    }
    reverse(p, s + strlen(s) - 1);
    return s;
}

/*
Version 1.2
No need to use strchr and strlen.
*/
char * reverseWords(char * s){
    char *p, *q;

    for (p = s, q = s; *q != '\0'; q++) {
        if (*q == ' ') {
            reverse(p, q - 1);
            p = q + 1;
        }
    }
    reverse(p, q - 1);
    return s;
}

/*
Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"
*/
int main() {
    char s1[] = "Let's take LeetCode contest";
    char s2[] = "God Ding";

    printf("ans = %s\n", reverseWords(s1));
    printf("ans = %s\n", reverseWords(s2));

    return 0;
}


