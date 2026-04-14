#include<stdio.h>

typedef struct{
    char tool[100];
    int quant;
    double cost;
}inventory;

// creating a function that will take the input of the inventory at the position record given input
void input(FILE *ptr){
    int record_num;
    inventory record;
    int num;
    printf("Enter any number(>0 to add record and <0 to stop): ");
    scanf("%d", &num);
    while(num>=0){
        printf("Enter the record of the tool: ");
        scanf("%d", &record_num);
        if (record_num < 1 || record_num > 100) {
            printf("Invalid record number!\n");
            getchar();
            continue;
        }

        getchar();
        printf("Enter the tool name: ");
        gets(record.tool);

        printf("Enter the quantity of the tool: ");
        scanf("%d", &record.quant);

        printf("Enter the cost of the tool: ");
        scanf("%lf", &record.cost);

        fseek(ptr,(record_num-1)*sizeof(inventory) ,SEEK_SET);// to position the pointer at the desired
        // position and no need of rewind the seek set automatically starts from the first record
        fwrite(&record, sizeof(inventory), 1, ptr);
        printf("\n\n");
        printf("Enter any number(>0 to add record and <0 to stop): ");
        scanf("%d", &num);
    }
}
// the above code to initialize the file
// now we have to enable the program to delete any desired record and update any desired record
// for deleting the record that particulare postion would be made empty
void update(FILE *ptr, int option){
    inventory empty={"", 0, 0};
    inventory record;
    int record_num;

    if(option==1){
        printf("Enter the record number you want to delete: ");
        scanf("%d", &record_num);

        if (record_num < 1 || record_num > 100) {
            printf("Invalid record number!\n");
            return;
        }

        fseek(ptr,(record_num-1)*sizeof(inventory) ,SEEK_SET);// this sets the pointer at the required
        // position
        fwrite(&empty,sizeof(inventory),1,ptr);
    }
    else if(option==2){

    while(1){
        printf("Enter the record of the tool: ");
        scanf("%d", &record_num);
        if (record_num < 1 || record_num > 100) {
            printf("Invalid record number!\n");
            getchar();
            continue;
        }
        else{
            break;
        }
    }
        getchar();
        printf("Enter the tool name: ");
        gets(record.tool);

        printf("Enter the quantity of the tool: ");
        scanf("%d", &record.quant);

        printf("Enter the cost of the tool: ");
        scanf("%lf", &record.cost);

        fseek(ptr,(record_num-1)*sizeof(inventory) ,SEEK_SET);// to position the pointer at the desired
        //location
        fwrite(&record, sizeof(inventory), 1, ptr);
    }// this will update the desired record

}

void read_file() {
    FILE *rptr;
    inventory reading;
    rptr =fopen("hardware.dat", "rb");
    if (rptr== NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    int header_printed =0;
    for(int i = 1; i <= 100; i++) {
        fread(&reading,sizeof(inventory),1, rptr);

        if(reading.tool[0]!= '\0') {
            if (!header_printed) {
                printf("%-10s%-20s%-10s%-10s\n", "Record", "Tool name","Quantity", "Cost");
                header_printed = 1;
            }

            printf("%-10d%-20s%-10d%-10.2f\n", i,reading.tool, reading.quant,reading.cost);
        }
    }

    fclose(rptr);
}


int main()
{
    FILE *fptr;
    inventory empty={"", 0, 0};
    int choice;
    // the file should be made of random access as it has to be then modified
    if((fptr=fopen("hardware.dat", "wb+"))==NULL){
        printf("The file is not available!!");
    }
    else{
        // creating 100 free(initialized to 0) records
        for(int i=0; i<100; i++){
            fwrite(&empty,sizeof(inventory),1,fptr);
        }
        rewind(fptr);
        input(fptr);// called a function that will take the input of the data
        //in the file according to the record number
        while(1){
            printf("Enter one to delete the record and 2 to update the record (or <0 to stop): ");
            scanf("%d", &choice);
            if(choice<0){
                break;
            }
            else if(choice!=1 && choice!=2){
                printf("The number is invalid!\n");
                continue;
            }
            if(choice<0){
                break;
            }
            update(fptr, choice);
            printf("\n");
        }
        fclose(fptr);
        // writing a function to read the file harware.dat

        printf("\n\n");
        read_file();
    }



    return 0;
}