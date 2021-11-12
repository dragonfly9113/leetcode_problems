/*
1528. Shuffle String
1528_shuffle_string.c

Given a string s and an integer array indices of the same length.
The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.

Example 1:
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Example 2:
Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.

Example 3:
Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"

Example 4:
Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"

Example 5:
Input: s = "art", indices = [1,0,2]
Output: "rat"

Constraints:
s.length == indices.length == n
1 <= n <= 100
s contains only lower-case English letters.
0 <= indices[i] < n
All values of indices are unique (i.e. indices is a permutation of the integers from 0 to n - 1).
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
C calloc() method
“calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. it is very much similar to malloc() but has two different points and these are:
1. It initializes each block with a default value ‘0’.
2. It has two parameters or arguments as compare to malloc().
Syntax: 
ptr = (cast-type*)calloc(n, element-size);
here, n is the no. of elements and element-size is the size of each element.
Example:
floag* ptr = (float*) calloc(25, sizeof(float));
*/

/*
Version 1
Time:   O(N)
Space:  O(N)
*/
char * restoreString_1(char * s, int* indices, int indicesSize){
    //char* p = (char*) malloc((indicesSize + 1) * sizeof(char));
    char* p = (char*) calloc(indicesSize + 1, sizeof(char));
    if(!p) {
        printf("calloc() failed\n");
        exit(1);
    }

    for (int i = 0; i < indicesSize; i++) p[indices[i]] = s[i];

    p[indicesSize] = '\0';
    return p;
}

/*
Version 2
Time:   O(N)
Space:  O(1)

Instead of copying chars in s to a new array, we now do swapping in place in s:
swap s[indices[i]] and s[i] is to make sure s[i] is placed at correct position in s.
swap indices[indices[i]] and indices[i] is to make sure indices[i] is placed at correct position in indices.
i will only be incremented if i == indices[i], which means indices[i] is already at correct position in indices.

Keep doing the above swappings until all elements in indices are in right positions: indices = [0,1,2,3,4....]. At that point, we can also be sure that all elements in s are all in right positions too.

Note: main() needs to make sure s is defined as an array, not a pointer to string literary to allow in-place modification:
char s[] = "codeleet";  <-- OK!
char* s = "codeleet";   <-- NOt OK!
*/
char * restoreString(char * s, int* indices, int indicesSize){
    int i = 0;
    while (i < indicesSize) {
        if (i == indices[i]) i++;
        else {
            char t = s[indices[i]];
            s[indices[i]] = s[i];
            s[i] = t;

            int j = indices[indices[i]];
            indices[indices[i]] = indices[i];
            indices[i] = j;
        }
    }
    return s;
}

/*
Example 1:
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Example 2:
Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.

Example 3:
Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"

Example 4:
Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"

Example 5:
Input: s = "art", indices = [1,0,2]
Output: "rat"
*/
int main_1() {
    char* s1 = "codeleet";
    int indices1[] = {4,5,6,7,0,2,1,3};
    char* s2 = "abc";
    int indices2[] = {0,1,2};
    char* s3 = "aiohn";
    int indices3[] = {3,1,4,2,0};
    char* s4 = "aaiougrt";
    int indices4[] = {4,0,2,6,7,3,1,5};
    char* s5 = "art";
    int indices5[] = {1,0,2};

    char* o;
    o = restoreString(s1, indices1, sizeof(indices1)/sizeof(int));
    printf("o = %s\n", o);
    free(o);
    o = restoreString(s2, indices2, sizeof(indices2)/sizeof(int));
    printf("o = %s\n", o);
    free(o);
    o = restoreString(s3, indices3, sizeof(indices3)/sizeof(int));
    printf("o = %s\n", o);
    free(o);
    o = restoreString(s4, indices4, sizeof(indices4)/sizeof(int));
    printf("o = %s\n", o);
    free(o);
    o = restoreString(s5, indices5, sizeof(indices5)/sizeof(int));
    printf("o = %s\n", o);
    free(o);

    return 0;
}

int main() {
    char s1[] = "codeleet";
    int indices1[] = {4,5,6,7,0,2,1,3};
    char s2[] = "abc";
    int indices2[] = {0,1,2};
    char s3[] = "aiohn";
    int indices3[] = {3,1,4,2,0};
    char s4[] = "aaiougrt";
    int indices4[] = {4,0,2,6,7,3,1,5};
    char s5[] = "art";
    int indices5[] = {1,0,2};

    restoreString(s1, indices1, sizeof(indices1)/sizeof(int));
    printf("s1 = %s\n", s1);
    restoreString(s2, indices2, sizeof(indices2)/sizeof(int));
    printf("s2 = %s\n", s2);
    restoreString(s3, indices3, sizeof(indices3)/sizeof(int));
    printf("s3 = %s\n", s3);
    restoreString(s4, indices4, sizeof(indices4)/sizeof(int));
    printf("s4 = %s\n", s4);
    restoreString(s5, indices5, sizeof(indices5)/sizeof(int));
    printf("s5 = %s\n", s5);

    return 0;
}


