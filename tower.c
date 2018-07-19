#include <stdio.h>
int i=0;
void ToH(char source,char destination,char temp,int n){i++;
        if(n>1){
        ToH(source,temp,destination,n-1);
        printf("move %dth disc from %c to %c\n",n,source,destination );
        ToH(temp,destination,source,n-1);
        }
        else if(n==1)
        printf("move %dth disc from %c to %c\n",n,source,destination );
        else
        printf("not valid disc no\n" );
        return;
}
int main(){
        int n;
        printf("enter no of discs\n" );
        scanf("%d",&n );
        ToH('A','B','C',n);
        printf("no of steps is %d\n",i );
}
