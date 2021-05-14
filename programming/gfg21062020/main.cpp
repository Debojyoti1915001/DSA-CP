#include <iostream>

using namespace std;
#define dim 3
struct Node{
int data;
Node* next;
Node* prev;
Node* up;
Node* down;
};
Node* createNode(int data){
Node*temp=new Node();
temp->data=data;
temp->next=NULL;
temp->prev=NULL;
temp->down=NULL;
}
Node* constructDoublyListUtil(int mtrx[][dim],int i,int j,Node*curr){
if(i>=dim||j>=dim){
    return NULL;
}
Node*temp=createNode(mtrx[i][j]);
temp->prev=curr;
temp->next=constructDoublyListUtil(mtrx,i,j+1,temp);
temp->down=constructDoublyListUtil(mtrx,i+1,j,temp);
return temp;
}
Node*constructDoublyList(int mtrx[][dim]){
return constructDoublyListUtil(mtrx,0,0,NULL);
}
void display(Node* head)
{
    // pointer to move right
    Node* rPtr;

    // pointer to move down
    Node* dPtr = head;

    // loop till node->down is not NULL
    while (dPtr) {

        rPtr = dPtr;

        // loop till node->right is not NULL
        while (rPtr) {
            cout << rPtr->data << " ";
            rPtr = rPtr->next;
        }

        cout << "\n";
        dPtr = dPtr->down;
    }
}
int main()
{
    int mtrx[dim][dim] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    Node* list = constructDoublyList(mtrx);

    display(list);

    return 0;
}
