#include <stdio.h>
#include <stdlib.h>
struct snode{//structure to pass
    int data;
    struct snode *link;

};

void push(int i,struct snode **stack){
    struct snode *temp;
     temp=(struct snode *)malloc(sizeof(struct snode));
     temp->data=i;
     temp->link=*stack;
     *stack=temp;
}
int  pop(struct snode **stack) {
    struct snode *temp;
    int i;
    if(*stack==NULL){
        printf("no element to return\n" );
        return NULL;
    }
    i=(*stack)->data;
    temp=*stack;
    *stack=(*stack)->link;
    free(temp);
    return i;

}
void delstack(struct snode **stack){//function to delete all elements in the stack
    while(*stack !=NULL)
        pop(stack );
}
int main(int argc, char const *argv[]) {
    struct snode *stack;
    int i;
    stack=NULL;
    push(1,&stack);
    push(2,&stack);
    push(2,&stack);
    push(2,&stack);
    ((i=pop(&stack))==NULL)?printf("stack empty\n" ):printf("popped element =%d\n",i );
    /*((i=pop(&stack))==NULL)?printf("stack empty\n" ):printf("popped element =%d\n",i );
    ((i=pop(&stack))==NULL)?printf("stack empty\n" ):printf("popped element =%d\n",i );
    /* code */
    delstack(&stack);
    ((i=pop(&stack))==NULL)?printf("stack empty\n" ):printf("popped element =%d\n",i );

    return 0;
}

/*output
popped element =2
popped element =1
no element to return
stack empty
*/
