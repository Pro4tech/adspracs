#include <stdio.h>
#define MAX 10

struct apass{// structure to pass array and size.
    //the maximum no of elemets can be altered here
    int a[MAX],n;
};
void read(struct apass *arr){//utility function to read array
    int i;
    printf("enter the no of elements\n" );
    scanf("%d",&(arr->n ));
    printf("enter elements\n" );
    for(i=0;i<arr->n;i++)
        scanf("%d",&(arr->a[i]) );
}
void swap(int *a,int *b){
    int t=*b;
    *b=*a;
    *a=t;
}
void display(struct apass *arr){//utility function to display array
    int i;
    printf("the elements are \n" );
    for(i=0;i<arr->n;i++)
        printf("%d\t",arr->a[i] );
    printf("\n" );
}

void selectionsort(struct apass *a){
    int i,j;
    for(i=0;i<a->n-1;i++){
        for(j=i+1;j<a->n;j++){
            if(a->a[j]<a->a[i])
            swap(&(a->a[j]),&(a->a[i]));
            display(a);
        }

    }
}

int main(int argc, char const *argv[]) {
    struct apass a;
    read(&a);
    display(&a);
    selectionsort(&a);
    printf("the final array is \n" );
    display(&a);
    return 0;
}
/*outout
enter the no of elements
5
enter elements
12
32
75
48
91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	75	48	91
the elements are
12	32	48	75	91
the elements are
12	32	48	75	91
the elements are
12	32	48	75	91
the final array is
the elements are
12	32	48	75	91
*/
