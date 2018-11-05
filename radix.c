#include <stdio.h>
struct apass{
    int a[100],n;
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

int max(struct apass arr){
    int m,i;
    for(i=1,m=arr.a[0];i<arr.n;i++)
        if(arr.a[i]>m)
            m=arr.a[i];
    return m;
}

int noOfDigits(int a){
    int i;
    for(i=0;a>0;i++,a=a/10);
    return i;
}

int nthDigit(int a,int n){
    int i;
    for(i=1;i<n;i++){
        a/=10;

    }
    return a%10;
}
void shuffle(struct apass *arr,int p){
    struct apass b;
    int i,j,k=0;
    b.n=arr->n;
    for(i=0;i<=9;i++){
        for(j=0;j<b.n;j++){
            if(nthDigit(arr->a[j],p)==i){
                b.a[k]=arr->a[j];
                k++;
            }

        }
    }
    //display(&b);
    for(i=0;i<b.n;i++)
        arr->a[i]=b.a[i];
}
void radix(struct apass *arr){
    int i,t;
    t=noOfDigits(max(*arr));
    for(i=1;i<=t;i++){
        shuffle(arr,i);
        display(arr);
    }
}
int main(int argc, char const *argv[]) {
    struct apass a;
    read(&a);
    display(&a);
    radix(&a);
    display(&a);
    //printf("%d\n",nthDigit(1,5) );
    return 0;
}
