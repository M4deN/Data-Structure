#include <stdio.h>
 
int main(){
 
  int x,y,soma,cont,temp;

    while(scanf("%d%d",&x,&y)==2){
        
        soma=0;

        if(x>y){

            temp=x;
            x=y;
            y=temp;
        
    }

    if(x%2!=0){

        for(cont=x+2;cont<y;cont++){

            if(cont%2!=0);

                soma+=cont;
            }
        }
        else{
            for(cont=x+1;cont<y;cont++){

             if(cont%2!=0);

                soma+=cont;
            }
        }
        printf("%d\n",soma);
    }
 
    return 0;
}