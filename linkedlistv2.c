#include <stdio.h>
#include <stdlib.h>

struct node{//initial structure declaration
    int data;
    struct node *link;
}*head=NULL;


void display(){//displays the linked list
    struct node *q;
    printf("\nthe linked list is:\n" );
    for(q=head;q!=NULL;q=q->link)
        printf("%d\n",q->data );
    printf("\n" );
}

void append(int x){//adds a node at the end
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
    display();
}

int size(){//returns size of the linked list
    int i=0;
    struct node *p;
    for(p=head;p!=NULL;p=p->link,i++);
    return i;

}

void addm(int pos,int x){//adds node after nth node
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
    display();


}

void addb4(int pos,int value){//adds node before nth node from behind
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
    display();
}

void deletep(int pos){//deletes node at given value
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
        display();
        return;
    }


    for (i=1,p=head;i<pos-1 && p!=NULL;i++,p=p->link);
    //printf("%d\n",i );
    q=p->link;
    p->link=q->link;
    free(q);
    display();
}

void  deletev(int val) {//deletes node having specific value
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
    display();

}

void addf(int x){//adds a node infront of the linked list
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=head;
    head=newnode;
    display();
}
 int main(int argc, char const *argv[]) {//driver code
        /* code */
    int a,b,c;while(1){
        printf("\nenter a choice:\n1 to display the link list\n" );
        printf("2 to add a node at the end\n" );
        printf("3 to add node in the front\n" );
        printf("4 to add node at any position\n" );
        printf("5 to add a node at nth position from behind\n" );
        printf("6 to delete node by value\n" );
        printf("7 to delete node by position\n" );
        printf("8 to display no of nodes in the linked list\n" );
        printf("press any other no to exit\n" );
        scanf("%d",&a );
        switch (a) {
            case 1:display();
            break;
            case 2:printf("enter value\n" );
            scanf("%d",&b );
            append(b);
            break;
            case 3:printf("enter value\n" );
            scanf("%d",&b );
            addf(b);
            break;
            case 4:printf("enter value and position\n" );
            scanf("%d%d",&b,&c );
            addm(b,c);
            break;
            case 5:printf("enter value and position\n" );
            scanf("%d%d",&b,&c );
            addb4(b,c);
            break;
            case 6:printf("enter value\n" );
            scanf("%d",&b );
            deletev(b);
            break;
            case 7:printf("enter position\n" );
            scanf("%d",&b );
            deletep(b);
            break;
            case 8:printf("the no of nodes is %d\n",size() );
            break;
            default:printf("wrong input. Goodbye\n" );
            return 0;
            }

    }
}
