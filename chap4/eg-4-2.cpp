// UVa 489 Hangman Judge
// Mo Frank Hu
// Note: the problem is not the same as one described in aoapc-book
#include<stdio.h>
#include<string.h>
#define maxn 200
#define alphabet 30

char ans[maxn];
int left;
int count_wrong = 0;
char guessed[alphabet]; // guessed chars

void guess(char c){
    //printf("%c ", c);
    int flag = 0;
    if (guessed[c-'a']) return;
    else guessed[c-'a'] = 1;
    for (int i = 0; ans[i] != '\0'; i++) {
        if (c == ans[i]){
            ans[i] = '0';
            flag = 1;
            left--;
        }
    }
    if (!flag) count_wrong++;
}

int main(){
    int kase = 0;
    while (1) {
        scanf("%d", &kase);
        if (kase != -1) {
            count_wrong = 0; // a wrong int here lead to bug
            memset(guessed, 0, sizeof(guessed));
            printf("Round %d\n", kase);
            scanf("%s", ans);
            left = strlen(ans);
            //printf("%s", ans);
            char guess_str[maxn];
            scanf("%s", guess_str);
            for (int i = 0; guess_str[i] != '\0'; i++){
                if (!left) break;
                guess(guess_str[i]); // process guess
            }
            //printf("%s ", ans);
            //printf("%d", count_wrong);
            int flag = 0;
            for (int i = 0; ans[i] != '\0'; i++)
                if (ans[i] != '0') flag = 1;
            if (count_wrong >= 7)
                printf("You lose.\n");
            else if (!flag)
                printf("You win.\n");
            else
                printf("You chickened out.\n");
            //printf("%s", guess);
        } else
            break;
    }
    return 0;
}
