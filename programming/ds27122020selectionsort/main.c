//1915001 Debojyoti Das
#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}
void SelectionSort(int A[],int n)
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
int A[100],n,i;
 printf("Selection sort\n");
 printf("Enter the size of the array\n");
 scanf("%d",&n);
 printf("Enter the array\n");
 for(i=0;i<n;i++){
    scanf("%d",&A[i]);
 }
 SelectionSort(A,n);
printf("The sorted array is:\n");
 for(i=0;i<n;i++)
 printf("%d ",A[i]);
 printf("\n");
 return 0;
}
