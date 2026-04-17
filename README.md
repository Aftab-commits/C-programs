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
