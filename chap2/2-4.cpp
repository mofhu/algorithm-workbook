#include<stdio.h>

int main(){
    int n, m;
    int count = 0;
    while (1) {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;
        else {
            count++;
            float sum = 0;
            for (int i = n; i <= m; i++)
                sum += 1.0 / i / i;
            printf("Case %d: %.5f\n", count, sum);

        }

    }
    return 0;
}
