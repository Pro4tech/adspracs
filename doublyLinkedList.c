#include <stdio.h>
#include <stdlib.h>

struct node{//declaration of node
    int data;
    struct node *next,*prev;
};
void addf(int x,struct node **head){//function to add node at 1st position
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=*head;
    (*head)->prev=newnode;
    *head=newnode;
    //display(*head);
}
void disprev(struct node *q){//function to display linked list in reverse order
    printf("\nthe nexted list in reverse order is:\n" );
    for(;q->next!=NULL;q=q->next);
    for(;q!=NULL;q=q->prev)
        printf("%d\n",q->data );
    printf("\n" );
}
void display(struct node *q){//function to display elements of linked list
    //struct node *q;
    printf("\nthe nexted list is:\n" );
    for(;q!=NULL;q=q->next)
        printf("%d\n",q->data );
    printf("\n" );
}
void append(int x,struct node **head){//function to add node at the end
    struct node *p ,*q;
    q=(struct node *)malloc(sizeof(struct node));
    if(*head==NULL){
        //printf("hello\n" );

        *head=q;}
    else{
        for(p=*head;p->next!=NULL;p=p->next);
        p->next=q;

    }
    q->data=x;
    q->next=NULL;
    q->prev=p;
    //display(*head);
}

int size(struct node *head){//returns size of the linked list
    int i=0;
    struct node *p;
    for(p=head;p!=NULL;p=p->next,i++);
    return i;

}
void addm(int pos,int x,struct node **head){//adds node after nth position
    int i;
    struct node *p,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
//    pos--;
    if(pos>size(*head)){
        printf("link list too small\n" );
        return;
    }

    for (i=1,p=*head;i<pos;i++,p=p->next);
    newnode->next=p->next;
    newnode->prev=p;
    p->next->prev=newnode;
    p->next=newnode;

    //display(*head);


}
void delete(int val,struct node **head) {//function to delete node containing value =val
    struct node *temp,*q=*head;
    while(q!=NULL){
        if(q->data==val){
            temp=q;
            if(q==*head){
                q->next->prev=NULL;
            }
            else if(q->next==NULL){
                q->prev->next=NULL;
            }
            else{
                q->next->prev=q->next;
                q->prev->next=q->prev;
            }
            free(temp);

        }
        q=q->next;
    }
}

int main(int argc, char const *argv[]) {
    struct node *head;
    head=NULL;
    append(20,&head);
    append(30,&head);
    display(head);
    addf(10,&head);
    display(head);
    disprev(head);
    addm(2,5,&head);
    disprev(head);
    delete(30,&head);
    disprev(head);
    return 0;
}
