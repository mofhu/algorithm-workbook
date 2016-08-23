#include<stdio.h>
#include<string.h>
#define maxn 1010

int main(){
    int kase = 0;
    int n;
    int ans[maxn], guess[maxn];
    while (scanf("%d", &n)){
        if (!n) break;
        kase += 1;
        for (int i = 0; i<n; i++) scanf("%d", &ans[i]); // read secret
        printf("Game %d:\n", kase);
        while (1){
            for (int i = 0; i<n; i++) {
                scanf("%d", &guess[i]);
            }
            if (!guess[0]) break;
            int count[10], ans_count[10], right_count[10];
            memset(count, 0, sizeof(count));
            memset(ans_count, 0, sizeof(count));
            memset(right_count, 0, sizeof(count));
            int a = 0, b = 0;
            for (int i = 0; i < n; i++){
                ans_count[ans[i]]++;
                count[guess[i]]++;
                if (ans[i] == guess[i]) {
                    right_count[ans[i]]++;
                }
            }
            for (int i = 1; i < 10; i++){
                a += right_count[i];
                if (count[i] > ans_count[i]) b += ans_count[i] - right_count[i];
                else b += count[i] - right_count[i];
            }
            printf("    (%d,%d)\n", a, b);
        }
    }
    return 0;
}
