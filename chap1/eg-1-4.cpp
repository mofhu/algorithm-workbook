#include<stdio.h>

int main(){
    int n, m;
    int x, y;  // x: chicken; y: rabbit
    scanf("%d%d", &n, &m);
    x = (4*n - m) / 2;
    y = (m - 2*n) / 2;
    if (x>0 && y>0 && m%2 == 0)
        printf("%d %d\n", x, y);
    else
        printf("No answer\n");
}
