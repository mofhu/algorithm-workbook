#include<stdio.h>

int main(){
    long long n;
    scanf("%lld", &n);

    int i = 0;
    while(n != 1){
        if(n%2 == 1) n = 3*n + 1;
        else n /= 2;
        i++;
    }
    printf("%d\n", i);
    return 0;
}
