//---------------game of craps program:-------------
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int sum;
    int die1;
    int die2;
    int target;
    int move;
    int frequency_win[22]={0};
    int frequency_loss[22]={0};
    int result;
    int win=0;
    int loss=0;
    int total_move=0;
    for(int i=1; i<=100000; i++){
        result=0;
        target=0;
        move=0;
        die1=(rand()%6)+1;
        die2=(rand()%6)+1;
        sum=die1+die2;
        move++;

        if(sum==7 || sum==11){
            result=1;
        }
        else if(sum==2 || sum ==3 || sum==12){
            result=0;
        }
        else{
            target=sum;

            while(1){
                die1=(rand()%6)+1;
                die2=(rand()%6)+1;
                sum=die1+die2;
                move++;
                if(sum==target){
                    result=1;
                    break;
                }
                else if(sum==7){
                    result=0;
                    break;
                }

            }
        }
        if(result==1){
            win++;
            if(move<=20){
                ++frequency_win[move];
            }
            else{
                ++frequency_win[21];
            }
        }
        else{
            loss++;
            if(move<=20){
                ++frequency_loss[move];
            }
            else{
                ++frequency_loss[21];
            }
        }
        total_move+=move;

    }
    for(int i=1; i<22; i++){
        if(i>20){
            printf("The games won in moves higher then 20: %d\n", frequency_win[21]);
            total_move+=frequency_win[21];

        }
        else{
            printf("Game won in %d moves: %d\n", i, frequency_win[i]);
            total_move+=frequency_win[i];
        }
    }
    for(int i=1; i<22; i++){
        if(i>20){
            printf("The games loss in moves higher then 20: %d\n", frequency_loss[21]);
            total_move+=frequency_loss[21];
        }
        else{
            printf("Game loss in %d moves: %d\n", i, frequency_loss[i]);
            total_move+=frequency_loss[i];
        }
    }
    printf("\nTotal wins: %d", win);
    printf("\nTotal losses: %d\n", loss);
    printf("Chance of winning: %f\n",((float)win/100000)*100);
    printf("The average of the moves per game is: %d",total_move/100000);
    // Assuming frequency_win[22] and frequency_loss[22] are already filled
    // from your 1000-game simulation

    printf("\nWin ratio vs game length:\n");
    printf("Moves\tWin Ratio (%%)\n");

    for (int i = 1; i <= 21; i++) {
        int wins = frequency_win[i];
        int losses = frequency_loss[i];
        int total = wins + losses;

        if (total > 0) { // avoid division by zero
            double win_ratio = (double)wins / total * 100.0;
            if (i <= 20)
                printf("%2d\t%.2f%%\n", i, win_ratio);
            else
                printf(">20\t%.2f%%\n", win_ratio);
        }
    }



    return 0;
}