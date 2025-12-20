#include<stdio.h>

void tow_of_h(int n,char from_rod,char to_rod,char aux_rod){

    if (n==1){
        printf("Move disk 1 from rod %c to %c\n",from_rod,to_rod); 
        return;
    }

    tow_of_h(n-1,from_rod,aux_rod,to_rod);

    printf("Move disk %d from %c to %c\n",n,from_rod,to_rod);

    tow_of_h(n-1,aux_rod,to_rod,from_rod);
}

int main(){

    int n;

    printf("Enter the number of disk:");
    scanf("%d",&n);

    tow_of_h(n,'A','C','B');
    return 0;
}