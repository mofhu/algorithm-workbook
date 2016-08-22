#include<stdio.h>
#include<math.h>

int main(){

    for(int a=1; a<=9; a++)
        for(int b=0; b<=9; b++){
            float n = sqrt(a*1100+b*11);
            int m = floor(n+0.5);  // solve float error
            if(a*1100+b*11==m*m) printf("%d\n", m*m);
        }

    return 0;
}
