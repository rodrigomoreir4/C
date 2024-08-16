#include <stdio.h>

int main(){

    int c, n, x, years;

    printf("Enter the initial population number: ");

    do{
        
        scanf("%d", &n);
        if(n < 9){
            printf("Population must be greater than 9.\n");
            printf("Enter the initial population number: ");
        }
        
    } while(n < 9);


    printf("Enter the final population number: ");

    do{

        scanf("%d", &x);
        if (x < n){
            printf("Final population cannot be smaller than initial population.\n");
            printf("Enter the final population number: ");
        }

    } while(x < n);

    for(years=0; n < x; years++){
        c = n/3 - n/4;
        n += c;
    }

    printf("Growth per year: %d\n", c);
    printf("Number of years: %d", years);
    return 0;

}