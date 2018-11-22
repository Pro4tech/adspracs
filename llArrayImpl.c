#include <stdio.h>
#define MAX 10
struct llarray{
    int n,a[MAX];
};

void append(struct llarray *a,int num){

    if(a->n==MAX){
        printf("linked list full\n" );
        return;
    }
    a->n++;
    a->a[a->n]=num;
    return;
}
void delend(struct llarray *a){
    if(a->n==-1){
        printf("linked list empty\n" );
        return;
    }
    a->a[a->n]=0;
    a->n-=1;
}

void display(struct llarray a){
    int i;
    for(i=0;i<=a.n;i++)
        printf("%d\t",a.a[i] );
    printf("\n" );
}
void addbeg(struct llarray *a, int num){
    int i;
    if(a->n==MAX){
        printf("linked list full\n" );
        return;
    }
    a->n++;
    if(a!=0){
        for(i=a->n-1;i>=0;i--){
            a->a[i+1]=a->a[i];
        }
    }
    a->a[0]=num;
    return;
}

void delbeg(struct llarray *a){
    int i;
    if(a->n==-1){
        printf("linked list empty\n" );
        return;
    }
    for(i=0;i<a->n;i++)
        a->a[i]=a->a[i+1];
    a->n--;
}

void addm(struct llarray *a, int num, int pos){
    int i;
    if(a->n==MAX){
        printf("linked list full\n" );
        return;
    }
    if(pos>a->n){
        printf("position does not exist\n" );
        return;

    }
    a->n++;
    for(i=a->n-1;i>=pos;i--){
        a->a[i+1]=a->a[i];
    }
    a->a[pos]=num;

}
void delm(struct llarray *a, int pos){
    int i;
    if(a->n==-1){
        printf("linked list empty\n" );
        return;
    }
    if(pos>a->n){
        printf("position does not exist\n" );
        return;

    }
    for(i=pos;i<a->n;i++)
        a->a[i]=a->a[i+1];
    a->n--;
}
int main(int argc, char const *argv[]) {
    int i;
    struct llarray a;
    a.n=-1;
    for(i=0;i<=5;i++)
        append(&a, 2*i+1);
    display(a);
/*    for(i=0;i<=5;i++)
        delend(&a);
    */display(a);
    //printf("%d\n",a.n );
    addbeg(&a, 25);
    //printf("%d\n",a.n );
    display(a);
    delbeg(&a);
    display(a);
    addm(&a,25,3);
    display(a);
    delm(&a,3);
    display(a);
    return 0;
}
