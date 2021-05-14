#include <stdio.h>
#include<stdlib.h>

void insertionSort(int A[],int n)
{
     int i,j,x;

     for(i=1;i<n;i++)
     {
         j=i-1;
         x=A[i];
         while(j>=0 && A[j]>x)
        {
             A[j+1]=A[j];
             j--;
        }
         A[j+1]=x;
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
    insertionSort(A,n);
    printf("Sorted Array : ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
