#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
     int temp=*x;
     *x=*y;
     *y=temp;
}
void selectionSort(int A[],int n)
{
     int i,j,k;

     for(i=0;i<n-1;i++)
     {
        for(j=k=i;j<n;j++)
        {
             if(A[j]<A[k])
             k=j;
         }
        swap(&A[i],&A[k]);
     }
}
int main()
{
    int n,*A;
    printf("Enter the elements in the array : ");
    scanf("%d",&n);
    A = (int*)malloc(n*sizeof(int));
    printf("Enter the Elements  : ");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    selectionSort(A,n);
    printf("Sorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
