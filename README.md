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
Implements the Tower of Hanoi problem using an iterative approach instead of recursion.

- Uses three arrays to simulate pegs as stacks  
- Initially places all disks on the source peg in descending order  
- Calculates total required moves using 2^n - 1  
- Executes moves in a loop using deterministic rules:
  - Odd moves always move the smallest disk in a fixed cyclic order  
  - Even moves perform the only valid legal move between the other two pegs  
- Continues until all disks are transferred to the destination peg  

### Key Logic and Techniques

```c
#define MAX_DISKS 64   // supports up to 64 disks using bit operations

// Stack simulation using arrays
void push(int peg[], int *top, int val)
{
    peg[++(*top)] = val;   // insert element at top
}

int pop(int peg[], int *top)
{
    if (*top < 0) return INT_MAX;   // treat empty peg as infinity
    return peg[(*top)--];
}

// Efficient move calculation using bit manipulation
long total_moves = (1LL << n) - 1;   // computes 2^n - 1

// Core movement logic
if (i % 2 == 1)
{
    // Odd move:
    // always move the smallest disk in a fixed cyclic pattern
}
else
{
    // Even move:
    // choose the only legal move between the other two pegs
    // by comparing top elements and moving the smaller disk
}
```

## 7. Tower of Hanoi (Recursive Solution)

### Description
Implements the Tower of Hanoi problem using recursion based on divide-and-conquer strategy.

- Takes number of disks as input and solves using recursive calls  
- Moves disks from source to destination using an auxiliary peg  
- Breaks the problem into smaller subproblems (n-1 disks)  
- Prints each move and counts total number of moves  
- Follows the rule that a larger disk can never be placed on a smaller one  

### Key Logic and Techniques

```c
// Recursive function
int hanoi(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        // Base case: directly move single disk
        printf("Move disk 1 from %c to %c\n", source, destination);
        return 1;
    }
    else
    {
        int moves = 0;

        // Step 1: move n-1 disks from source to auxiliary
        moves += hanoi(n-1, source, destination, auxiliary);

        // Step 2: move largest disk to destination
        printf("Move disk %d from %c to %c\n", n, source, destination);
        moves++;

        // Step 3: move n-1 disks from auxiliary to destination
        moves += hanoi(n-1, auxiliary, source, destination);

        return moves;
    }
}
```

## 8. Inventory Management System (File Handling - Random Access)

### Description
Implements an inventory system using binary file handling with random access to manage records.

- Stores tool name, quantity, and cost using a structure  
- Creates a file with fixed-size records for direct access  
- Allows inserting records at specific positions  
- Supports updating and deleting records using record number  
- Reads and displays only valid (non-empty) records  

### Key Logic and Techniques

```c
#include <stdio.h>

typedef struct{
    char tool[100];
    int quant;
    double cost;
} inventory;

// Initialize file with empty records for fixed-size random access
inventory empty = {"", 0, 0};
for(int i = 0; i < 100; i++){
    fwrite(&empty, sizeof(inventory), 1, fptr);
}

// Random access: jump directly to required record position
fseek(ptr, (record_num - 1) * sizeof(inventory), SEEK_SET);
fwrite(&record, sizeof(inventory), 1, ptr);

// Deletion: overwrite record with empty structure
fseek(ptr, (record_num - 1) * sizeof(inventory), SEEK_SET);
fwrite(&empty, sizeof(inventory), 1, ptr);

// Reading records and skipping empty entries
fread(&reading, sizeof(inventory), 1, rptr);
if(reading.tool[0] != '\0'){
    // valid record
}
```

## 9. Knight’s Tour Problem (Heuristic Approach)

### Description
Implements the Knight’s Tour using a greedy heuristic (Warnsdorff’s Rule) to visit all 64 squares exactly once.

- Starts from any position on the board  
- Generates all valid knight moves  
- Chooses the next move with the least future options (minimum accessibility)  
- Updates accessibility dynamically after each move  
- Stops when all squares are visited or no move is possible  

### Key Logic and Techniques

