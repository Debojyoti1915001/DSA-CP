//1915001 Debojyoti Das
#include <stdio.h>
#define SIZE 10
int hash(int key)
{
 return key%SIZE;
}
int probe(int H[],int key)
{
 int index=hash(key);
 int i=0;
 while(H[(index+i)%SIZE]!=0)
 i++;
 return (index+i)%SIZE;
}
void Insert(int H[],int key)
{
 int index=hash(key);

 if(H[index]!=0)
 index=probe(H,key);
 H[index]=key;
}
int Search(int H[],int key)
{
 int index=hash(key);

 int i=0;

 while(H[(index+i)%SIZE]!=key){
 i++;
 if(i==SIZE+1){
    printf("Element not present\n");
    return;
 }
 }
printf("\nKey found at %d\n",(index+i)%SIZE);
}
int main()
{
  int HT[10]={0};
    int n,k;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        Insert(HT,k);
    }

    int ch=1;
	while(ch > 0){
	    printf("Enter the element to be searched for : ");
	    int k;
	    scanf("%d",&k);
	    Search(HT,k);

	   printf("Enter 0 to stop 1 to continue : ");
	   scanf("%d",&ch);
	}
	return 0;

}
