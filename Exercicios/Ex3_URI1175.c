#include <stdio.h>

int main(){

   int n[20], x,i,y;
    for(i=0; i<20; i++)
        scanf("%d",&n[i]);
    for(i=0, y=19; i<10; i++, y--){

        x=n[i];
        n[i]=n[y];
        n[y]=x;   
    }

    for(i=0; i<20; i++)
        printf("N[%d] = %d\n",i,n[i]);
        
    return 0;
}