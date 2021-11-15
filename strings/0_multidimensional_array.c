/*
Multidimensional array
0_multidimentional_array.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
To pass a string, we can use either char* or char[] (1D array).
*/
void print1D_1(char* item) {
    printf("item = %s\n", item);
}

void print1D(char item[]) {
    printf("item = %s\n", item);
}

/* 2D version 1:
When items1[][10] is defined using 2D array, the parameter of print2D() should also be defined as strs[][10]. Note that the second dimention size must be defined and match that of items1[][10].
The following two definitions do NOT work:
    void print2D_1(char* strs, int strsSize);     // Assume the incoming 2D array can be converted to a 1D array.
    void print2D_1(char** strs, int strsSize);    // Assume the incoming 2D array is the same as char** pointer.

We can see a big drawback of this funciton definition: it is NOT flexible at all. The first parameter MUST be char [][10]! Even the size of the second dimention is fixed!
*/
void print2D_1(char strs[][10], int strsSize) {
    for (int i = 0; i < strsSize; i++)
        printf("1%d: %s\n",i, strs[i]);
}

/* 2D version 2:
Since items2 is defined as an array of pointers, when it is passed as argument it is actually converted to char**. Thus here the first parameter of print2D_2 should be char**.
The function can also be defined as below:
    void print2D_2(char* strs[], int strsSize);
But the below definitions are NOT OK:
    void print2D_2(char* strs, int strsSize);
    void print2D_2(char strs[][10], int strsSize);

Note: I think this definition is better than that of 2D array. It is more flexible to use! This might be one of the reasons why array of pointers is more commonly used than multi-dimention arrays.
*/
void print2D_2(char** strs, int strsSize) {
    for (int i = 0; i < strsSize; i++)
        printf("2%d: %s\n",i, strs[i]);
}

/* 2D version 2.1:
Similar to print2D_2(). The difference: the array of pointers will be allocated dynamically and passed to this function.
Usually print2d_2() doesn't care how char** strs is allocated and initialized as long as strsSize is passed in. That's why print2D_2(char** strs, ..) is more flexible than the multidimensional array version.
*/
void print2D_2_1(char** strs, int strsSize) {
    for (int i = 0; i < strsSize; i++)
        printf("2.1%d: %s\n",i, strs[i]);
}

/* 2D version 2.2:
Similar to print2D_2_1(). The difference: instead of pointing to dynamically allocated memory space, each row pointer points to static anonymous string literal (likely in read-only memory region).
*/
void print2D_2_2(char** strs, int strsSize) {
    for (int i = 0; i < strsSize; i++)
        printf("2.2%d: %s\n",i, strs[i]);
}

/* 2D version 2.3:
The strs is defined as a 2D array but is casted as char* and passed here. The dimension bound info is lost during the cast process. Therefore we need to pass them in seperately as strsSize and colSize.
The strs in memory looks like a 1D array:
[Hello,\0....World!\0...]
 ^           ^
 0           10
When implementing print2D_2_3(), we need to explicitly use strsSize and colSize in order to properly use pointer strs. This is the drawback of this approach: implementing print2D_2_3() is a little more complex.
*/
void print2D_2_3(char* strs, int strsSize, int colSize) {
    for (int i = 0; i < strsSize; i++) {
        strs += i * colSize;
        printf("2.3%d: %s\n",i, strs);
    }
}

/* 3D version 1: 
The following definitions do NOT work:
    void print3D_2(char* strs, int strsSize);
    void print3D_2(char** strs, int strsSize);
    void print3D_2(char*** strs, int strsSize);

As we observed in 2D, this function definition is NOT flexible. Especially we must give the bounds of the second and the third dimensions as array type. This will greatly limit the usefulness of the function.
*/
void print3D_1(char strs[][3][10], int strsSize) {
    for (int i = 0; i < strsSize; i++) {
        printf("3D_1: ");
        for (int j = 0; j < 3; j++)
            printf("%s  ", strs[i][j]);
        printf("\n");
    }
}

/* 3D version 2:
A little better than version 1 as we only need to specify one bound.
But still not flexible.
*/
void print3D_2(char* strs[][3], int strsSize) {
    for (int i = 0; i < strsSize; i++) {
        printf("3D_2: ");
        for (int j = 0; j < 3; j++)
            printf("%s  ", strs[i][j]);
        printf("\n");
    }
}

/* 3D version 3:
The items5 (char ***) will be dynamically allocated and passed here. Since all pointers pointed to by items5 are allocated and initialized in a d1 * d2 array manner. Here we can access those pointers as in a d1 * d2 array.
*/
void print3D_3(char*** strs, int d1, int d2) {
    for (int i = 0; i < d1; i++) {
        printf("3D_3: ");        
        for (int j = 0; j < d2; j++)
            printf("%s  ", strs[i][j]);
        printf("\n");
    }
}

/* 3D version 3.1: Not OK!
//int d1 = 2, d2 = 3, d3 = 10;
//char items3[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
Convert the 3D array to 1D array and pass to print3D_3_1() as char *.
This one didn't work as expected and prints something like below, which is NOT correct!
3D_3_1: phone  blue  computer
3D_3_1:
*/
void print3D_3_1(char* strs, int d1, int d2, int d3) {
    for (int i = 0; i < d1; i++) {
        printf("3D_3_1: ");
        for (int j = 0; j < d2; j++) {
            strs += j * d3 + i * d2 * d3;
            printf("%s  ", strs);
        }
        printf("\n");
    }
}


