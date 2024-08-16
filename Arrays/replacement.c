#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int is_valid_key(const char *key) {
        for (int i = 0; key[i] != '\0'; i++) {
            if (!isalpha(key[i])) {
                return 0;
            }
        } 
        return 1;
    }

    char text[1000], key[1000];

    do {
        printf("Insert key: ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = 0;
        if(strlen(key) != 26){
            printf("The key must contain 26 characters.\n");
        }
    } while (!is_valid_key(key) || strlen(key) != 26);

    printf("Insert text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    printf("Key: %s\n", key);
    printf("Plaintext: %s\n", text);
    printf("Ciphertext: ");

    for (int i=0; i < strlen(text); i++){
        char c = text[i];
        if (isalpha(c)){
            if (islower(c)){
                c = tolower(key[c - 'a']);
            } else if (isupper(c)){
                c = toupper(key[c - 'A']);
            }
        }
        printf("%c", c);
    }

    return 0;
}