#include<stdio.h>
#define SIZE 1000
#define SUBJECT 3

int num;

void input(char (*name)[SIZE], int (*marks)[SUBJECT])
{
    int student=0;
    while(student<num){
        printf("Enter the student %d name: ", student+1);
        scanf("%s", name[student]);
        printf("Enter the marks of the three subjects: \n");
        for(int subject=0; subject<SUBJECT; subject++){
            scanf("%d", &marks[student][subject]);
          }
        student++;
    }
    return;
}

// Calculate average marks of a student
int AVG(int (*marks)[SUBJECT], int student)
{
    int total=0;
    for(int i=0; i<SUBJECT; i++){
        total+=marks[student][i];
    }
    return total/SUBJECT;
}

// Find the student with the highest average
char* highest(char (*names)[SIZE], int (*marks)[SUBJECT]){
    int highest_avg=-999;
    int i=0;
    char *top;
    while(i<num){
        if(AVG(marks, i)>highest_avg){
            highest_avg=AVG(marks, i);
            top=names[i];
        }
        i++;
    }
    return top;
}

// String copy utility
void string_copy(char *string1, char *string2)
{
    for(int i=0; ((*(string1+i)=*(string2+i))!='\0'); i++);
}

// Sort students by average marks in descending order
void sorting(char name[][SIZE], int marks[][SUBJECT])
{
    int tempMarks[SUBJECT];
    char tempName[SIZE];

    for (int i =0; i <num - 1; i++)
    {
        for (int j = i + 1; j< num; j++)
        {
            if (AVG(marks, i) <AVG(marks, j))
            {
                for (int k =0; k < SUBJECT; k++)
                {
                    tempMarks[k] = marks[i][k];
                    marks[i][k]= marks[j][k];
                    marks[j][k]= tempMarks[k];
                }
                string_copy(tempName,name[i]);
                string_copy(name[i],name[j]);
                string_copy(name[j],tempName);
            }
        }
    }
}

int main()
{
    char name[50][SIZE];
    int marks[50][SUBJECT]={0};
    
    printf("Enter the number of students you want to process: ");
    scanf("%d", &num);
    
    input(name, marks);
    
    printf("\n");
    printf("The topper is: %s\n", highest(name, marks));
    printf("\n\n");
    
    sorting(name, marks);
    
    printf("Students sorted by average marks:\n");
    printf("Name\t\tMarks\n");
    for(int i=0; i<num; i++){
        printf("%s\t", name[i]);
        for(int j=0; j<SUBJECT; j++){
            printf("%-10d", marks[i][j]);
        }
        printf("\tAverage: %d\n", AVG(marks, i));
    }

    return 0;
}
