//1915001
//DEBOJYOTI DAS
//HEAPSORT
#include <stdio.h>
void Insert(int A[],int n)
{
 int i=n,temp;
 temp=A[i];
 while(i>1 && temp>A[i/2])
 {
 A[i]=A[i/2];
 i=i/2;
 }
 A[i]=temp;
}
int Delete(int A[],int n)
{
 int i,j,x,temp,val;
 val=A[1];
 x=A[n];
 A[1]=A[n];
 A[n]=val;
 i=1;j=i*2;
 while(j<=n-1)
 {
 if(j<n-1 && A[j+1]>A[j])
 j=j+1;
 if(A[i]<A[j])
 {
 temp=A[i];
 A[i]=A[j];
 A[j]=temp;
 i=j;
 j=2*j;
 }
 else
 break;
 }
 return val;
}
int main() {
 int n;
 printf("Enter the no. of terms: ");
 scanf("%d",&n);
 int H[n+1];
 H[0]=0;
  printf("Enter the elements: \n");
  int i;
 for(i=1;i<=n;i++){
    scanf("%d",&H[i]);
 }
 for(i=2;i<=n;i++)
 Insert(H,i);
 for(i=n;i>1;i--)
 {
 Delete(H,i);
 }
  printf("After applying heap sort: \n");
 for(i=1;i<=n;i++)
 printf("%d ",H[i]);
 printf("\n");

 return 0;
}
