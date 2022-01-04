/*
2114. Maximum Number of Words Found in Sentences
2114_max_num_words_in_sentence.c

A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
You are given an array of strings sentences, where each sentences[i] represents a single sentence.
Return the maximum number of words that appear in a single sentence.

Example 1:
Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation: 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.

Example 2:
Input: sentences = ["please wait", "continue to fight", "continue to win"]
Output: 3
Explanation: It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.

Constraints:
1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] consists only of lowercase English letters and ' ' only.
sentences[i] does not have leading or trailing spaces.
All the words in sentences[i] are separated by a single space.
*/
#include <stdio.h>
#include <string.h>

/*
Version 1

Example 1:
Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation: 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
*/
int numOfWords(char *s) {
    int cnt = 0;
    for (char *p = s; *p != '\0'; p++)
        if (*p == ' ')
            cnt++;
    return (cnt + 1);
}

int mostWordsFound(char ** sentences, int sentencesSize){
    int maxNum = 0;
    for (int i = 0; i < sentencesSize; i++) {
        int cnt = numOfWords(sentences[i]);
        if (maxNum < cnt)
            maxNum = cnt;
    }
    return maxNum;
}

/*
Example 1:
Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation: 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.

Example 2:
Input: sentences = ["please wait", "continue to fight", "continue to win"]
Output: 3
Explanation: It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.
*/
int main() {
    char *sentences1[] = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    int sentencesSize1 = 3;
    char *sentences2[] = {"please wait", "continue to fight", "continue to win"};
    int sentencesSize2 = 3;

    printf("ans = %d\n", mostWordsFound(sentences1, sentencesSize1));
    printf("ans = %d\n", mostWordsFound(sentences2, sentencesSize2));

    return 0;
}