/*
char items3[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
*/
int main() {

    char* item = "Hello, world!";
    //char item[] = "Hello, world!";        // This way is also OK!
    print1D(item);

    /* 2D version 1:
    Use a 2D array to hold multiple strings. Must indicate the dimentions for all inner dimentions. Only the most outer dimention does not need to specify. Note that in this way, all items are of the same length 10. Also in this way, all necessary storage (2 * 10 * sizeof(char)) is allocated upfront.

    The items1 can only be passed to print2D_1():
        void print2D_1(char strs[][10], int strsSize);
    It is NOT OK to pass items1 to print2D_2():
        void print2D_2(char** strs, int strsSize);
    Even casting items1 to char** type and passing to print2D_2() is NOT OK:
        print2D_2((char **)items1, 2);
    */
    char items1[][10] = {"Hello,", "world!"};
    print2D_1(items1, 2);

    /* 2D version 2:
    Use an array of pointers to hold multiple strings.
    But the following definition/initialization is NOT OK
        char** items2 = {"Hello,", "world!"};
    This means even though we know char* [] will be converted to char**, but we cannot just define char** items2 and initialize it as an array of pointers.
    */
    char* items2[] = {"Hello,", "world!"};
    print2D_2(items2, 2);

    /* 2D version 2.1:
    Use an array of pointers to hold multiple strings.
    Allocate storage with dynamic allocation.
    */
    int rows = 2, cols = 10;
    char** items2_1 = (char **) malloc(rows * sizeof(char*));
    char* items_arr[] = {"Hello,", "world!"};
    if (!items2_1) {
        printf("items2_1 is null because malloc() failed!\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        items2_1[i] = (char *) malloc(cols * sizeof(char));
        if (!items2_1[i]) {
            printf("items2_1[%d] is null because malloc() failed!\n", i);
            exit(1);
        }
        strcpy(items2_1[i], items_arr[i]);
    }
    print2D_2_1(items2_1, rows);

    for (int i = 0; i < rows; i++)
        free(items2_1[i]);
    free(items2_1);

    /* 2D version 2.2:
    Use an array of pointers to hold multiple strings.
    Mix dynamic allocation and static allocation. Only rows number of pointers are dynamically allocated. Instead of dynamically allocating space for each row pointer, each row pointer points to a static unnamed string literal (likely allocated in read-only memory).
    */
    rows = 2;
    char** items2_2 = (char **) malloc(rows * sizeof(char*));
    //char* items_arr[] = {"Hello,", "world!"};
    if (!items2_2) {
        printf("items2_2 is null because malloc() failed!\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++)
        items2_2[i] = items_arr[i];
    print2D_2_2(items2_2, rows);
    free(items2_2);

    /* 2D version 2.3:
    This way is a nice compromise. Here items2_3 can be defined as 2D array and easily initialized. Then we cast items2_3 as a char* and pass to print2D_2_3(). Since we are not passing array dimensions any more, we need to pass the bounds seperately as strsSize and colSize.
        void print2D_2_3(char* strs, int strsSize, int colSize);
    */
    char items2_3[][10] = {"Hello,", "world!"};
    print2D_2_3((char*)items2_3, 2, 10);

    /* 3D version 1:
    Use 3-dimentional array.
    Note: an multidimensional array must have bounds for all dimensions except the first!
    */
    char items3[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
    print3D_1(items3, 2);

    /* 3D version 2:
    Use a 2D array of pointers.
    It is a little better than 3D array as at least we only need to give one bound.
    Note: we can NOT define items4 as below:
        char** items4[] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
    */
    char* items4[][3] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
    print3D_2(items4, 2);

    /* 3D version 3:
    Use array of pointers with dynamic allocation.
    First allocate space for 1 pointer to hold items5 (char ***).
    Secondly allocate space for 2 pointers to hold items5[0] and items5[1] (char **).
    Thirdly allocate space for 6 pointers to hold items5[0][0]...items5[]1[2] (char *).
    Lastly allocate space for 6 strings (10 chars max each) and save their addresses to the 6 pointers allocated above.
    Therefore, in all, there are 9 pointers in play.
    */
    //char items3[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
    int d1 = 2, d2 = 3, d3 = 10;
    char*** items5 = (char ***)malloc(d1 * sizeof(char**));
    if (!items5) {
        printf("items5 is null because malloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < d1; i++) {
        items5[i] = (char **)malloc(d2 * sizeof(char*));
        if (!items5[i]) {
            printf("items5[%d] is null because malloc() failed!\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++) {
            items5[i][j] = (char *)malloc(d3 * sizeof(char));
            if (!items5[i][j]) {
                printf("items5[%d][%d] is null because malloc() failed!\n", i, j);
                exit(1);
            }
            strcpy(items5[i][j], items3[i][j]);
        }
    
    print3D_3((char ***)items5, d1, d2);

    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            free(items5[i][j]);
    for (int i = 0; i < d1; i++)
        free(items5[i]);
    free(items5);

    /* 3D version 3.1: Not OK!
    Convert the 3D array to 1D array and pass to print3D_3_1() as char *.
    This one didn't work as expected and prints something like below, which is NOT correct!
    3D_3_1: phone  blue  computer
    3D_3_1:
    */
    //int d1 = 2, d2 = 3, d3 = 10;
    //char items3[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}};
    print3D_3_1((char *)items3, d1, d2, d3);

    return 0;
}

