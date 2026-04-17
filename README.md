*****###  THE REPO CONTAINS MULTIPLE IMPORTANT C PROGRAMS (FOR LOGIC BUILDING)  ###*****

## 1. Card Shuffle Program

### Description
Simulates a standard 52-card deck and displays both original and shuffled output.

- Uses a structure to store face and suit of each card  
- Deck is initialized using index mapping instead of nested loops  
- Cards are shuffled randomly and printed in formatted layout  

### Key Logic and Techniques
```c
typedef struct {
    char *face;
    char *suit;
} game;

face[i % 13];   // selects card value
suit[i / 13];   // assigns suit

j = rand() % 52;   // random index for swapping
```
---

## 2. Game of Craps Simulation

### Description
Simulates 100,000 games of craps to analyze winning probability and game behavior.

- Uses random dice rolls to follow standard craps rules  
- Tracks wins, losses, and number of moves per game  
- Calculates win probability and average moves  
- Stores frequency of wins and losses based on number of moves  

### Key Logic and Techniques
```c
die1 = (rand() % 6) + 1;
die2 = (rand() % 6) + 1;
sum = die1 + die2;

if(sum == 7 || sum == 11) result = 1;
else if(sum == 2 || sum == 3 || sum == 12) result = 0;
else {
    target = sum;
    while(1){
        // repeat until target or 7
    }
}
```
