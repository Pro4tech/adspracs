#include <math.h>
#include <stdio.h>
struct apass{
    int a[10],n;
};

void read(struct apass *arr){
    int i;
    printf("enter the no of elements\n" );
    scanf("%d",&(arr->n ));
    printf("enter elements\n" );
    for(i=0;i<arr->n;i++)
        scanf("%d",&(arr->a[i]) );
}

void display(struct apass *arr){
    int i;
    printf("the elements are \n" );
    for(i=0;i<arr->n;i++)
        printf("%d\t",arr->a[i] );
    printf("\n" );
}

void heapify(struct apass *arr){
    int i,parent,temp;
    for(i=arr->n-1;i>0;i--){
        parent=(i-1)/2;
        if(arr->a[parent]>arr->a[i]){
            temp=arr->a[parent];
            arr->a[parent]=arr->a[i];
            arr->a[i]=temp;
        }
    }
}

void adjust(struct apass *arr){
    int i=1;
    int temp=arr->a[0];
    while(i <( arr->n)){
        if(i<arr->n-1 && arr->a[i]<arr->a[i+1])
            i++;
        if(temp>arr->a[i])
            break;
        arr->a[i/2]=arr->a[i];
        //(i==0)?(i=1):(i*=2);
        i=i*2;

    }
    arr->a[i/2]=temp;
//    display(arr);
    printf("%d\n",arr->a[0] );
}

void sort(struct apass *arr){
    int i,t;
    struct apass b;
    /*for(i=0,b.n=arr->n;i<arr->n;i++)
        b.a[i]=arr->a[i];
    for(i=0,arr->n=0;b.n>0;i++,(arr->n)++){
        display(&b);
        adjust(&b);
        arr->a[i]=b.a[0];
        b.a[0]=b.a[b.n-1];
        b.n--;
        display(&b);
    }*/
    for(i=arr->n-1;i>=1;i--){
        t=arr->a[i];
        arr->a[i]=arr->a[0];
        arr->a[0]=t;
        adjust(arr);
    }
}

int main(int argc, char const *argv[]) {
    struct apass a;
    read(&a);
    display(&a);
    heapify(&a);
    sort(&a);
    display(&a);
    return 0;
}
