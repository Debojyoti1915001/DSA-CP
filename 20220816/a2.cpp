listnode* reverse(listnode* head){
    listnode*p=NULL,*q=head,*r=NULL;
    while(q){
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    return p;
}
bool palindromelist(listnode* head){
    //if size of ll 0 or 1
    if(head==NULL||head->next==NULL)return true;
    //middle of the linkedlist
    listnode *fast=head,*slow=head;
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    listnode *head2=slow->next;
    slow->next=NULL;
    listnode *head2=reverse(head2);
    //iterating to check if both the vals are equal
    while(head&&head2){
        if(head->val!=head2->val)return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
}