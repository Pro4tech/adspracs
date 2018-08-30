#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

void display(struct node *head){//display function
    struct node *q;
    if(head==NULL){
        printf("linked list absent\n" );
        return;
    }
    printf("the linked list is\n" );
    for(q=head;q->link!=head;q=q->link)//prints all elements till last element
        printf("%d\n",q->data );
    printf("%d\n",q->data );//prints last element
    printf("\n" );
}

void addcq(struct node **head,struct node **tail,int i){//function to add node at the end
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i;
    temp->link=*head;


    if(*head==NULL){//empty linked list
        *tail=temp;
        *head=temp;
    }
    else{//elements are present in the linked list

        (*tail)->link=temp;
            *tail=temp;

    }
}
void delcirq(struct node **head,struct node **tail){//deletes first element of the queue
    struct node *temp;
    temp=*head;
    if(*head==*tail){//this works if there is only 1 element in the linked list
        *head=NULL;
        *tail=NULL;

    }
    else{//works in cases wherein ,more than 1 element is present
        (*tail)->link=(*head)->link;

        *head=(*head)->link;
    }
    free(temp);
}


int main(int argc, char const *argv[]) {//driver program
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
