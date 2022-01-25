/*
929. Unique Email Addresses
929_unique_email_addrs.c

Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.
For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.
For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.
For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.
Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.

Example 1:
Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

Example 2:
Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3

Constraints:
1 <= emails.length <= 100
1 <= emails[i].length <= 100
emails[i] consist of lowercase English letters, '+', '.' and '@'.
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
Domain names end with the ".com" suffix.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Version 1

Example 1:
Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
*/
#define MAX_NUM_EMAILS 100
#define MAX_LEN_EMAILS 101
int numUniqueEmails(char ** emails, int emailsSize){
    char processedEmails[MAX_NUM_EMAILS][MAX_LEN_EMAILS] = {{}};

    for (int i = 0; i < emailsSize; i++) {
        bool afterAt = false;
        bool afterPlus = false;
        char *o = processedEmails[i];
        for (char *p = emails[i]; *p != '\0'; p++) {
            if (*p == '@')
                afterAt = true;
            if (*p == '+')
                afterPlus = true;
            if (!afterAt) {
                if (*p == '.' || afterPlus)
                    continue;
                *o++ = *p;
            }
            else
                *o++ = *p;
        }
        *o = '\0';
    }

    printf("emailsSize = %d\n", emailsSize);
    for (int i = 0; i < emailsSize; i++)
        printf("%s\n", processedEmails[i]);

    return emailsSize;
}

/*
Example 1:
Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

Example 2:
Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3
*/
int main() {
    char *emails1[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    int emailsSize1 = sizeof(emails1) / sizeof(char *);
    
    numUniqueEmails(emails1, emailsSize1);

    return 0;
}

