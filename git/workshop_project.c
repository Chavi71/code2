#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10
#define DELAY_MICROSECONDS 100000               //1 sec

void printArray(int arr[],int size ,int selected1,int selected2){
    for(int i=0;i<size;i++){
        if(i==selected1 || i==selected2){
            printf("\x1b[31m%d \x1b[0m",arr[i]);  //set txt color to red for selected elements
        }else{
            printf("%d ",arr[i]);
        }
    }
    printf("\r");                                 //takes the cursor to the beginning of the statement(to over write the sentence, since we are printing the contents in the same line)
    fflush(stdout);                              //flush the output to make it visible immediately (to remove any kind of delay that is produced bt the printf statement)
}

void swap(int *a,int *b){
    int temp=*a;                                        //value of a stored in temp
    *a=*b;
    *b=temp;
}
void delay(int microseconds){
    int nanoseconds=microseconds*1000;                 //since for loop runs on nanoseconds
    for(int i=0;i<nanoseconds;i++);                    //infinite loop to print nothing n to produce a delay
}

void bubbleSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                printArray(arr,size,j,j+1);             //passing the index of the left n rt ele.
                delay(DELAY_MICROSECONDS);
            }
        }
    }
}
int main(){
    srand(time(NULL));                               //to display actual time of the laptop
    int arr[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
        arr[i]=rand()%100;                           //generate random no.s for the array (10 random integers)
    }
    printf("original array:");
    printArray(arr,ARRAY_SIZE,-1,-1);               //pass any -ve value to avoid printing in red part
    printf("\n");

    printf("sorting steps:\n");
    bubbleSort(arr,ARRAY_SIZE);

    printf("\n Sorted array:");
    printArray(arr,ARRAY_SIZE,-1,-1);
    printf("\n");

    return 0;
    }