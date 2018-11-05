#include <stdio.h>
#define MAX 5
struct str{
    int a[MAX],i;
};
void search(int s,struct str *arr){
    int pos;
    for(pos=0;(pos<MAX) && (arr->a[pos]<=s);pos++){
        if(arr->a[pos]==s){
            arr->i=pos;
            return;
        }
    }
    arr->i=-1;
}
void input(struct str *arr){
    int i;
    printf("enter elements\n" );
    for(i=0;i<MAX;i++)
        scanf("%d",&(arr->a[i]) );
}
int main(int argc, char const *argv[]) {
    struct str a;
    int x;
    a.i=-1;
    input(&a);
    printf("enter a no\n" );
    scanf("%d",&x );
    search(x,&a);
    (a.i==-1)?printf("element not present in the array\n" ):printf("element found at %dth position\n",a.i+1 );

    return 0;
}
/*output
enter elements
1
3
5
7
9
enter a no
3
element found at 2th position


enter elements
1
3
5
7
9
enter a no
4
element not present in the array
*/
