#include<stdio.h>
#define size 8
int position(int , int, const int [][size], int [], int []);
int smallest_box(const int  [][size], const int [], const int [], int , int *, int *);
int accessibilty(int access[][size], const int board[][size], int r, int c);
int knight_tour(int , int );

int main()
{
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            knight_tour(i , j);
            printf("\n\n\n");
        }
    }

    return 0;
}

int smallest_box(const int  accessiblity[][size], const int possible_row[], const int possible_column[], int number, int *best_r, int *best_c){

    // the function takes the element of the board and then determines which of the possible moves is the
    // best possible move(the least access)
    int smallest=999;
    int r;
    int c;
    int next_r;
    int next_c;
    for(int i=0; i<number; i++){
        r=possible_row[i];
        c=possible_column[i];
        if(accessiblity[r][c]<smallest){
            smallest=accessiblity[r][c];
            *best_r=r;
            *best_c=c;
        }

    }
    return smallest;
}

int position(int r, int col, const int board[][size], int possible_r [], int possible_col[])// 0, 0 r+=vertical
{
    int vertical[8]={-1,-2,-2,-1,1,2,2,1};
    int horizontal[8]={2,1,-1,-2,-2,-1,1,2};
    int next_r;
    int next_col;
    int count=0;
    for(int i=0, j=0; i<8; i++){
        next_r=r+vertical[i];
        next_col=col+horizontal[i];
        if(next_r>=0 && next_r<=(size -1) && next_col>=0 && next_col<=(size-1) && board[next_r][next_col]==0){
            //that is a possible
            possible_r[j]=next_r;
            possible_col[j]=next_col;
            j++;
            count++;
        }
    }
    return count;

}//This function checks all 8 possible knight jumps, keeps only the valid ones, stores their coordinates
 //in two arrays, and returns how many valid moves exist.

 // I have to now work on the accessbilty

 int accessibilty(int access[][size], const int board[][size], int r, int c){
     int next_r;
     int next_c;
     int vertical[8]={-1,-2,-2,-1,1,2,2,1};
     int horizontal[8]={2,1,-1,-2,-2,-1,1,2};

     for(int i=0; i<8; i++){
        next_r=r+vertical[i];
        next_c=c+horizontal[i];
        if(next_r>=0 && next_r<=(size -1) && next_c>=0 && next_c<=(size-1) && board[next_r][next_c]==0){
            if(access[next_r][next_c]>0){
                access[next_r][next_c]--;
            }
        }
     }

 }

int knight_tour(int start_row, int start_col){
    int access[size][size] = {
        {2,3,4,4,4,4,3,2},
        {3,4,6,6,6,6,4,3},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},
        {3,4,6,6,6,6,4,3},
        {2,3,4,4,4,4,3,2}
    };

    int chess[size][size] = {0};

    int current_r = start_row;  // starting row
    int current_c = start_col;  // starting column
    int number = 1;

    chess[current_r][current_c] = number;
    access[current_r][current_c] = 99999;

    int possible_row[8], possible_col[8];
    int next_r, next_c;

    do{
        int n = position(current_r, current_c, chess, possible_row, possible_col);
        if(n == 0 && number<64) {
            printf("No more moves available. Knight tour failed!\n");
            break;
        }
        smallest_box(access, possible_row, possible_col, n, &next_r, &next_c);

        number++;
        chess[next_r][next_c] = number;
        access[next_r][next_c] = 99999;  // mark as visited
        accessibilty(access,chess,next_r, next_c);
        current_r = next_r;
        current_c = next_c;

    }while(number<=64);

    printf("Knight's Tour:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%3d ", chess[i][j]);
        }
        printf("\n");
    }

}