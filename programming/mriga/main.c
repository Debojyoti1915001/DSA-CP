#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){

    printf("Enter Maximum Size of Stack : ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st){

    int i;
    if(st.top==-1){
        printf("Stack is empty!!\n");
    }
    for(i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);
    printf("\n");
}

void push(struct Stack *st, int x){

    if(st->top==st->size-1)
        printf("Stack OverFlow!\n");
        else{
            st->top++;
            st->S[st->top]=x;
        }
}

int pop(struct Stack *st){

    int x=-1;
    if(st->top==-1)
        printf("Stack UnderFlow!!\n");
    else{
        x=st->S[st->top--];
    }
    return x;
}


int main(){

    struct Stack st;
    create(&st);
    int op=0;
    int x;
    while(op<5){
        printf("\nOptions\n");
        printf("1 : Dispaly \n");
        printf("2 : Dispaly Size \n");
        printf("3 : Push \n");
        printf("4 : Pop \n");
        printf("5 : Exit \n");
        printf("Enter your Choice : ");
        scanf("%d",&op);

        switch(op){

            case 1:
                    Display(st);
                    break;

            case 2:
                    printf("Size of the stack : %d\n",st.top+1);
                    break;

            case 3:
                    printf("Enter element to be pushed : ");
                    scanf("%d",&x);
                    push(&st,x);
                    printf("Stack now is :\t");
                    Display(st);
                    break;

            case 4:
                    printf("Popped element : %d\n",pop(&st));
                    printf("Stack now is :\t");
                    Display(st);
                    break;

            default:
                    break;
        }
    }
    return 0;
}
