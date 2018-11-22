#include <stdio.h>
#define MAX 5
struct queue{
    int arr[MAX],front,rear;
};

void add(struct queue *q,int n){
    if((q->front==(q->rear+1)%MAX)){
        printf("queue full\n" );
        return;
    }
    q->rear+=1;
    if(q->front=-1)
    q->front+=1;
    q->front%=MAX;
    q->rear%=MAX;
    q->arr[q->rear]=n;
}

int  delete(struct queue *q){
    int temp;
    if(q->front==-1)
    return NULL;
    temp=q->arr[q->front];
    q->arr[q->front]=0;
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front+=1;
    q->front%=MAX;
    return temp;
}

void display(struct queue q) {
    int i;
    for(i=0;i<MAX;i++)
        printf("%d\t",q.arr[i] );
    printf("\n" );
}

int main(int argc, char const *argv[]) {
    struct queue q;
    int i;
    q.front=q.rear=-1;
    add(&q,1);
    add(&q,2);
    add(&q,3);
    add(&q,4);
    add(&q,5);
    add(&q,1);
    display(q);
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    display(q);
    add(&q,1);
    display(q);
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    ((i=delete(&q))==NULL)?printf("queue empty\n" ):printf("popped element=%d\n",i );
    display(q);
    return 0;
}
