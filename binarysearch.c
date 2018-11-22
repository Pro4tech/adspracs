#include <stdio.h>
#define MAX 5// size of the array can be altered here
struct str{// structure to pass array.
    int a[MAX];
};
int binarySearch(struct str  *s, int l, int r, int x){//recursive function to impliment  binary Search
   if (r >= l){
        int mid = l + (r - l)/2;
         if (s->a[mid] == x)
            return mid;
        if (s->a[mid] > x)
            return binarySearch(s, l, mid-1, x);
        return binarySearch(s, mid+1, r, x);
   }
   return -1;
}
void input(struct str *arr){//utility function to read array
    int i;
    printf("enter elements\n" );
    for(i=0;i<MAX;i++)
        scanf("%d",&(arr->a[i]) );
}
int main(int argc, char const *argv[]) {//main driver function
    struct str a;
    int x;
//    printf("%d\n",1>2 );
    input(&a);
    printf("enter a no\n" );
    scanf("%d",&x );
    x=binarySearch(&a,MAX-1,0,x);
    (x==-1)?printf("element not present in the array\n" ):printf("element found at %dth position\n",x+1 );

    return 0;
}
