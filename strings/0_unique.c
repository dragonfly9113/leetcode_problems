/*
How to handle uniqueness with C programm?
0_unique.c
*/
#include <stdio.h>
#include <string.h>


/*
Count distinct elements in an array

Checking from left, if the first distinct element is found, it is counted. All the same elements to its right will not be counted.

Example 1:
arr = {1, 2, 3, 3, 4, 5};
ret = 5 because there are only 5 distinct elements in this arr: {1, 2, 3, 4, 5}
*/
int countDistinct(int *arr, int arrSize) {
    int cnt = 1;
    
    if (arrSize == 0)
        return 0;
    
    for (int i = 1; i < arrSize; i++) {
        int j;
        for (j = 0; j < i; j++)
            if (arr[j] == arr[i])
                break;
        if (j == i)
            cnt++;
    }
    return cnt;
}


int main() {
    int arr1[] = {1, 2, 3, 3, 4, 5};
    int arrSize1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {1, 2, 3, 3, 1};
    int arrSize2 = sizeof(arr2) / sizeof(int);
    int arr3[] = {2, 2, 3, 3, 5, 5};
    int arrSize3 = sizeof(arr3) / sizeof(int);

    printf("ans = %d\n", countDistinct(arr1, arrSize1));
    printf("ans = %d\n", countDistinct(arr2, arrSize2));
    printf("ans = %d\n", countDistinct(arr3, arrSize3));

    return 0;
}


