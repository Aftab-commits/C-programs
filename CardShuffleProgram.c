#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARD 52
#define FACE 13

typedef struct {
    char *face;
    char *suit;
} game;

// Initialize deck with all cards
void deck(game *card, char *face[], char *suit[])
{
    for(int i=0; i<CARD; i++){
        card[i].face = face[i%FACE];
        card[i].suit = suit[i/FACE];
    }
}

// Shuffle the deck using Fisher-Yates algorithm
void shuffle(game *card)
{
    int j;
    game temp;
    
    for(int i=0; i<CARD; i++){
        j = rand() % CARD;
        temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }
}

// Print the entire deck
void print_deck(game *card)
{
    for(int i=0; i<CARD; i++){
        printf("%-15s of %-10s", card[i].face, card[i].suit);
        if((i+1) % 2 == 0){
            printf("\n");
        } else {
            printf("\t\t");
        }
    }
    printf("\n");
}

int main()
{
    char *face[FACE] = {
        "Ace", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "Jack", "Queen", "King"
    };
    
    char *suit[4] = {
        "Hearts", "Diamonds", "Clubs", "Spades"
    };
    
    game card[CARD];
    
    srand(time(NULL));
    
    printf("=== CARD SHUFFLE PROGRAM ===\n\n");
    
    // Initialize deck
    deck(card, face, suit);
    
    printf("Original Deck:\n");
    printf("==============\n");
    print_deck(card);
    
    printf("\n\nShuffled Deck:\n");
    printf("==============\n");
    shuffle(card);
    print_deck(card);
    
    return 0;
}
