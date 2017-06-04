#include <stdio.h>
#include <cs50.h>
#include <string.h>

void caesar_cipher(string s);
int key;
string plaintext;
int count;

int main(int argc, string argv[])
{
    
    // check to make sure that only a single argument was put in
    if (argc != 2) {
        printf("Please enter a single integer as a command line argument\n");
        return 1;
    }
    
    // convert the argument to an int
    key = atoi(argv[1]);
    
    // check to make sure the argument isn't a letter, 0, or negative number. When atoi converts to int it will output a 0
    // if the input is a letter, so 2 birds with one stone here
    if (key <= 0) {
        printf("Please enter a positive, non-zero number...and no letters allowed!\n");
        return 1;
    }

    printf("plaintext: ");
    plaintext = get_string();
    printf("ciphertext: ");
    caesar_cipher(plaintext);
    printf("\n");
    return 0;

    
}

void caesar_cipher(string s) {
    
    
    count = 0; // Variable to save which character we are on
    
    for (int i = 0; i < strlen(s); i++) { // for loop to iterate through the string
    
    
            if (s[i] >= 65 && s[i] <= 90) { // check for cap letters
            
                // wrap around function for if the key + ascii value > 90 (upper limit for capital letters). Will add the value of the
                // i'th char of the plaintext and the key value and then subtract 90 to get the remainder. The remainder is added to
                // 65 (bottom limit for capital letters) in order to get the correct wrap around value. It then assigns it to the
                // next available spot in the ciphered string.
                if (s[i] + key > 90) {
                    printf("%c", (65 + ((s[i] + key) - 91)));
                }
                // if adding the key to the character doesn't go outside of normal bounds, just change it and move on
                else {
                    printf("%c", (s[i] + key));
                }
                count++;
            }
            
            
            else if (s[i] >= 97 && s[i] <= 122) { // check for lower case letters
            
                // wrap around function for if the key + ascii value > 122 (upper limit for lower case letters). Will add the value of
                // the i'th char of the plaintext and the key value and then subtract 122 to get the remainder. The remainder is added
                // to 97 (bottom limit for lower case letters) in order to get the correct wrap around value. It then assigns it to the
                // next available spot in the ciphered string.
                if (s[i] + key > 122) {
                    printf("%c", (97 + ((s[i] + key) - 123)));
                }
                // if adding the key to the character doesn't go outside of normal bounds, just change it and move on
                else {
                    printf("%c", (s[i] + key));
                }
                count++;
            }
            
            
            else { // if the i'th char of s got to here it isn't a lower or upper case letter so just pass it on as is
                printf("%c", s[i]);
                count++;
            }
    }
    

}