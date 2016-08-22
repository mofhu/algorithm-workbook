#include<stdio.h>

int main(){
    int a, b, c;
    int kase = 0;
    while (1){
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 && b == 0 && c ==0) break;
        else{
            kase++;
            int mod = a%b;
            printf("Case %d: %d.", kase, a/b);
            for (int i = 1; i<=c-1; i++){
                mod *= 10;
                printf("%d", mod/b);
                mod %= b;
            }
            mod *= 10;
            int final_dig = mod/b;
            mod %= b;
            if (mod*10 / b > 5) final_dig++;
            printf("%d\n", final_dig);
        }
    }
    return 0;
}
