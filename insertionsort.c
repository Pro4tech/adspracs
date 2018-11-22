#include <stdio.h>
#include <math.h>
struct apass{// structure to pass array and size.
    //the maximum no of elemets can be altered here
    int arr[10],n;
};

/* Function to sort an array using insertion sort*/
void insertionSort(struct apass *a)
{
int i, key, j;
for (i = 1; i < a->n; i++)
{
	key = a->arr[i];
	j = i-1;

	/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
	while (j >= 0 && a->arr[j] > key)
	{
		a->arr[j+1] = a->arr[j];
		j = j-1;
	}
	a->arr[j+1] = key;
}
}

// A utility function to print an array of size n
void read(struct apass *arr){//utility function to read array
    int i;
    printf("enter the no of elements\n" );
    scanf("%d",&(arr->n ));
    printf("enter elements\n" );
    for(i=0;i<arr->n;i++)
        scanf("%d",&(arr->arr[i]) );
}

void display(struct apass *arr){//utility function to display array
    int i;
    printf("the elements are \n" );
    for(i=0;i<arr->n;i++)
        printf("%d\t",arr->arr[i] );
    printf("\n" );
}




/* Driver program to test insertion sort */
int main()
{
    struct apass a;
    read(&a);
    display(&a);
    insertionSort(&a);
    printf("the final array is \n" );
    display(&a);
    return 0;
}
/*output
enter the no of elements
5
enter elements
12
32
25
91
0
the elements are
12	32	25	91	0
the final array is
the elements are
0	12	25	32	91
*/
