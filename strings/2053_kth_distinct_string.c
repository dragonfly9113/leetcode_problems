/*
2053. Kth Distinct String in an Array
2053_kth_distinct_string.c

A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.

Example 1:
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 

Example 2:
Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.

Example 3:
Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".

Constraints:
1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
Version 1

Example 1:
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
*/
#define MAX_ARR_LEN 1000
#define MAX_STR_LEN 6
char * kthDistinct(char ** arr, int arrSize, int k){
    char *out;
    char distArr[MAX_ARR_LEN][MAX_STR_LEN] = {{}}; 

    out = (char *)calloc(MAX_STR_LEN, sizeof(char));
    if (!out) {
        printf("out is NULL, calloc() failed!\n");
        exit(1);
    }

    int idx = 0;
    for (int i = 0; i < arrSize; i++) {
        int j;
        for (j = 0; j < arrSize; j++) {
            if (j != i && !strcmp(arr[i], arr[j]))
                break;
        }
        if (j == arrSize)
            strcpy(distArr[idx++], arr[i]);
    }
    if (k <= idx)
        strcpy(out, distArr[k - 1]);
    return out;
}


/*
Example 1:
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 

Example 2:
Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.

Example 3:
Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
*/
int main() {
    char *out;
    char *arr1[] = {"d","b","c","b","c","a"};
    int arrSize1 = sizeof(arr1) / sizeof(char *);
    int k1 = 2;
    char *arr2[] = {"aaa","aa","a"};
    int arrSize2 = sizeof(arr2) / sizeof(char *);
    int k2 = 1;
    char *arr3[] = {"a","b","a"};
    int arrSize3 = sizeof(arr3) / sizeof(char *);
    int k3 = 3;

    printf("arrSize = %d\n", arrSize1);
    out = kthDistinct((char **)arr1, arrSize1, k1);
    printf("out = %s\n", out);
    free(out);
    printf("arrSize = %d\n", arrSize2);
    out = kthDistinct((char **)arr2, arrSize2, k2);
    printf("out = %s\n", out);
    free(out);
    printf("arrSize = %d\n", arrSize3);
    out = kthDistinct((char **)arr3, arrSize3, k3);
    printf("out = %s\n", out);
    free(out);

    return 0;    
}


