#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char card[20];
    int a = 0, b = 0;
    printf("Enter card number: ");
    scanf("%s", card);

    for (int i = strlen(card) - 2; i >= 0; i -= 2){
        int num = (card[i] - '0') * 2;
        if (num > 9) {
            num = (num % 10) + 1;
        }
        a += num;
    }

    for (int i = strlen(card) - 1; i >= 0; i -= 2){
        int num = card[i] - '0';
        b += num;
    }

    int c = a + b;
    if (c % 10 == 0){
        printf("Valid card\n");
    } else {
        printf("Invalid card\n");
    }
    return 0;
}
