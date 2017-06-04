#include <stdio.h>
#include <cs50.h>
#include <string.h>

void vigenere_cipher(string s, string k);
string key;
string plaintext;
int length;
int keyslot;

int main(int argc, string argv[])
{
    
    // check to make sure that only a single argument was put in
    if (argc > 2 || argc < 2) {
        printf("Please enter a single string as a command line argument\n");
        return 1;
    }
    
    // get the len of the argument and put it in a string
    length = strlen(argv[1]);
    
    // put the key string into a workable variable
    key = argv[1];
    
    // check to make sure the argument only contains letters
    for (int v = 0; v < length; v++) {
        if(argv[1][v] <= 64 && argv[1][v] >= 0) {
            printf("Please enter letters only, no numbers or special characters!\n");
            return 1;
        }
        else if(argv[1][v] >= 91 && argv[1][v] <= 96) {
            printf("Please enter letters only, no numbers or special characters!\n");
            return 1;
        }
        else if(argv[1][v] >= 123 && argv[1][v] <= 127) {
            printf("Please enter letters only, no numbers or special characters!\n");
            return 1;
        }
        else {
            continue;
        }
    }

    printf("plaintext: ");
    plaintext = get_string();
    printf("ciphertext: ");
    vigenere_cipher(plaintext, key);
    printf("\n");
    return 0;

    
}


void vigenere_cipher(string s, string k) {
    
    int plainlen = strlen(s);
    int count = 0;
    
    for (int i = 0; i < plainlen; i++) { // for loop to iterate through the string
    
            // cycle through key again if needed
            if ( count >= strlen(k) ) {
                count = 0;
                i--;
            }
            
            keyslot = k[count];
            
            if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) {
                printf("%c", (s[i] + keyslot) % 26);
            }
            
            // anything leftover is a symbol, print it. dont increase count because it isnt an alphabetical character
            else {
                printf("%c", s[i]);
            }
    }
}