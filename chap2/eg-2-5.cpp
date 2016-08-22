#include<stdio.h>
//#define LOCAL

int main(){
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int x, n = 0, sum = 0;
    int min = 1000, max = -1000;

    while(scanf("%d", &x) == 1){
        if(x < min) min = x;
        if(x > max) max = x;
        sum += x;
        n++;
    }
    printf("%d %d %.3f\n", min, max, (float)sum / n);

    return 0;

}
