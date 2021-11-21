#include<stdio.h>
#include<stdlib.h>


void display(float* arr, int size) {
    for (int i = 0; i < size; i++) 
        printf("%f\t", arr[i]);
}
void radixSort(float** arr,int size,char sort){
    float* oneBucket = (float*) malloc(size*sizeof(float));
    float* zeroBucket = (float*) malloc(size*sizeof(float));
    int zeroCounter = 0,oneCounter = 0;
    for(int i=0;i<32;i++){
        for(int j=0;j<size;j++){
            unsigned int temp = *((unsigned int*) (*arr+j)) >> i;
            temp &= 1 ;
            if(temp == 1)
                oneBucket[oneCounter++] = (*arr)[j];
            else  zeroBucket[zeroCounter++] = (*arr)[j];
        }
        if(sort == 'a'){
            for(int k=0;k<zeroCounter;k++)
                (*arr)[k] = zeroBucket[k];
            for(int k=zeroCounter;k<size;k++)
                (*arr)[k] = oneBucket[k];
        }
        else{
            for(int k=0;k<oneCounter;k++)
                (*arr)[k] = oneBucket[k];
            for(int k=oneCounter;k<size;k++)
                (*arr)[k] = zeroBucket[k];
        }
    }
}
int main() {
    int size = 0;
    printf("Enter the number of elements of the array : ");
    scanf("%d", &size);
    int negativeCounter = 0;
    int positiveCounter = 0;
    float* negArr = (float*) malloc(size*sizeof(float));
    float* posArr = (float*) malloc(size*sizeof(float));
    for (int i = 0; i < size; i++) {
        float val = 0.0;
        printf("Enter Element %d : ", (i + 1));
        scanf("%f\n",&val);
        if(val<0) 
            negArr[negativeCounter++] = val;
        else posArr[positiveCounter++] = val;   
    }
    
    if(negativeCounter == 0){
        radixSort(&posArr,size,'a');
        display(posArr,size);
    }
    else{
        radixSort(&posArr,negativeCounter,'a');
        radixSort(&negArr,positiveCounter,'d');
        display(negArr,negativeCounter);
        display(posArr,positiveCounter);
    }
    
    return 0;
}