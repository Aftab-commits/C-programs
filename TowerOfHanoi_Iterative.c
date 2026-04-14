#include <stdio.h>
#include <limits.h>

#define MAX_DISKS 64   // Supports up to 64 disks using bit operations for 2^n - 1

// Simple stack helpers
void push(int peg[], int *top, int val) {
    peg[++(*top)] = val;
}

int pop(int peg[], int *top) {
    if (*top < 0) return INT_MAX; // empty -> treat as +inf (no disk)
    return peg[(*top)--];
}

int peek(int peg[], int top) {
    if (top < 0) return INT_MAX;
    return peg[top];
}

int main(void) {
    int n;
    printf("=== TOWER OF HANOI (ITERATIVE) ===\n");
    printf("Enter odd number of disks n (e.g. 3, 5, 7): ");
    if (scanf("%d", &n) != 1) return 0;
    
    if (n <= 0 || (n % 2) == 0) {
        printf("This program expects a positive odd n.\n");
        return 1;
    }
    
    // Three pegs: 0=source(A), 1=auxiliary(B), 2=destination(C)
    int pegs[3][MAX_DISKS];
    int tops[3] = {-1, -1, -1}; // empty stacks
    char names[3] = {'A', 'B', 'C'};

    // Initialize: push n, n-1, ..., 1 onto source peg (so top is 1)
    for (int d = n; d >= 1; --d) {
        push(pegs[0], &tops[0], d);
    }

    long total_moves = (1LL << n) - 1; // 2^n - 1
    int pos_smallest = 0; // current peg index that has disk 1 (initially source = 0)

    printf("Source: A, Auxiliary: B, Destination: C\n");
    printf("Total moves required = 2^%d - 1 = %ld\n\n", n, total_moves);
    printf("Moves:\n");
    
    for (long i = 1; i <= total_moves; ++i) {
        if (i % 2 == 1) {
            // Odd move: Move smallest disk (disk 1)
            int from = pos_smallest;
            int to = (from + 2) % 3; // For odd n, cycle: 0->2->1->0...
            int disk = pop(pegs[from], &tops[from]);
            push(pegs[to], &tops[to], disk);
            pos_smallest = to; // Update position of disk 1
            printf("Move %3ld: disk %d from %c to %c\n", i, disk, names[from], names[to]);
        } 
        else {
            // Even move: Move the only legal disk between the two pegs not having disk 1
            int p1 = (pos_smallest + 1) % 3;
            int p2 = (pos_smallest + 2) % 3;
            
            int top1 = peek(pegs[p1], tops[p1]);
            int top2 = peek(pegs[p2], tops[p2]);

            if (top1 == INT_MAX && top2 == INT_MAX) {
                // Nothing to move (shouldn't happen in correct run)
                continue;
            } 
            else if (top1 == INT_MAX) {
                // p1 empty -> move top of p2 to p1
                int disk = pop(pegs[p2], &tops[p2]);
                push(pegs[p1], &tops[p1], disk);
                printf("Move %3ld: disk %d from %c to %c\n", i, disk, names[p2], names[p1]);
            } 
            else if (top2 == INT_MAX) {
                // p2 empty -> move top of p1 to p2
                int disk = pop(pegs[p1], &tops[p1]);
                push(pegs[p2], &tops[p2], disk);
                printf("Move %3ld: disk %d from %c to %c\n", i, disk, names[p1], names[p2]);
            } 
            else if (top1 < top2) {
                // Move smaller disk from p1 to p2
                int disk = pop(pegs[p1], &tops[p1]);
                push(pegs[p2], &tops[p2], disk);
                printf("Move %3ld: disk %d from %c to %c\n", i, disk, names[p1], names[p2]);
            } 
            else { // top2 < top1
                // Move smaller disk from p2 to p1
                int disk = pop(pegs[p2], &tops[p2]);
                push(pegs[p1], &tops[p1], disk);
                printf("Move %3ld: disk %d from %c to %c\n", i, disk, names[p2], names[p1]);
            }
        }
    }

    printf("\nDone! Final peg states:\n");
    for (int k = 0; k < 3; ++k) {
        printf("%c: ", names[k]);
        for (int t = 0; t <= tops[k]; ++t) {
            printf("%d ", pegs[k][t]);
        }
        printf("\n");
    }
    return 0;
}
