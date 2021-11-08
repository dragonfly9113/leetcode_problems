/*
	344. Reverse String

	Write a function that reverses a string. The input string is given as an array of characters s.

	Example 1:
	Input: s = ["h","e","l","l","o"]
	Output: ["o","l","l","e","h"]

	Example 2:
	Input: s = ["H","a","n","n","a","h"]
	Output: ["h","a","n","n","a","H"]

	Constraints:
	1 <= s.length <= 105
	s[i] is a printable ascii character.

	Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

/*
Note 1: The difference between char* str and char str[]:
char* str = "hello";
In this case, an unamed array will be created to hold the string litery. Then the pointer to the first element &unamed[0] will be assigned to str.
Sinde this is a string litery, it is liked that the storage of the unamed array will be put into read-only section. Thus trying to modify the string through
pointer str will cause UB (undefined behaviour)!

char str[] = "hello";
In this case, an array named "str" is created. The storage will most likely be in the stack if this statement is in a function. Modifying the string through
pointer str is OK. Passing the pointer to another function for manipulation is also OK.

Note 2: sizeof() v.s. strlen()
Based on the previous example:
sizeof(str) = 6
strlen(str) = 5

Please note that when we initialize a string like above, a nul char '\0' is appended at the end of string by compiler:
str[] = {'h', 'e', 'l', 'l', 'o', '\0'};

Therefore, sizeof(str) = 6 because sizeof() counts the number of all elements (including the nul char) in the array in bytes and because sizeof(char) = 1.
The strlen() is a function defined in standard C lib and it will count all chars in a string (excluding the nul char). We need to #include <string.h> to use it.

Note 3: The difference between the following array initialization:
char str[] = "hello";
char str[] = {'h', 'e', 'l', 'l', 'o'};

The first one is to use a string litary to initialize an array and it will append a nul char at the end of array. So the size of the array is 6.
The second one is to use {} clause to initialize an array and so str will treated just like an array (not a string). No nul char will be appended and the size is 5.
*/

#include <stdio.h>
#include <string.h>

// Use two pointers
void reverseString(char* s, int sSize){
	char* p = s;
	char* q = s + sSize - 1;
	
	while (p < q) {
		char t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}

	return;
}

// Use index instead of pointer
void reverseString_index(char* s, int sSize){
	int i = 0;
	int j = sSize - 1;

	while (i < j) {
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}

	return;
}

int main()
{
	char str1[] = "hello";
	char str2[] = "Hannah";
	
	reverseString(str1, strlen(str1));
	printf("str1 = %s\n", str1);
	
	reverseString(str2, 6);
	printf("str2 = %s\n", str2);

	return 0;
}

