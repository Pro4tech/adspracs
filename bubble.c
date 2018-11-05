#include <stdio.h>
struct apass{// structure to pass array and size.
    //the maximum no of elemets can be altered here
    int a[10],n;
};
void read(struct apass *arr){//utility function to read array
    int i;
    printf("enter the no of elements\n" );
    scanf("%d",&(arr->n ));
    printf("enter elements\n" );
    for(i=0;i<arr->n;i++)
        scanf("%d",&(arr->a[i]) );
}

void display(struct apass *arr){//utility function to display array
    int i;
    printf("the elements are \n" );
    for(i=0;i<arr->n;i++)
        printf("%d\t",arr->a[i] );
    printf("\n" );
}

void  bubble(struct apass *arr) {//bubble sort function
    /* code */
    int i,j,temp;
    for(i=0;i<arr->n;i++){
        for(j=0;j<arr->n-i-1;j++){
            if(arr->a[j]>arr->a[j+1]){
                temp=arr->a[j];
                arr->a[j]=arr->a[j+1];
                arr->a[j+1]=temp;

            }
        }
    }
}

int main(int argc, char const *argv[]) {//main driver program
    struct apass a;
    read(&a);
    display(&a);
    bubble(&a);
    display(&a);
    return 0;
}
