#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*head=NULL;


void display(){
    struct node *q;
    printf("\nthe linked list is:\n" );
    for(q=head;q!=NULL;q=q->link)
        printf("%d\n",q->data );
    printf("\n" );
}

void append(int x){
    struct node *p ,*q;
    q=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
        head=q;
    else{
        for(p=head;p->link!=NULL;p=p->link);
        p->link=q;

    }
    q->data=x;
    q->link=NULL;
//    display();
}

int size(){
    int i=0;
    struct node *p;
    for(p=head;p!=NULL;p=p->link,i++);
    return i;

}

void addm(int pos,int x){
    int i;
    struct node *p,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    pos--;
//printf("%d\n",size() );
    if(pos>size()){
        printf("link list too small\n" );
        return;
    }
    for (i=1,p=head;i<pos;i++,p=p->link);
    newnode->link=p->link;
    p->link=newnode;
//    display();


}

void addb4(int pos,int value){
    int i;
    struct node *newnode,*p;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    if(pos>size())
    {   printf("link list too small\n" );
        return;
    }
    pos=size()-pos;
    for (i=0,p=head;i<pos;i++,p=p->link);
    newnode->link=p->link;
    p->link=newnode;
//    display();
}

void deletep(int pos){
    int i;
    struct node *p,*q;
    if(pos>size()){
        printf("no position avalible\n" );
        return;
    }
    if(pos==1) {
        p=head;
        head=p->link;
        free(p);
//        display();
        return;
    }


    for (i=1,p=head;i<pos-1 && p!=NULL;i++,p=p->link);
    //printf("%d\n",i );
    q=p->link;
    p->link=q->link;
    free(q);
//    display();
}

void  deletev(int val) {
    struct node *p,*q;
    while (head->data==val) {
        p=head;
        head=p->link;
        free(p);}
    for(p=head;p->link!=NULL;p=p->link){
        if(p->link->data==val){
            q=p->link;
            p->link=q->link;
            free(q);
        }
    }
//    display();

}

void addf(int x){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=head;
    head=newnode;
//    display();
}
 int main(int argc, char const *argv[]) {

append(1);
addf(2);
addm(2,3);
addb4(2,4);
display();
deletev(2);
display();
deletep(1);
display();
}
