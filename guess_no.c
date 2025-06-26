#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int num,guess,attempts=0;
    srand(time(NULL));
    num=rand()%100;

    do{
        printf("\nGuess the number(0 to 99): ");
        scanf("%d",&guess);

        if (guess<num){
            printf("\nEnter larger number");
        }
        else if (guess>num){
            printf("\nEnter smaller number");
        }
        else {
            printf("\nyou guessed the correct number");        
        }
        attempts++;
    } while(guess != num);

    printf("\nNumber of attempts: %d",attempts);
    printf("\nDeveloped by: ASUTOSH SAHU");
}