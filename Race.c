#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char race[71];
    int t = 1, h = 1;
    int number;

    srand(time(NULL));

    printf("BANG!!!\n");
    printf("AND THE RACE STARTS!!!!\n");

    while (t < 70 && h < 70)
    {
        number = 1 + (rand() % 10);

        for (int i = 1; i <= 70; i++)
            race[i] = '-';


        if (number >= 1 && number <= 5)
            t += 3;
        else if (number >= 6 && number <= 7)
            t -= 6;
        else
            t += 1;

        /* HARE moves */
        if (number >= 1 && number <= 2)
            ;
        else if (number >= 3 && number <= 4)
            h += 9;
        else if (number == 5)
            h -= 12;
        else if (number >= 6 && number <= 8)
            h += 1;
        else
            h -= 2;

        if (t < 1) t = 1;
        if (h < 1) h = 1;
        if (t > 70) t = 70;
        if (h > 70) h = 70;


        if (t == h)
        {
            race[t] = '*';
        }
        else
        {
            race[t] = 'T';
            race[h] = 'H';
        }

        for (int i = 1; i <= 70; i++)
        {
            if (race[i] == '*')
                printf("OUCH!!!");
            else
                printf("%c", race[i]);
        }
        printf("\n");
    }

    if (t >= 70 && h >= 70)
        printf("IT'S A TIE!\n");
    else if (t >= 70)
        printf("TORTOISE WINS!!!\n");
    else
        printf("HARE WINS!!!\n");

    return 0;
}