#include<stdio.h>
#define maxn 200

char ans[maxn];
int count_wrong = 0;
int len_ans = 0;  // length of answer

int main(){
    int kase = 0;
    scanf("%d", &kase);
    if (kase != -1) {
        printf("%d\n", kase);
        len_ans = scanf("%s", ans);
        printf("%d", len_ans);
        char guess[maxn];
        scanf("%s", guess);

    } else {
        return 0;
    }
}
