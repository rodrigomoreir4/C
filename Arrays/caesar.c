#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int is_valid_key(const char *input) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                return 0;
            }
        } 
        return 1;
    }

    char text[1000], input[1000];
    int k;

    printf("Insert text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    do {
        printf("Enter key number: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
    } while (!is_valid_key(input) || sscanf(input, "%d", &k) != 1);

    k = k % 26;

    printf("Plaintext: %s\n", text);
    printf("Ciphertext: ");

    for (int i = 0; text[i] != '\0'; i++){
        char c = text[i];
        if (isalpha(c)){
            if (islower(c)){
                c = 'a' + (c - 'a' + k) % 26;
            } else if (isupper(c)){
                c = 'A' + (c - 'A' + k) % 26;
            }
        }
        printf("%c", c);
    }

    return 0;
}