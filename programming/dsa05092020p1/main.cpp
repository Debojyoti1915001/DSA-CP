#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int main(){
srand(time(0));
int *p=nullptr;
int r,c,n;
scanf("%d%d%d",&r,&c,&n);
int *arr = (int *)malloc(n* sizeof(int));
int i;
for(i=0;i<n;i++)
*(arr+i)=(rand()%(r-c +1))+c;
for(i=0;i<n;i++)
printf("%d ",*(arr+i));
}
