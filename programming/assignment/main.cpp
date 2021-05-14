#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int Hash(int key)
{
    return key%10;
}

void SortedInsert(struct Node **H,int x)
{
  struct Node *t,*q=NULL,*p=*H;

  t=(struct Node *)malloc(sizeof(struct Node));
  t->data=x;
  t->next=NULL;

  if(*H==NULL)
    *H=t;
  else{
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==*H)
    {
        t->next=*H;
        *H=t;
    }else{
        t->next=q->next;
        q->next=t;
    }
  }
}

struct Node * Search(struct Node *p,int x)
{
    while(p!=NULL){
        if(x==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int Delete(struct Node **H,int x)
{
    struct Node *q=NULL,*p=*H;
    int val;

    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p->data==x){
        q->next=p->next;
        val=p->data;
        free(p);
        return val;
    }
    else
            return -1;
}

void deleteHash(struct Node *H[],int key)
{
    int  del;
    int index=Hash(key);
    //printf("Index:%d",index);
    del=Delete(&H[index],key);
    if(del!=-1)
        printf("%d is deleted",del);
    else if(del==-1)
        printf("Entered key is not present in hash");
}

void Insert(struct Node *H[],int key)
{
    int index=Hash(key);
    SortedInsert(&H[index],key);
}

int main()
{
    struct Node *HT[10];
    int key,searchKey;
    struct Node *temp;
    for(int i=0;i<=9;i++)
        HT[i]=NULL;
    printf("Enter -1 to terminate insert\n");
    while(key!=-1){
        printf("Enter the key to insert:");
        scanf("%d",&key);
        if(key!=-1)
            Insert(HT,key);
    }

    printf("\nEnter the key to be searched:");
    scanf("%d",&searchKey);
    temp=Search(HT[Hash(searchKey)],searchKey);
    printf("%d is found\n",temp->data);
    while(true){
    int temp;
    printf("Enter the value to delete or -1 to delete \n");
    scanf("%d",&temp);
    if(temp== -1)break;
    deleteHash(HT,temp);
    }
    return 0;
}
