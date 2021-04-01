#include <stdio.h>
int main(){

    double a=0.0, M[12][12];
    char T[2];
    int C,x,y,z,p=11,r=7;

    scanf("%s", &T);
    for(x=0;x<=11;x++){

        for(y=0; y<=11; y++)
            scanf("%lf", &M[x][y]);
    }

    for(z=1; z<=10;z++){

        if(z<=5){

            for(C=p; C<=11;C++)
                a+=M[z][C];
            p--;
        }
        else if(z>=6){

        for(C=r; C<=11; C++)
            a+=M[z][C];
        r++;
        }
    }
    if(T[0]=='S')
        printf("%.1lf\n",a);
    else if(T[0]=='M'){

        a=a/30.0;
        printf("%.1lf\n",a);
    }
    
    return 0;
}
