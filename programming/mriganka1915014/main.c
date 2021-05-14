#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next;
};


struct node* Create(int* sz);
void Insert(struct node* head,int* sz);
void Display(struct node *head);
void Size(int s);
struct node* InsertAtPos(struct node* head, int* sz,int position, int data);
struct node* DeleteAtPos(struct node* head, int* sz,int position);

int main(){
    struct node *head;
    printf("Enter the linked list : (-1 to stop entering) \n");
    int size=0;
    int position,val;
    head = Create(&size);
    int op = 0;
    while (op < 5) {
    printf("\nOptions\n");
    printf("1 : Display \n");
    printf("2 : Display Size \n");
    printf("3 : Insert at Position \n");
    printf("4 : Delete at Position\n");
    printf("5 : Exit\n");
    printf("Enter your choice :  ");
    scanf("%d", &op);
    switch (op) {
      case 1:
        Display(head);
        break;
      case 2:
        Size(size);
        break;
      case 3:
        printf("Enter the position : ");
    	scanf("%d",&position);
    	printf("Enter the value : ");
    	scanf("%d",&val);
        head=InsertAtPos(head,&size,position,val);
        Display(head);
        break;
      case 4:
        printf("Enter the position : ");
    	scanf("%d",&position);
    	head=DeleteAtPos(head,&size,position);
        Display(head);
        break;
      default:
        break;
    }
  }
}


struct node* Create(int* sz){
    struct node* first = NULL;
    int n;
    struct node* t;
    struct node* p;
    while(1)
   {
       scanf("%d",&n);
       if(n<0)
            break;
       else
       {
           t=(struct node *)malloc(sizeof(struct node));
           t->data=n;
           t->next=NULL;
           *sz+=1;
           if(first==NULL)
           {
               first=t;
               p=first;
           }
           p->next=t;
           p=t;
       }
   }
   return first;
}
void Insert(struct node* head,int* sz){
    int n;
    if(head==NULL){
        head = Create(sz);
    }
    else
    {
        printf("Enter the value to be inserted : ");
        scanf("%d",&n);
        struct node* p=head;
        struct node* t;

        while(p->next!=NULL)
            p=p->next;

        t=(struct node *)malloc(sizeof(struct node));
        t->data=n;
        t->next=NULL;
        p->next = t;
        *sz+=1;
    }
}
void Display(struct node* head){
    struct node* t=head;
   while(t)
   {
       printf("%d ",t->data);
       t=t->next;
   }
   printf("\n");
}
void Size(int s){
    printf("Size of the linked list : %d\n",s);
}
struct node* InsertAtPos(struct node* head, int* sz,int position,int data){

        if(head==NULL){
            printf("The Linked List is empty!!\n");
            return head;
        }

    	struct node *ptr = (struct node*)malloc(sizeof(struct node));
    	ptr->data=data;

    	int i;
    	struct node *temp=head;

    	if(position==1)
        {
        	ptr->next=temp;
        	head=ptr;
        	*sz+=1;
        	return head;
    	}

    	if(position == *sz+1){
    	    while(temp->next)
    	        temp=temp->next;
    	   temp->next=ptr;
    	   ptr->next=NULL;
    	   return head;
    	}

    	if(position>(*sz+1)){
    	    printf("PLease enter valid index!!  (<=size)\n");
    	    return head;
    	}

        for(i=1;i<position-1;i++)
    	{
        		temp=temp->next;
    	}

    	ptr->next=temp->next;
    	temp->next=ptr;
    	*sz+=1;
    	return head;
}
struct node* DeleteAtPos(struct node* head, int* sz,int position){
    if(head==NULL){
        printf("The linked list is EMPTY!!\nPlease enter the Linked List : \n");
        head=Create(sz);
        return head;
    }

    if(position>(*sz)){
        printf("Please Enter a valid Position!!\n");
        return head;
    }

    struct node *t=head;
    struct node *p=NULL;
    if(position==1){
        head=head->next;
        t->next=NULL;
        free(t);
        *sz-=1;
        return head;
    }

    for(int i=1;i<position;i++){
        p=t;
        t=t->next;
    }
    p->next=t->next;
    t->next=NULL;
    free(t);
    *sz-=1;
    return head;

}

