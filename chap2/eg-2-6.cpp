#include<stdio.h>
//#define LOCAL

int main(){
    int x, n = 0, kase = 0;

    while(scanf("%d", &n) == 1 && n){
        int min = 1000, max = -1000;
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            if(x < min) min = x;
            if(x > max) max = x;
            sum += x;
        }
        if(kase) printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, (float)sum / n);
    }
    return 0;

}
