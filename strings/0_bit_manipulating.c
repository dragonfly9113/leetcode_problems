/*
Bit Manipulating
0_bit_manipulating.c
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Bit mask and bitwise operators.
*/
#define COLOR_RED   01
#define COLOR_GREEN 02
#define COLOR_BLUE  04

/*
Check if a single bit is cleared.
*/
bool checkIfBitCleared(int flags, char color) {
    if (color == 'R')
        return ((flags & COLOR_RED) == 0);
    else if (color == 'G')
        return ((flags & COLOR_GREEN) == 0);
    else
        return ((flags & COLOR_BLUE) == 0);
}

int main_checkIfBitCleared() {
    int flags = 0;

    flags |= (COLOR_RED | COLOR_GREEN | COLOR_BLUE);    /* set all bits */
    printf("R G B = %d %d %d\n", checkIfBitCleared(flags, 'R'), checkIfBitCleared(flags, 'G'), checkIfBitCleared(flags, 'B'));

    flags &= ~COLOR_RED;    /* clear RED bit */
    printf("R G B = %d %d %d\n", checkIfBitCleared(flags, 'R'), checkIfBitCleared(flags, 'G'), checkIfBitCleared(flags, 'B'));

    flags &= ~COLOR_GREEN;  /* clear GREEN bit */
    printf("R G B = %d %d %d\n", checkIfBitCleared(flags, 'R'), checkIfBitCleared(flags, 'G'), checkIfBitCleared(flags, 'B'));

    flags &= ~COLOR_BLUE;   /* clear BLUE bit */
    printf("R G B = %d %d %d\n", checkIfBitCleared(flags, 'R'), checkIfBitCleared(flags, 'G'), checkIfBitCleared(flags, 'B'));

    flags |= COLOR_GREEN;   /* set GREEN bit */
    printf("R G B = %d %d %d\n", checkIfBitCleared(flags, 'R'), checkIfBitCleared(flags, 'G'), checkIfBitCleared(flags, 'B'));

    return 0;
}

/*
Check if a single bit is set.
*/
bool checkIfBitSet(int flags, char color) {
    if (color == 'R')
        return ((flags & COLOR_RED) != 0);
    else if (color == 'G')
        return ((flags & COLOR_GREEN) != 0);
    else
        return ((flags & COLOR_BLUE) != 0);
}

int main_checkIfBitSet() {
    int flags = 0;

    flags |= (COLOR_RED | COLOR_GREEN | COLOR_BLUE);    /* set all bits */
    printf("R G B = %d %d %d\n", checkIfBitSet(flags, 'R'), checkIfBitSet(flags, 'G'), checkIfBitSet(flags, 'B'));

    flags &= ~COLOR_RED;    /* clear RED bit */
    printf("R G B = %d %d %d\n", checkIfBitSet(flags, 'R'), checkIfBitSet(flags, 'G'), checkIfBitSet(flags, 'B'));

    flags &= ~COLOR_GREEN;  /* clear GREEN bit */
    printf("R G B = %d %d %d\n", checkIfBitSet(flags, 'R'), checkIfBitSet(flags, 'G'), checkIfBitSet(flags, 'B'));

    flags &= ~COLOR_BLUE;   /* clear BLUE bit */
    printf("R G B = %d %d %d\n", checkIfBitSet(flags, 'R'), checkIfBitSet(flags, 'G'), checkIfBitSet(flags, 'B'));

    flags |= COLOR_GREEN;   /* set GREEN bit */
    printf("R G B = %d %d %d\n", checkIfBitSet(flags, 'R'), checkIfBitSet(flags, 'G'), checkIfBitSet(flags, 'B'));

    return 0;
}

/*
Check if multiple bits are clear.
*/
bool checkIfAllBitsClear(int flags) {
    return ((flags & (COLOR_RED | COLOR_GREEN | COLOR_BLUE)) == 0);
}

int main_checkIfAllBitsClear() {
    int flags = 0;

    printf("All bits clear? %d\n", checkIfAllBitsClear(flags));

    flags |= (COLOR_RED | COLOR_GREEN | COLOR_BLUE);    /* set all bits */
    printf("All bits clear? %d\n", checkIfAllBitsClear(flags));

    flags &= ~COLOR_RED;    /* clear RED bit */
    printf("All bits clear? %d\n", checkIfAllBitsClear(flags));

    flags &= ~COLOR_GREEN;  /* clear GREEN bit */
    printf("All bits clear? %d\n", checkIfAllBitsClear(flags));

    flags &= ~COLOR_BLUE;   /* clear BLUE bit */
    printf("All bits clear? %d\n", checkIfAllBitsClear(flags));

    flags |= COLOR_GREEN;   /* set GREEN bit */
    printf("All bits clear? %d\n", checkIfAllBitsClear(flags));

    return 0;
}

/*
Check if multiple bits are set.
This one is a little tricky.
*/
bool checkIfAllBitsSet(int flags) {
    return ((flags | ~(COLOR_RED | COLOR_GREEN | COLOR_BLUE)) == ~0);
}

int main() {
    int flags = 0;

    printf("All bits clear? %d\n", checkIfAllBitsSet(flags));

    flags |= (COLOR_RED | COLOR_GREEN | COLOR_BLUE);    /* set all bits */
    printf("All bits clear? %d\n", checkIfAllBitsSet(flags));

    flags &= ~COLOR_RED;    /* clear RED bit */
    printf("All bits clear? %d\n", checkIfAllBitsSet(flags));

    flags &= ~COLOR_GREEN;  /* clear GREEN bit */
    printf("All bits clear? %d\n", checkIfAllBitsSet(flags));

    flags &= ~COLOR_BLUE;   /* clear BLUE bit */
    printf("All bits clear? %d\n", checkIfAllBitsSet(flags));

    flags |= COLOR_GREEN;   /* set GREEN bit */
    printf("All bits clear? %d\n", checkIfAllBitsSet(flags));

    return 0;
}


