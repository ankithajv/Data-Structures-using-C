#include<stdio.h>

void addMatrix(int *m1,int *m2,int rows,int cols){
    printf("Resultant Matrix:");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int sum = *(m1+i*cols+j) + *(m2+i*cols+j);
            printf("%d\t",sum);
        }
        printf("\n");
    }
}

int main() {
    int mat1[2][2], mat2[2][2];
    int rows = 2, cols = 2;

   printf("Enter the elements for 1st matrix:");
   for (int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
        scanf("%d",&mat1[i][j]);
    }
   }
   printf("Enter the elements for 2nd matrix:");
   for (int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
        scanf("%d",&mat1[i][j]);
    }
   }

    addMatrix((int *)mat1,(int *)mat2,rows,cols);

    return 0;
}