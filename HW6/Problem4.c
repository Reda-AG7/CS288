#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



int main(int argc,char** argv){
    printf("%d\n",argc);
    if(argc <=1)
        return 0;
    else{
        int size = atoi(argv[1]);
        //allocating the 2dArray
        int** arr = (int**) malloc(size*sizeof(int*));
        for(int i=0;i<size;i++)
            *(arr + i) = (int*)malloc((i+1)*sizeof(int));
        
        //filling out the triangle
        for(int i=0;i<size;i++){
            for(int j=0;j<=i;j++){
                if(j == 0 || j==i)
                    arr[i][j] = 1;
                else arr[i][j]=arr[i-1][j-1] + arr[i-1][j];
            }
        }
        //display the triangle
        for(int i=0;i<size;i++){
            for(int j=0;j<=i;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
        //freeing the memory
        for(int i=0;i<size;i++)
            free(arr[i]);
        free(arr);

    }

    return 0;
}