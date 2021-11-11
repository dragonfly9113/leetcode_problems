/*
1108. Defanging an IP Address
1108_defanging_IP_addr.c

Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

Constraints:
The given address is a valid IPv4 address.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
First version
*/
char * defangIPaddr_1(char * address) {
    int addrLen = strlen(address);
    int defangedLen = addrLen + 6;
    char* defanged_addr = malloc(defangedLen + 1);

    int j = 0;
    for (int i = 0; i < addrLen; i++) {
        if (address[i] != '.') {
            defanged_addr[j++] = address[i];
        }
        else {
            defanged_addr[j++] = '[';
            defanged_addr[j++] = '.';
            defanged_addr[j++] = ']';
        }
    }

    defanged_addr[defangedLen] = '\0';
    return defanged_addr;
}

/*
Version 2
Use pointer instead of index.
*/
char * defangIPaddr(char * address) {
    int addrLen = strlen(address);
    int defangedLen = addrLen + 6;
    char* defanged_addr = malloc(defangedLen + 1);

    char* p = address;
    char* q = defanged_addr;
    while (p < address + addrLen) {
        if (*p != '.') {
            *q++ = *p;
        }
        else {
            *q++ = '[';
            *q++ = '.';
            *q++ = ']';
        }
        p++;
    }

    defanged_addr[defangedLen] = '\0';
    return defanged_addr;
}

/*
Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/
int main() {
    char* addr1 = "1.1.1.1";
    char* addr2 = "255.100.50.0";

    char* output;

    output = defangIPaddr(addr1);
    printf("output = %s\n", output);

    if (output) {
        free(output);
        output = NULL;
    }

    output = defangIPaddr(addr2);
    printf("output = %s\n", output);

    if (output) {
        free(output);
        output = NULL;
    }

    return 0;
}













