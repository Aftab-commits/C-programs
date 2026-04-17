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

## 4. Recursive String Reversal Program

### Description
Reverses strings using recursion with two different approaches: in-place swapping and recursive printing.

- Uses recursion to reverse a string character by character  
- Implements both in-place reversal and output-based reversal  
- Includes manual string length calculation without library functions  
- Demonstrates multiple recursive techniques on strings  

### Key Logic and Techniques

```c
// String length calculation without library function
int string_length(char *str)
{
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

// In-place recursive reversal using swapping
void reverse_string(char *str, int start, int end)
{
    if(start >= end) return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse_string(str, start + 1, end - 1);
}

// Recursive reverse using pointer arithmetic (prints in reverse order)
char* reverse_recursive(char *str)
{
    if(str[0] == '\0') return str;

    reverse_recursive(&str[1]);
    printf("%c", str[0]);
}
```

## 5. Student Marks Management System

### Description
Manages student records, calculates averages, finds the topper, and sorts students based on performance.

- Stores student names and marks using 2D arrays  
- Takes input using pointer-based 2D array parameters  
- Calculates average marks for each student  
- Finds student with highest average  
- Sorts students in descending order of average marks  

### Key Logic and Techniques

```c
#define SIZE 1000
#define SUBJECT 3

int num;

// Input function using pointer to 2D arrays
void input(char (*name)[SIZE], int (*marks)[SUBJECT])
{
    int student = 0;
    while(student < num){
        printf("Enter name: ");
        scanf("%s", name[student]);

        printf("Enter marks of 3 subjects:\n");
        for(int subject = 0; subject < SUBJECT; subject++){
            scanf("%d", &marks[student][subject]);
        }

        student++;
    }
}

// Average calculation
int AVG(int (*marks)[SUBJECT], int student)
{
    int total = 0;
    for(int i = 0; i < SUBJECT; i++){
        total += marks[student][i];
    }
    return total / SUBJECT;
}

// Find topper using pointer return
char* highest(char (*names)[SIZE], int (*marks)[SUBJECT])
{
    int highest_avg = -999;
    char *top;

    for(int i = 0; i < num; i++){
        if(AVG(marks, i) > highest_avg){
            highest_avg = AVG(marks, i);
            top = names[i];
        }
    }
    return top;
}

// String copy using pointers
void string_copy(char *string1, char *string2)
{
    for(int i = 0; ((*(string1+i)=*(string2+i))!='\0'); i++);
}

// Sorting students by average marks
void sorting(char name[][SIZE], int marks[][SUBJECT])
{
    int tempMarks[SUBJECT];
    char tempName[SIZE];

    for(int i = 0; i < num - 1; i++){
        for(int j = i + 1; j < num; j++){
            if(AVG(marks, i) < AVG(marks, j)){

                for(int k = 0; k < SUBJECT; k++){
                    tempMarks[k] = marks[i][k];
                    marks[i][k] = marks[j][k];
                    marks[j][k] = tempMarks[k];
                }

                string_copy(tempName, name[i]);
                string_copy(name[i], name[j]);
                string_copy(name[j], tempName);
            }
        }
    }
}
```

## 6. Tower of Hanoi (Iterative Solution)

### Description
Solves the Tower of Hanoi problem using an iterative approach instead of recursion by simulating stacks with arrays.

- Uses three pegs implemented as arrays  
- Calculates total moves using bit manipulation  
- Moves disks using fixed odd and even move rules  
- Ensures all moves follow valid Tower of Hanoi constraints  

### Key Logic and Techniques

```c
#include <stdio.h>
#include <limits.h>

#define MAX_DISKS 64

void push(int peg[], int *top, int val)
{
    peg[++(*top)] = val;
}

int pop(int peg[], int *top)
{
    if (*top < 0) return INT_MAX;
    return peg[(*top)--];
}

int peek(int peg[], int top)
{
    if (top < 0) return INT_MAX;
    return peg[top];
}

long total_moves = (1LL << n) - 1;

if (i % 2 == 1)
{
    // Move smallest disk in fixed cycle
}
else
{
    // Move the only legal disk between the other two pegs
}
```
