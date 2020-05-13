/**
 * Ciphers and deciphers by making use of the Caesar cipher
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";

void *caesar_cipher( char *plain_text, int key ) {
            
    /* Get text length and prellocate the ciphered text */
    int length = strlen(plain_text);
    char *ciphered_text = malloc( sizeof( char) * (length + 1) );

    /* Start ciphering each of the words */
    for ( int i = 0; i < length; i++ ) {

        /* Get a letter and its position in alphabet  */
        char letter = plain_text[i];
        char *ch = strchr(ALPHABET, letter); 

        /* Check if letter has been found */
        if ( ch != NULL ) {

            /* Apply the key to cipher the character */
            int pos = ((ch - ALPHABET) + key) % strlen(ALPHABET);

            /* Add current character to ciphered text */
            ciphered_text[i] = ALPHABET[pos];

        } else {

            /* Letter not in alphabet and can not be ciphered */
            ciphered_text[i] = letter;
        }
    }

    return ciphered_text;

}


int main ( int argc, char **args ) {

    /* Plain text message to be ciphered */
    char *plain_text = "i still consider pluto to be a planet of solar system";

    /* Key for the cipher */
    int key = 10;

    /* Cipher the plain text with previous key */
    char *ciphered_text = caesar_cipher( plain_text, key);

    /* Show plain and hidden texts */
    printf("Plain text:\t %s\n", plain_text);
    printf("Ciphered text:\t %s\n", ciphered_text);

    return EXIT_SUCCESS;
}
