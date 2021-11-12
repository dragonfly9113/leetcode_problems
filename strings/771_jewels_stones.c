/*
771. Jewels and Stones
771_jewels_stones.c

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0

Constraints:
1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Version 1
Brute Force version
time complexity = O(M*N)
*/
bool isJewel(char* jewels, char oneStone) {
    char* j = jewels;

    while (*j) {
        if (oneStone == *j)
            return true;
        j++;
    }
    return false;
}

int numJewelsInStones_1(char * jewels, char * stones) {
    char* s = stones;
    int count = 0;

    while (*s) {
        if (isJewel(jewels, *s))
            count++;
        s++;
    }

    return count;
}

/*
Version 2
Consider that an English letter is an ASCII symbol and can be easily converted to an integer, which can be then used as an index of array. Thus an array of letters can be easily converted to an array of integers with each letter as index.
Then we can take advantage of the O(1) search charater of array to check if a stone is a jewel or not.
Time Complexity: O(M+N)
*/
int numJewelsInStones_2(char * jewels, char * stones) {
    int count = 0;
    int jewelTable['z' - 'A' + 1] = {0};

    while (*jewels) {
        jewelTable[*jewels - 'A'] = 1;
        jewels++;
    }    

    while (*stones) {
        if (jewelTable[*stones - 'A'] == 1)
            count++;
        stones++;
    }

    return count;
}

/*
Version 3 - from discussions
Improvements from version 2:
1. No need to calculate the length of jewel table. Since we know that letter z (the biggest one) is less than 128, we can just define a table of 128 to cover all English letters.
2. The for loop can be more neat than while loop, and no need to calculate array size.
3. For table index, no need to calculate *p - 'A' since we have an arr[128] to cover all.
4. No need to use if clause.

Note: similar method uses unordered_map in C++, and HashSet in Java.
*/
int numJewelsInStones(char * jewels, char * stones) {
    int a = 0;
    char t[128] = {};

    for (char* p = jewels; *p; p++) t[*p] = (char) 1;
    for (char* p = stones; *p; p++) a += t[*p];    

    return a;
}

/*
Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
*/
int main() {
    char* jewels1 = "aA";
    char* jewels2 = "z";

    char* stones1 = "aAAbbbb";
    char* stones2 = "ZZ";

    int output1 = numJewelsInStones(jewels1, stones1);
    int output2 = numJewelsInStones(jewels2, stones2);

    printf("output1 = %d\n", output1);
    printf("output2 = %d\n", output2);

    return 0;
}
