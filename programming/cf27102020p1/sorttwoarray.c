#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}
void Bubble(int A[],int n)
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
void merge(int a[], int m, int b[], int n, int sorted[]) {
  int i, j, k;

  j = k = 0;

  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}
int main()
{
 int A[100],B[100],sorted[200],na,nb,i;
 printf("Enter the size of the first array\n");
 scanf("%d",&na);
 printf("Enter the first array\n");
 for(i=0;i<na;i++){
    scanf("%d",&A[i]);
 }
 Bubble(A,na);
 printf("Enter the size of the second array\n");
scanf("%d",&nb);
printf("Enter the second array\n");
 for(i=0;i<nb;i++){
    scanf("%d",&B[i]);
 }
Bubble(B,nb);
 merge(A, na, B, nb, sorted);
 printf("Enter the merged array is:\n");
 for (i = 0; i < na + nb; i++) {
    printf("%d  ", sorted[i]);
  }
 return 0;
}
