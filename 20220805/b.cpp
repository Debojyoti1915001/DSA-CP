#include<stdio.h>

int main()

{

int a[]={1,2,4,6,8};

int* p[]={a,a+1,a+2,a+3,a+4};

int** pl=p;

int* p2=*(p+2);

printf("%u %u %u\n",*++p2,++*p2++, *++*++pl);
return 0;
}