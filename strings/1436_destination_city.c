/*
1436. Destination City
1436_destination_city.c

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.
It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

Example 1:
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

Example 3:
Input: paths = [["A","Z"]]
Output: "Z"

Constraints:
1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Version 1
*/
#define MAX_NUM_PATHS 100
#define MAX_PATH_LEN 2
#define MAX_CITY_LEN 11
char * destCity_1(char *** paths, int pathsSize, int* pathsColSize){
    char srcCities[MAX_NUM_PATHS][MAX_CITY_LEN] = {{}};
    char dstCities[MAX_NUM_PATHS][MAX_CITY_LEN] = {{}};

    char *out = calloc(MAX_CITY_LEN, sizeof(char));
    if (!out) {
        printf("out is null, calloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < pathsSize; i++) {
        strcpy(srcCities[i], paths[i][0]);
        strcpy(dstCities[i], paths[i][1]);
    }

    for (int i = 0; i < pathsSize; i++) {
        int j;
        for (j = 0; j < pathsSize; j++) {
            if (strcmp(dstCities[i], srcCities[j]) == 0)
                break;
        }
        if (j == pathsSize) {
            strcpy(out, dstCities[i]);
            break;
        }
    }
    return out;
}

/*
Version 1.1
A more compact version based on version 1: no need to use additional arrays like srcCities and dstCities.
*/
char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    for (int i = 0; i < pathsSize; i++) {
        int j;
        for (j = 0; j < pathsSize; j++) {
            if (strcmp(paths[i][1], paths[j][0]) == 0)
                break;
        }
        if (j == pathsSize)
            return paths[i][1];
    }
    return NULL;
}

/*
Example 1:
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

Example 3:
Input: paths = [["A","Z"]]
Output: "Z"

#define MAX_NUM_PATHS 100
#define MAX_PATH_LEN 2
#define MAX_CITY_LEN 11
*/
int main() {
    int d1, d2, d3;
    char *out;

    d1 = 3; // number of paths
    d2 = 2; // number of cities in each path
    d3 = MAX_CITY_LEN;  // max length of each city name

    char pathsArr[][MAX_PATH_LEN][MAX_CITY_LEN] = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};

    char *** paths = (char ***)calloc(d1, sizeof(char **));
    if (!paths) {
        printf("paths is null, calloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < d1; i++) {
        paths[i] = (char **)calloc(d2, sizeof(char *));
        if (!paths[i]) {
            printf("paths[%d] is null, calloc() failed!\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            paths[i][j] = (char *)calloc(d3, sizeof(char));
            if (!paths[i][j]) {
                printf("paths[%d][%d] is null, calloc() failed!\n");
                exit(1);
            }
            strcpy(paths[i][j], pathsArr[i][j]);
        }
    }

    out = destCity(paths, d1, &d2);
    printf("out = %s\n", out);
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            free(paths[i][j]);
    for (int i = 0; i < d1; i++)
        free(paths[i]);
    free(paths);

    /*
    Example 2:
    Input: paths = [["B","C"],["D","B"],["C","A"]]
    Output: "A"
    */
    d1 = 3; // number of paths
    d2 = 2; // number of cities in each path
    d3 = MAX_CITY_LEN;  // max length of each city name

    char pathsArr2[][MAX_PATH_LEN][MAX_CITY_LEN] = {{"B","C"},{"D","B"},{"C","A"}};

    char *** paths2 = (char ***)calloc(d1, sizeof(char **));
    if (!paths2) {
        printf("paths is null, calloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < d1; i++) {
        paths2[i] = (char **)calloc(d2, sizeof(char *));
        if (!paths2[i]) {
            printf("paths[%d] is null, calloc() failed!\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            paths2[i][j] = (char *)calloc(d3, sizeof(char));
            if (!paths2[i][j]) {
                printf("paths[%d][%d] is null, calloc() failed!\n");
                exit(1);
            }
            strcpy(paths2[i][j], pathsArr2[i][j]);
        }
    }

    out = destCity(paths2, d1, &d2);
    printf("out = %s\n", out);
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            free(paths2[i][j]);
    for (int i = 0; i < d1; i++)
        free(paths2[i]);
    free(paths2);

    /*
    Example 3:
    Input: paths = [["A","Z"]]
    Output: "Z"    
    */
    d1 = 1; // number of paths
    d2 = 2; // number of cities in each path
    d3 = MAX_CITY_LEN;  // max length of each city name

    char pathsArr3[][MAX_PATH_LEN][MAX_CITY_LEN] = {{"A","Z"}};

    char *** paths3 = (char ***)calloc(d1, sizeof(char **));
    if (!paths3) {
        printf("paths is null, calloc() failed!\n");
        exit(1);
    }

    for (int i = 0; i < d1; i++) {
        paths3[i] = (char **)calloc(d2, sizeof(char *));
        if (!paths3[i]) {
            printf("paths[%d] is null, calloc() failed!\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            paths3[i][j] = (char *)calloc(d3, sizeof(char));
            if (!paths3[i][j]) {
                printf("paths[%d][%d] is null, calloc() failed!\n");
                exit(1);
            }
            strcpy(paths3[i][j], pathsArr3[i][j]);
        }
    }

    out = destCity(paths3, d1, &d2);
    printf("out = %s\n", out);
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            free(paths3[i][j]);
    for (int i = 0; i < d1; i++)
        free(paths3[i]);
    free(paths3);

    return 0;
}


