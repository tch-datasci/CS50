#include <stdio.h>
#include <cs50.h>
#include <string.h>

void get_initials(string s);
string name;
int canary;
int space;
char initials[4];

int main(void)
{
    printf("Please enter your name: ");
    name = get_string();
    get_initials(name);
    printf("%s\n", initials);
}

void get_initials(string s)
{
    canary = 1; // Variable indicating whether or not the previous space was blank or not
    space = 0; // Variable to save which slot in the initials array we are on
    
    // This for loop will iterate through the string. If "canary" is 1 it will save that character to the "initials" array using the
    // number saved in the "space" variable, increment the "space" variable and then set "canary" to 0. If the current character of
    // the string is a space, dash, period or single quote it will set "canary" to 1, alerting that the following character belongs
    // in the "initials" array. If current character is anything else it will just continue the next iteration, to be safe.
    
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == ' ' || s[i] == '-' || s[i] == '.' || s[i] == '\'') {
            canary = 1;
        }
        else if (canary == 1) {
            initials[space] = s[i];
            space++;
            canary = 0;
        }
        else {
            continue;
        }
    }
        
}