#include<stdio.h>
#include<stdlib.h>

int main(){
    int size = 0;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&size);
    unsigned int* arr = (unsigned int*) malloc(size*sizeof(unsigned int));
    unsigned int* zeroBucket = (unsigned int*) malloc(size*sizeof(unsigned int));
    unsigned int* oneBucket = (unsigned int*) malloc(size*sizeof(unsigned int));
    for(int i=0;i<size;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%ud", &arr[i]);
    }
    // we know that size of unsigned int is 4 Bytes = 32bits
    for(int i=0;i<32;i++){
        int buck1Counter = 0;
        int buck0Counter = 0;
        for(int j=0;j<size;j++){
            unsigned int temp = arr[j] >> i;
            temp &= 1;
            if(temp == 1)
                oneBucket[buck1Counter++] = arr[j];
            else zeroBucket[buck0Counter++] = arr[j];
        }
        for(int k=0;k<buck0Counter;k++){
            arr[k] = zeroBucket[k];
        }
        for(int k=buck0Counter;k<size;k++){
            arr[k] = oneBucket[k-buck0Counter];
        }
    }
    //display
    for(int k=0;k<size;k++)
        printf("%u ",arr[k]);
    printf("\n");
    free(oneBucket);
    free(zeroBucket);
    free(arr);
    return 0;
}