#include <stdlib.h>
#include <stdio.h>
struct queue{
    int data;
    struct queue *link;
};

void add(struct queue **front,struct queue **rear,int num){
    struct queue *temp;
    temp=(struct queue *)malloc(sizeof(struct queue));
    temp->data=num;
    if(*front==NULL)
        *front=*rear=temp;
    else{
        (*rear)->link=temp;
        *rear=temp;
    }


}

int delete(struct queue **front,struct queue **rear){
    int data;
    struct queue *temp;
    if(*front==NULL)
        return NULL;
    data=(*front)->data;
    temp=*front;
    *front=temp->link;
    free(temp);
    return data;
}
int main(int argc, char const *argv[]) {
    struct queue *front,*rear;
    int i;
    front=rear=NULL;
    add(&front,&rear,1);
    add(&front,&rear,2);
    add(&front,&rear,3);
    add(&front,&rear,4);
    add(&front,&rear,5);
    add(&front,&rear,1);
    ((i=delete(&front,&rear))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&front,&rear))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&front,&rear))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&front,&rear))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&front,&rear))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&front,&rear))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    return 0;
}
