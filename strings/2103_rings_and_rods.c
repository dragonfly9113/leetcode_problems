/*
2103. Rings and Rods
2103_rings_and_rods.c

There are n rings and each ring is either red, green, or blue. The rings are distributed across ten rods labeled from 0 to 9.
You are given a string rings of length 2n that describes the n rings that are placed onto the rods. Every two characters in rings forms a color-position pair that is used to describe each ring where:
The first character of the ith pair denotes the ith ring's color ('R', 'G', 'B').
The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').
For example, "R3G2B1" describes n == 3 rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.
Return the number of rods that have all three colors of rings on them.

Example 1:
Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation: 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.

Example 2:
Input: rings = "B0R0G0R9R0B0G0"
Output: 1
Explanation: 
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.

Example 3:
Input: rings = "G4"
Output: 0
Explanation: 
Only one ring is given. Thus, no rods have all three colors.

Constraints:
rings.length == 2 * n
1 <= n <= 100
rings[i] where i is even is either 'R', 'G', or 'B' (0-indexed).
rings[i] where i is odd is a digit from '0' to '9' (0-indexed).
*/
#include <stdio.h>
#include <string.h>

/*
Version 1
Use a 2D array to store color rings info on each rod.

Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation: 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.
*/
#define MAX_NUM_RODS 10
#define MAX_NUM_COLORS 3
int countPoints_1(char * rings){
    unsigned char rods[MAX_NUM_RODS][MAX_NUM_COLORS] = {{0}};
    const char *r;
    int cnt = 0;

    for (r = rings; *r != '\0'; ) {
        int ridx, cidx;
        if (*r == 'R')
            cidx = 0;
        else if (*r == 'G')
            cidx = 1;
        else
            cidx = 2;

        ridx = *++r - '0';
        rods[ridx][cidx] = 1;
        r++;
    }

    for (int i = 0; i < MAX_NUM_RODS; i++) {
        int num_of_colors = 0;
        for (int j = 0; j < MAX_NUM_COLORS; j++)
            num_of_colors += rods[i][j];
        if (num_of_colors == 3)
            cnt++;
    }
    return cnt;
}

/*
Version 2
A more compact version of version 1.
*/
int countPoints_2(char * rings){
    unsigned char rods[MAX_NUM_RODS][MAX_NUM_COLORS] = {{0}};
    const char *r;
    int cnt = 0;

    for (r = rings; *r != '\0'; ) {
        int ridx, cidx;
        cidx = *r == 'R' ? 0 : (*r == 'G' ? 1 : 2);
        ridx = *++r - '0';
        rods[ridx][cidx] = 1;
        r++;
    }

    for (int i = 0; i < MAX_NUM_RODS; i++) {
        int num_of_colors = 0;
        for (int j = 0; j < MAX_NUM_COLORS; j++)
            num_of_colors += rods[i][j];
        if (num_of_colors == 3)
            cnt++;
    }
    return cnt;
}

/*
Version 3
Use bit masks and bitwise operators.
*/
#define COLOR_RED   01
#define COLOR_GREEN 02
#define COLOR_BLUE  04
int countPoints_3(char * rings){
    char rods[MAX_NUM_RODS]= {};
    const char *r;
    int cnt = 0;

    for (r = rings; *r != '\0'; ) {
        int ridx;
        char color = *r;
        ridx = *++r - '0';
        if (color == 'R')
            rods[ridx] |= COLOR_RED;
        else if (color == 'G')
            rods[ridx] |= COLOR_GREEN;
        else
            rods[ridx] |= COLOR_BLUE;
        r++;
    }

    for (int i = 0; i < MAX_NUM_RODS; i++) {
        if ((rods[i] | ~(COLOR_RED | COLOR_GREEN | COLOR_BLUE)) == ~0)
            cnt++;
    }
    return cnt;
}

/*
Version 3.1
Use bit masks and bitwise operators - a more compact version based on version 3.
*/
int countPoints_3_1(char * rings){
    char rods[MAX_NUM_RODS]= {};
    const char *r;
    int cnt = 0;

    for (r = rings; *r != '\0'; ) {
        int color = *r == 'R' ? COLOR_RED : (*r == 'G' ? COLOR_GREEN : COLOR_BLUE);
        rods[*++r - '0'] |= color;
        r++;
    }

    for (int i = 0; i < MAX_NUM_RODS; i++) {
        if ((rods[i] | ~(COLOR_RED | COLOR_GREEN | COLOR_BLUE)) == ~0)
            cnt++;
    }
    return cnt;
}

/*
Version 3.2
Use bit masks and bitwise operators - an alternative way to do bit masks:
Use enum instead of #define.
*/
enum {
    CLR_RED = 01,
    CLR_GREEN = 02,
    CLR_BLUE = 04
};

int countPoints_3_2(char * rings){
    char rods[MAX_NUM_RODS]= {};
    const char *r;
    int cnt = 0;

    for (r = rings; *r != '\0'; ) {
        int color = *r == 'R' ? CLR_RED : (*r == 'G' ? CLR_GREEN : CLR_BLUE);
        rods[*++r - '0'] |= color;
        r++;
    }

    for (int i = 0; i < MAX_NUM_RODS; i++) {
        if ((rods[i] | ~(CLR_RED | CLR_GREEN | CLR_BLUE)) == ~0)
            cnt++;
    }
    return cnt;
}

/*
Version 4
Use bit-fields.
*/
struct colors {
    unsigned int is_red : 1;
    unsigned int is_green : 1;
    unsigned int is_blue : 1;
};

int countPoints(char * rings){
    struct colors rods[MAX_NUM_RODS] = {};
    const char *r;
    int cnt = 0;

    for (r = rings; *r != '\0'; ) {
        int ridx;
        char ch = *r;
        ridx = *++r - '0';
        if (ch == 'R')
            rods[ridx].is_red = 1;
        else if (ch == 'G')
            rods[ridx].is_green = 1;
        else
            rods[ridx].is_blue = 1;
        r++;
    }

    for (int i = 0; i < MAX_NUM_RODS; i++) {
        if (rods[i].is_red == 1 && rods[i].is_green == 1 && rods[i].is_blue == 1)
            cnt++;
    }
    return cnt;
}

/*
Example 1:
Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation: 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.

Example 2:
Input: rings = "B0R0G0R9R0B0G0"
Output: 1
Explanation: 
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.

Example 3:
Input: rings = "G4"
Output: 0
Explanation: 
Only one ring is given. Thus, no rods have all three colors.
*/
int main() {
    char *rings1 = "B0B6G0R6R0R6G9";
    char *rings2 = "B0R0G0R9R0B0G0";
    char *rings3 = "G4";

    printf("sizeof(struct colors) = %d\n", sizeof(struct colors));

    printf("ans = %d\n", countPoints(rings1));
    printf("ans = %d\n", countPoints(rings2));
    printf("ans = %d\n", countPoints(rings3));

    return 0;
}

