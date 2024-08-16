#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char player1[1000], player2[1000];

    int calculation(char *input){
        int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
        int position, x=0;
        for(int i=0; i < strlen(input); i++){
            if (isalpha(input[i])){
                if(islower(input[i])){
                    position = input[i] - 'a';
                } else {
                    position = input[i] - 'A';
                }
                x += POINTS[position];
            }
        }
        return x;
    }

    printf("Player 1, type the word: ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;
    int score1 = calculation(player1);

    printf("Player 2, type the word: ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;
    int score2 = calculation(player2);

    printf("Player1 : %d | ", score1);
    printf("Player2 : %d\n", score2);

    if (score1 > score2){
        printf("Player 1 wins!");
    } else if (score1 < score2){
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }

    return 0;
}