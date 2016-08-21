#include<stdio.h>

int main(){
    int n;
    float sum;
    scanf("%d", &n);
    if (95*n > 300) sum = 95*n*0.85;
    else sum = 95*n;
    printf("%.2f\n", sum);
    return 0;
}