```c
#include<stdio.h>
#define size 8

// Possible knight moves (L-shape)
int vertical[8]   = {-1,-2,-2,-1,1,2,2,1};
int horizontal[8] = { 2, 1,-1,-2,-2,-1,1,2};

// Find all valid next moves
int position(int r, int col, const int board[][size], int possible_r[], int possible_col[])
{
    int next_r, next_col, count = 0;

    for(int i = 0, j = 0; i < 8; i++){
        next_r = r + vertical[i];
        next_col = col + horizontal[i];

        // Check boundaries and ensure square is not visited
        if(next_r >= 0 && next_r < size && next_col >= 0 && next_col < size && board[next_r][next_col] == 0){
            possible_r[j] = next_r;     // store valid row
            possible_col[j] = next_col; // store valid column
            j++;
            count++;
        }
    }
    return count;  // total valid moves
}

// Select next move using minimum accessibility (Warnsdorff’s Rule)
int smallest_box(const int access[][size], const int possible_r[], const int possible_c[], int n, int *best_r, int *best_c)
{
    int smallest = 999;

    for(int i = 0; i < n; i++){
        int r = possible_r[i];
        int c = possible_c[i];

        // Choose square with least accessibility (fewest future moves)
        if(access[r][c] < smallest){
            smallest = access[r][c];
            *best_r = r;
            *best_c = c;
        }
    }
    return smallest;
}

// Update accessibility after each move
int accessibilty(int access[][size], const int board[][size], int r, int c)
{
    for(int i = 0; i < 8; i++){
        int next_r = r + vertical[i];
        int next_c = c + horizontal[i];

        // Reduce accessibility of reachable unvisited squares
        if(next_r >= 0 && next_r < size && next_c >= 0 && next_c < size && board[next_r][next_c] == 0){
            if(access[next_r][next_c] > 0){
                access[next_r][next_c]--;
            }
        }
    }
}

// Main tour loop using greedy heuristic
do{
    int n = position(current_r, current_c, chess, possible_row, possible_col);

    // If no moves left before completing all 64 squares → failure
    if(n == 0 && number < 64){
        break;
    }

    // Select best next move based on minimum accessibility
    smallest_box(access, possible_row, possible_col, n, &next_r, &next_c);

    // Move knight and mark step number
    chess[next_r][next_c] = ++number;

    // Mark square as visited and update accessibility matrix
    access[next_r][next_c] = 99999;
    accessibilty(access, chess, next_r, next_c);

    // Update current position
    current_r = next_r;
    current_c = next_c;

} while(number <= 64);
```

## 10. N-Queens Placement (Heuristic Approach)

### Description
Places queens on an 8x8 chessboard using a greedy heuristic based on minimum attack coverage.

- Selects positions where a queen would attack the least number of squares  
- Places a queen and marks all attacked positions on the board  
- Repeats the process until no safe position is left  
- Does not use backtracking, so solution may not be optimal  

### Key Logic and Techniques

```c
#include <stdio.h>
#define size 8

// Place queen and mark all attacked positions
void attack(int board[][size], int row, int col) {
    board[row][col] = 10; // queen placed

    // Mark row and column
    for (int j = 0; j < size; j++)
        if (board[row][j] != 10) board[row][j] = 1;

    for (int i = 0; i < size; i++)
        if (board[i][col] != 10) board[i][col] = 1;

    // Mark diagonals (4 directions)
    for (int i=row-1,j=col-1; i>=0&&j>=0; i--,j--) if (board[i][j]!=10) board[i][j]=1;
    for (int i=row+1,j=col+1; i<size&&j<size; i++,j++) if (board[i][j]!=10) board[i][j]=1;
    for (int i=row-1,j=col+1; i>=0&&j<size; i--,j++) if (board[i][j]!=10) board[i][j]=1;
    for (int i=row+1,j=col-1; i<size&&j>=0; i++,j--) if (board[i][j]!=10) board[i][j]=1;
}

// Calculate how many squares a queen would attack from a position
int elimination(int row, int col) {
    int count = 0;

    count += size;       // row coverage
    count += size - 1;   // column coverage

    // diagonal coverage
    for (int i=row-1,j=col-1; i>=0&&j>=0; i--,j--) count++;
    for (int i=row+1,j=col+1; i<size&&j<size; i++,j++) count++;
    for (int i=row-1,j=col+1; i>=0&&j<size; i--,j++) count++;
    for (int i=row+1,j=col-1; i<size&&j>=0; i++,j--) count++;

    return count; // lower value = better position
}

// Greedy selection: choose empty cell with minimum elimination
for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

        if (chess[i][j] == 0) { // only empty cells
            if (access[i][j] < minAccess) {
                minAccess = access[i][j];
                bestR = i;
                bestC = j;
            }
        }

    }
}

// Place queen and update board
attack(chess, bestR, bestC);
```
