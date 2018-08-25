#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void display(struct node *q){
    //struct node *q;
    printf("\nthe linked list is:\n" );
    for(;q!=NULL;q=q->link)
        printf("%d\n",q->data );
    printf("\n" );
}

void append(int x,struct node **head){
    struct node *p ,*q;
    q=(struct node *)malloc(sizeof(struct node));
    if(*head==NULL){
        //printf("hello\n" );

        *head=q;}
    else{
        for(p=*head;p->link!=NULL;p=p->link);
        p->link=q;

    }
    q->data=x;
    q->link=NULL;
    //display(*head);
}

int size(struct node *head){
    int i=0;
    struct node *p;
    for(p=head;p!=NULL;p=p->link,i++);
    return i;

}
void addf(int x,struct node **head){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=*head;
    *head=newnode;
    //display(*head);
}

void addm(int pos,int x,struct node **head){
    int i;
    struct node *p,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
//    pos--;
    if(pos>size(*head)){
        printf("link list too small\n" );
        return;
    }

    for (i=1,p=*head;i<pos;i++,p=p->link);
    newnode->link=p->link;
    p->link=newnode;
    //display(*head);


}
void  deletev(int val,struct node **head) {
    struct node *p,*q;
    while ((*head) -> data==val) {
        p=*head;
        *head=p->link;
        free(p);}
    for(p=*head;p->link!=NULL;p=p->link){
        if(p->link->data==val){
            q=p->link;
            p->link=q->link;
            free(q);
        }
    }
    //display(*head);

}




int main(int argc, char const *argv[]) {
    struct node *head;
    head=NULL;
    append(20,&head);
    append(30,&head);
    display(head);
//    append(10,&head);
    addf(10,&head);
    display(head);
    addm(5,90, &head);
    addm(4,40,&head);
    display(head);
    deletev(20,&head);
    display(head);
    return 0;
}
