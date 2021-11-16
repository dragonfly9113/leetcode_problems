/*
1773. Count Items Matching a Rule
1773_count_items_matching.c

You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.
The ith item is said to match the rule if one of the following is true:
ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.

Example 1:
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].

Example 2:
Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.

Constraints:
1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey is equal to either "type", "color", or "name".
All strings consist only of lowercase letters.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1
This version works when items is defined/initialized as below:
    char items1[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}, {"phone","gold","iphone"}};

This version can NOT pass the official tester because it does NOT math the required signature below:
    int countMatches(char ***items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue);
*/
int countMatches_1(char items[][3][10], int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int cnt = 0;
    int itemsCol = 0;

    if (!strcmp(ruleKey, "type")) itemsCol = 0;
    else if (!strcmp(ruleKey, "color")) itemsCol = 1;
    else itemsCol = 2;

    for (int i = 0; i < itemsSize; i++) {
        if (!strcmp(items[i][itemsCol], ruleValue)) cnt++;
    }

    return cnt;
}

/*
Version 2
*/
int countMatches(char ***items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int cnt = 0;
    int itemsCol = 0;

    if (!strcmp(ruleKey, "type")) itemsCol = 0;
    else if (!strcmp(ruleKey, "color")) itemsCol = 1;
    else itemsCol = 2;

    for (int i = 0; i < itemsSize; i++) {
        if (!strcmp(items[i][itemsCol], ruleValue)) cnt++;
    }

    return cnt;
}

/* Version 1: NOT OK!
This version of main() requires the follow countMtches(), which is NOT OK for the official tester:
    int countMatches_1(char items[][3][10], int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue);
*/
int main_1() {
    int count = 0;
    int itemsColSize = 3;
    char items1[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}, {"phone","gold","iphone"}};
    char* ruleKey1 = "color";
    char* ruleValue1 = "silver";

    count = countMatches_1(items1, 3, &itemsColSize, ruleKey1, ruleValue1);
    printf("count = %d\n", count);

    return 0;
}

/* Version 2
Example 1:
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].

Example 2:
Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
*/
int main() {
    int count = 0;
    int d1 = 3, d2 = 3, d3 = 10;
    char static_items1[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","lenovo"}, {"phone","gold","iphone"}};
    char static_items2[][3][10] = {{"phone","blue","pixel"}, {"computer","silver","phone"}, {"phone","gold","iphone"}};
    char* ruleKey1 = "color";
    char* ruleKey2 = "type";
    char* ruleValue1 = "silver";
    char* ruleValue2 = "phone";

    char*** items = (char ***)malloc(d1 * sizeof(char **));
    for (int i = 0; i < d1; i++){
        items[i] = (char **)malloc(d2 * sizeof(char *));
        for (int j = 0; j < d2; j++)
            items[i][j] = static_items1[i][j];
    }

    count = countMatches((char ***)items, d1, &d2, ruleKey1, ruleValue1);
    printf("count1 = %d\n", count);

    for (int i = 0; i < d1; i++){
        for (int j = 0; j < d2; j++)
            items[i][j] = static_items2[i][j];
    }

    count = countMatches((char ***)items, d1, &d2, ruleKey2, ruleValue2);
    printf("count2 = %d\n", count);

    for (int i = 0; i < d1; i++)
        free(items[i]);
    free(items);

    return 0;
}

