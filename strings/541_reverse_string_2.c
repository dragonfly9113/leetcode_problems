/*
541. Reverse String II

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"

Constraints:
1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104
*/

#include <stdio.h>
#include <string.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

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

/*
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
*/
char * reverseStr_1(char* s, int k) {
	int sSize = strlen(s);
	char* p = s;
	char* q = s + sSize - 1;

	while (p <= q) {
		int cLeft = q - p + 1;	// cLeft is the number charaters left from the current p position.

		if (cLeft < k)
			reverseString(p, cLeft);
		else
			reverseString(p, k);

		p += 2 * k;		
	}

	return s;
}

/*
Use MIN() to avoid using if..else.. clause.
*/
char * reverseStr(char* s, int k) {
	int sSize = strlen(s);
	char* p = s;
	char* q = s + sSize - 1;

	while (p <= q) {
		int cLeft = q - p + 1;	// cLeft is the number charaters left from the current p position.
		reverseString(p, MIN(cLeft, k));

		p += 2 * k;		
	}

	return s;
}

/*
Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"
*/
int main()
{
	char str1[] = "abcdefg";
	int k1 = 2;
	char str2[] = "abcd";
	int k2 = 2;

	reverseStr(str1, k1);
	printf("str1 = %s\n", str1);
	
	reverseStr(str2, k2);
	printf("str2 = %s\n", str2);

	return 0;
}

