#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double calculate_index(float L, float S) {
    return 0.0588 * L - 0.296 * S - 15.8;
}

int main() {
    
    char text[1000];
    int num_letters = 0, num_sentences = 0, num_words = 1;

    printf("Insert text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            num_sentences++;
        } else if (isalpha(text[i])){
            num_letters++;
        } else if(text[i] == ' ') {
            num_words++;
        }
    }

    float L = (float)num_letters/num_words * 100;
    float S = (float)num_sentences/num_words * 100;

    float index = round(calculate_index(L, S));

    printf("L: %.2f\n", L);
    printf("S: %.2f\n", S);

    printf("Phrases: %d\n", num_sentences);
    printf("Letters: %d\n", num_letters);
    printf("Words: %d\n", num_words);
    printf("Grade: %.0f\n", index);

    return 0;
}
