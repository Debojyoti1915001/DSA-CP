#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void insert(struct Node *p,int index,int x)
{
 struct Node *t;
 int i;
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;

 if(index == 0)
 {
 t->next=first;
 first=t;
 }
 else
 {
 for(i=0;i<index-1;i++)
 p=p->next;
 t->next=p->next;
 p->next=t;
 }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
int Delete(struct Node *p,int index)
{
 struct Node *q=NULL;
 int x=-1,i;
 if(index==1)
 {
 q=first;
 x=first->data;
 first=first->next;
 free(q);
 return x;
 }
 else
 {
 for(i=0;i<index-1;i++)
 {
 q=p;
 p=p->next;
 }
 q->next=p->next;
 x=p->data;
 free(p);
 return x;

 }
}
int main()
{
int n;
printf("Enter the size\n");
scanf("%d",&n);
int A[n+1];
printf("Enter the linked list elements\n");
int i;
for(i=0;i<n;i++)scanf("%d",&A[i]);
 create(A,n);
 insert(first,2,5);
 printf("The value deleted at index 2:%d\n",Delete(first,2));
 Display(first);

 return 0;
}
