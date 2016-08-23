#include<stdio.h>
#define maxn 90

int main(){
    int kase=0;
    scanf("%d", &kase);
    //printf("%d", kase);
    while (kase-- ) {
        char s[maxn];
        scanf("%s", s);
        //printf("%d", kase);
        int score = 0;
        int is_cont = 0;
        for (int i=0; s[i] != '\0'; i++){
            //printf("%c", s[i]);
            if (s[i] == 'O') {
                is_cont += 1;
                score += is_cont;
            }
            else is_cont = 0;
        }
        printf("%d\n", score);
    }
    return 0;
}
