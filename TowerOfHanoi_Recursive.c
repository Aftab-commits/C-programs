#include<stdio.h>

// Recursive solution to Tower of Hanoi problem
// n = number of disks
// a = source peg
// c = destination peg
// b = auxiliary peg

int hanoi(int n, char source, char auxiliary, char destination)
{
    // Base case: only one disk to move
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return 1;
    }
    // Recursive case:
    // 1. Move n-1 disks from source to auxiliary (using destination as temporary)
    // 2. Move the largest disk from source to destination
    // 3. Move n-1 disks from auxiliary to destination (using source as temporary)
    else {
        int moves = 0;
        
        // Step 1: Move n-1 disks from source to auxiliary
        moves += hanoi(n-1, source, destination, auxiliary);
        
        // Step 2: Move the largest disk from source to destination
        printf("Move disk %d from %c to %c\n", n, source, destination);
        moves++;
        
        // Step 3: Move n-1 disks from auxiliary to destination
        moves += hanoi(n-1, auxiliary, source, destination);
        
        return moves;
    }
}

int main()
{
    int number;
    printf("=== TOWER OF HANOI (RECURSIVE) ===\n");
    printf("Enter the number of disks: ");
    scanf("%d", &number);
    
    if(number <= 0) {
        printf("Number of disks must be positive!\n");
        return 1;
    }
    
    printf("\nSolution for %d disks:\n", number);
    printf("Source: A, Auxiliary: B, Destination: C\n\n");
    
    int total_moves = hanoi(number, 'A', 'B', 'C');
    
    printf("\nTotal moves required: %d\n", total_moves);
    printf("For %d disks, minimum moves = 2^%d - 1 = %d\n", number, number, (1 << number) - 1);
    
    return 0;
}
