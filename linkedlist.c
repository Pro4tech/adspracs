#include <stdio.h>
#include <stdlib.h>//for free() and malloc()

struct node{
    int data;
    struct node *link;
};

void display(struct node *q){//function to display all nodes in the linked list
    //struct node *q;
    printf("\nthe linked list is:\n" );
    for(;q!=NULL;q=q->link)
        printf("%d\n",q->data );
    printf("\n" );
}

void append(int x,struct node **head){//function to add node at the end
    struct node *p ,*q;
    q=(struct node *)malloc(sizeof(struct node));
    if(*head==NULL){//this works the node being added is first node
        *head=q;
    }
    else{//this works in other case
        for(p=*head;p->link!=NULL;p=p->link);//for loop to go to the end if the linked list
        p->link=q;

    }
    q->data=x;//assigns value to data part of the node
    q->link=NULL;//makes the link NULL
    //display(*head);
}

int size(struct node *head){//function to find size of the linked list
    int i=0;
    struct node *p;
    for(p=head;p!=NULL;p=p->link,i++);
    return i;

}
void addf(int x,struct node **head){//function to add node at the beginning
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=*head;//points the link part of newly created
    //node to the first node of existing linked list
    *head=newnode;//makes the newly created node first node
    //display(*head);
}

void addm(int pos,int x,struct node **head){//function to add node at nth position from front
    int i;
    struct node *p,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
//    pos--;
    if(pos>size(*head)){//comdition to check if the position is valid.
        //the function returns control to main if linked list is too small
        printf("link list too small\n" );
        return;
    }

    for (i=1,p=*head;i<pos;i++,p=p->link);
    newnode->link=p->link;
    p->link=newnode;
    //display(*head);


}
void  deletev(int val,struct node **head) {//finction to delete a value in the linked list
    struct node *p,*q;
    while ((*head) -> data==val) {//works if the value passed is at the first node
        p=*head;
        *head=p->link;
        free(p);
    }
    for(p=*head;p->link!=NULL;p=p->link){//checks other nodes
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
