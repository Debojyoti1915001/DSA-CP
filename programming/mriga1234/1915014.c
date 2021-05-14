#include <stdio.h>
#include <stdlib.h>


void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}

void bubbleSort(int A[],int n)
{
     int i,j,flag=0;

     for(i=0;i<n-1;i++)
     {
         flag=0;
         for(j=0;j<n-i-1;j++)
        {
             if(A[j]>A[j+1])
            {
                 swap(&A[j],&A[j+1]);
                 flag=1;
             }
        }
         if(flag==0)
         break;
     }

}

int * Merge(int A[],int B[],int n, int m)
{
     int* C = (int*)malloc((n+m)*sizeof(int));
     int i=0,j=0,k=0;
     while(i<n && j<m){
         if(A[i]<B[j])
            C[k++]=A[i++];
        else
            C[k++]=B[j++];
     }
     for(;i<n;i++)
        C[k++]=A[i];
     for(;j<m;j++)
        C[k++]=B[j];
    return C;

}

int main() {
    // Write C code here
   int n,m,*A,*B;
   printf("Enter number of elements in 1st Array : ");
   scanf("%d",&n);
   A=(int*)malloc(n*sizeof(int));
   for(int i=0;i<n;i++)
       scanf("%d",&A[i]);

   printf("Enter number of elements in 2st Array : ");
   scanf("%d",&m);
   B=(int*)malloc(m*sizeof(int));
   for(int i=0;i<m;i++)
       scanf("%d",&B[i]);
    bubbleSort(A,n);
    bubbleSort(B,m);

    printf("Arrays after sorting : \n");
    printf("A[] : ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);

    printf("\nB[] : ");
    for(int i=0;i<m;i++)
        printf("%d ",B[i]);

    int *C = Merge(A,B,n,m);    //Function call for Merge()

    printf("\nThe final Merged Array is : ");
    for(int i=0;i<(m+n);i++)
        printf("%d ",C[i]);

    return 0;
}
