// UVa 253 Cube painting
// Author: Mo Frank Hu
// half-finished here
//
#include<stdio.h>
#include<string.h>
#define maxn 20


int main(){
    char s[maxn];
    while (scanf("%s", s) == 1){
        printf("%s\n", s);
        char s1[maxn], s2[maxn];
        strcpy(s2, &s[6]);
        for (int i = 0; i < 6; i++) {
            s1[i] = s[i];
        }
        s1[6] = '\0';
        printf("%s, %s ", s1, s2);

    }
    return 0;

}
