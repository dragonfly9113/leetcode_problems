/*
1678. Goal Parser Interpretation
1678_goal_parser.c

You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.

Example 1:
Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:
Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:
Input: command = "(al)G(al)()()G"
Output: "alGalooG"

Constraints:
1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1
Time: O(N)
Space: O(N)
*/
char * interpret_1(char * command){
    char* out = (char*) calloc(100, sizeof(char));
    if (!out) {
        printf("calloc() failed!\n");
        exit(1);
    }

    char* p = command;
    char* q = out;
    while (*p) {
        if (*p == 'G') {
            *q = 'G'; q++;
            p++;
        }
        else if (*p == '(' && *(p+1) == ')') {
            *q = 'o'; q++;
            p += 2;
        }
        else {
            *q = 'a'; q++;
            *q = 'l'; q++;
            p += 4;
        }
    }

    *q = '\0';
    return out;
}

/*
Version 2
Time: O(N)
Space: O(1)

No need to have an extra array. Just update the original array and two pointers. The pointer p is used to check pattern and the pointer q is used to update. The reason we can do this is because p will move faster than the update pointer q.
*/
char * interpret_2(char * command){
    char* p = command;
    char* q = command;

    while (*p) {
        if (*p == 'G') {
            *q = 'G'; q++;
            p++;
        }
        else if (*p == '(' && *(p+1) == ')') {
            *q = 'o'; q++;
            p += 2;
        }
        else {
            *q = 'a'; q++;
            *q = 'l'; q++;
            p += 4;
        }
    }

    *q = '\0';
    return command;
}

/*
Version 3
Time: O(N)
Space: O(1)

Similar to version 2. Simplify else if clause a little.
*/
char * interpret(char * command){
    char* p = command;
    char* q = command;

    while (*p) {
        if (*p == 'G') {
            *q = 'G'; q++;
            p++;
        }
        else if (*(p+1) == ')') {
            *q = 'o'; q++;
            p += 2;
        }
        else {
            *q = 'a'; q++;
            *q = 'l'; q++;
            p += 4;
        }
    }

    *q = '\0';
    return command;
}

/*
Example 1:
Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:
Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:
Input: command = "(al)G(al)()()G"
Output: "alGalooG"
*/
int main () {
    char c1[] = "G()(al)";
    char c2[] = "G()()()()(al)";
    char c3[] = "(al)G(al)()()G";

    char* o1 = interpret(c1);
    printf("o1 = %s\n", o1);
    //free(o1);
    char* o2 = interpret(c2);
    printf("o2 = %s\n", o2);
    //free(o2);
    char* o3 = interpret(c3);
    printf("o3 = %s\n", o3);
    //free(o3);

    return 0;
}

