/*
2011. Final Value of Variable After Performing Operations
2011_final_value_after_ops.c

There is a programming language with only four operations and one variable X:
++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

Example 1:
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.

Example 2:
Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.

Example 3:
Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.

Constraints:
1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".
*/
#include <stdio.h>
#include <string.h>

/*
First version
*/
int finalValueAfterOperations(char ** operations, int operationsSize){
    int x = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "++X") == 0 || strcmp(operations[i], "X++") == 0)
            x++;
        else
            x--;
    }

    return x;
}

/*
Example 1:
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.

Example 2:
Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.

Example 3:
Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
*/
int main()
{
    int output1 = 0;
    char* ops1[] = {"--X","X++","X++"};
    int ops_size1 = sizeof(ops1) / sizeof(char*);

    int output2 = 0;
    char* ops2[] = {"++X","++X","X++"};
    int ops_size2 = sizeof(ops2) / sizeof(char*);

    int output3 = 0;
    char* ops3[] = {"X++","++X","--X","X--"};
    int ops_size3 = sizeof(ops3) / sizeof(char*);

    output1 = finalValueAfterOperations(ops1, ops_size1);
    printf("ops_size1 = %d\n", ops_size1);
    printf("output1 = %d\n", output1);

    output2 = finalValueAfterOperations(ops2, ops_size2);
    printf("ops_size2 = %d\n", ops_size2);
    printf("output2 = %d\n", output2);

    output3 = finalValueAfterOperations(ops3, ops_size3);
    printf("ops_size3 = %d\n", ops_size3);
    printf("output3 = %d\n", output3);

	return 0;
}






