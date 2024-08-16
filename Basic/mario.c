#include <stdio.h>

int main(){

    int number;
    do
    {
        printf("Enter an integer between 1 and 8: ");
        scanf("%d", &number);
    } while (number < 1 || number > 8);

    for (int i=1; i<=number; i++){
        for(int y=1; y<=(number - i); y++){
            printf(" ");
        }
        for(int z=1; z<=i; z++){
                printf("#");
        }

        printf(" ");

        for(int z=1; z<=i; z++){
                printf("#");
        }

        printf("\n");
    }

    printf("You typed: %d\n", number);

    return 0;
}