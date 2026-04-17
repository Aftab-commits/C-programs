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

## 3. Tortoise and Hare Race Simulation

### Description
Simulates a race between a tortoise and a hare on a 70-position track and prints the race progress step by step.

- Uses an array to represent the race track visually  
- Both players move based on random probability rules  
- Displays real-time position updates after every move  
- Handles collisions when both land on the same position  

### Key Logic and Techniques
```c
number = 1 + (rand() % 10);

// Tortoise movement
if (number <= 5) t += 3;
else if (number <= 7) t -= 6;
else t += 1;

// Hare movement
if (number <= 2) ;
else if (number <= 4) h += 9;
else if (number == 5) h -= 12;
else if (number <= 8) h += 1;
else h -= 2;
```

