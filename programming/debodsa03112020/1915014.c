#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node** H;

void HashTable(){
    H = (struct node*) malloc(sizeof(struct node*)*10);
    for(int i=0;i<10;i++)
        H[i] = NULL;
}

int hash(int key){
    return key%10;
}

void insert(int key){
    int hashIndex = hash(key);
   struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = key;
	t->next = NULL;
	if (H[hashIndex] == NULL){
		H[hashIndex] = t;
	}
	else{
	    struct node* p = H[hashIndex];
	    struct node* q = H[hashIndex];
	    while (p && p->data < key){
			q=p;
			p = p->next;
		}
		if (q == H[hashIndex]){
			t->next = H[hashIndex];
			H[hashIndex] = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}

	}
}

int search(int key){
        int hashIndex = hash(key);
        struct node* p = H[hashIndex];
        while(p){
            if(p->data==key)
                return p->data;

            p=p->next;
        }
        return -1;
}

int main(void){
    // Your code here!
   HashTable();
   int n;
   printf("Enter the number of elements in the array : ");
   scanf("%d",&n);
   printf("Enter the elements : ");
   int A[n];
   for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
   for (int i=0; i<n; i++){
		insert(A[i]);
	}
	int ch=1;
	while(ch > 0){
	    printf("Enter the element to be searched for : ");
	    int k;
	    scanf("%d",&k);
	    if(search(k) > 0)
	        printf("Search Successful\n");
	    else
	        printf("Search Unsuccessful\n");

	   printf("Do you want to search more ? (0/1) ");
	   scanf("%d",&ch);
	}
	return 0;

}
