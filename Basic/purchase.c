#include <stdio.h>

int main(){

    float price, payment;
    char a, b;
    
    printf("Enter the price amount: ");

    do{
        scanf("%c", &a);    
        if(a == '\n'){
            printf("Invalid input. Please enter a valid price amount.\n");
            printf("Enter the price amount: ");
        } else if (a == ' '){
            scanf("%*[^\n]");
        } else {
             ungetc(a, stdin);
             if(scanf("%f", &price) != 1){
                scanf("%*[^\n]");
             }
        }
    } while(price <= 0.099);

    printf("Enter the payment amount: ");

    do{
        scanf(" %c", &b);    
        if(b == '\n'){
            printf("Invalid input. Please enter a valid payment amount.\n");
            printf("Enter the payment amount: ");
        } else if (b == ' '){
            scanf("%*[^\n]");
        } else {
             ungetc(b, stdin);
             if(scanf("%f", &payment) != 1){
                scanf("%*[^\n]");
             }
        }
    } while(payment <= 0.099);

    if (payment < price){
        printf("Insufficient value for purchase!");
    } else {
        float change = payment - price;
        printf("Change: %.2f\n", change);

        int cents = (int)(change * 100);
        int coins[] = {25,10,5,1};
        for(int i = 0; i < 4; i++){
            int numCoins = cents / coins[i];
            cents %= coins[i];
            printf("Coins of %d: %d\n", coins[i], numCoins);
        }
    }

    return 0;
}

