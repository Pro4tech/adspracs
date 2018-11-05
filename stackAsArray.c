#include <stdio.h>
#define MAX 3//defines size of the stack
struct stack{//structure to pass top pointer and stack array
    int top;
    int a[MAX];
};
void  push(int i,struct stack *s){
    (s->top==MAX)?printf("stack full\n" ):( s->a[s->top++]=i);
}
int pop(struct stack *s){
    return !(s->top>0)?NULL: s->a[--(s->top)];
}
int main(int argc, char const *argv[]) {//driver program
    struct stack s;
    int i;
    s.top=0;
    push(2,&s);
    push(5,&s);
    push(6,&s);
    push(7,&s);
    ((i=pop(&s))==NULL)?printf("stack empty\n" ):printf("popped element=%d\n",i );
    ((i=pop(&s))==NULL)?printf("stack empty\n" ):printf("popped element=%d\n",i );
    ((i=pop(&s))==NULL)?printf("stack empty\n" ):printf("popped element=%d\n",i );
    ((i=pop(&s))==NULL)?printf("stack empty\n" ):printf("popped element=%d\n",i );
    return 0;
}
/*output
stack full
popped element=6
popped element=5
popped element=2
stack empty
*/
