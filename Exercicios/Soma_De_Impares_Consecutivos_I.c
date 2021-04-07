#include <stdio.h>

int main(){
    
int x,y,top=0,i,min,max;


    scanf("%d %d", &y,&x);

    if (x<y){

        min=x;
        max=y;

    }else{

        max=x;
        min=y;
    }

    for(i=(min+1);i<max; ++i){

         if
            (i%2==1 || i %2==-1){

         top+=i;
            }
        }

        printf("%d\n",top);

    return 0;
}