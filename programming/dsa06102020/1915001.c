#include <stdio.h>
#include <stdlib.h>
struct Stack
{
     int size;
     int top;
     int *S;
};

void create(struct Stack *st)
{
     printf("Enter size : ");
     scanf("%d",&st->size);
     st->top=-1;
     st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
     int i;
     if(st.top==-1){
         printf("Stack is empty!!\n");
     }
     for(i=st.top;i>=0;i--)
     printf("%d ",st.S[i]);
     printf("\n");

}

void push(struct Stack *st,int x)
{
     if(st->top==st->size-1)
     printf("Stack overflow\n");
     else
     {
     st->top++;
     st->S[st->top]=x;
     }
}

int pop(struct Stack *st)
{
     int x=-1;
     if(st->top==-1)
     printf("Stack Underflow\n");
     else
     {
         x=st->S[st->top--];
     }
     return x;
}

int isEmpty(struct Stack st)
{
     if(st.top==-1)
     return 1;
     return 0;
}

int isFull(struct Stack st)
{
     return st.top==st.size-1;
}


int main()
{
     struct Stack st;
     create(&st);
     int x,y;
        while (1) {
            printf("Enter 1 to Display \n");
            printf("Enter 2 to Display Size \n");
            printf("Enter 3 to Push \n");
            printf("Enter 4 to Pop\n");
            printf("Enter  -1 to end\n ");
            scanf("%d", &y);
            if(y==-1)break;
            switch (y) {

                case 1:
                        Display(st);
                        break;
                case 2:
                        printf("Size of the stack : %d\n",st.top + 1);
                        break;
                case 3:
                        printf("Enter element to be pushed : ");
                        scanf("%d",&x);
                        push(&st,x);
                        printf("The stack is :\t");
                        Display(st);
                        break;
                case 4:
                        printf("Poped element : %d\n",pop(&st));
                        printf("The stack is :\n");
                        Display(st);
                        break;
                default:
                continue;
            }

      }

     return 0;
}
