#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

void display(struct node *head){
    struct node *q;
    if(head==NULL){
        printf("linked list absent\n" );
        return;
    }
    printf("the linked list is\n" );
    for(q=head;q->link!=head;q=q->link)
        printf("%d\n",q->data );
    printf("%d\n",q->data );
    printf("\n" );
}

void addcq(struct node **head,struct node **tail,int i){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i;
    temp->link=*head;


    if(*head==NULL){
        *tail=temp;
        *head=temp;
    }
    else{

        (*tail)->link=temp;
            *tail=temp;

    }
}
void delcirq(struct node **head,struct node **tail){
    struct node *temp;
    temp=*head;
    if(*head==*tail){
        *head=NULL;
        *tail=NULL;

    }
    else{
        (*tail)->link=(*head)->link;

        *head=(*head)->link;
    }
    free(temp);
}


int main(int argc, char const *argv[]) {
    struct node *head,*tail;
    head=NULL;
    tail=NULL;
    addcq(&head,&tail, 10);
    addcq(&head,&tail, 20);
    display(head);
    delcirq(&head,&tail);
    display(head);

    return 0;
}
