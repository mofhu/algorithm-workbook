#include<stdio.h>

int main(){
    char s;
    int flag = 1;
    while ((s = getchar()) != EOF) {
        if (s == '"'){
            if (flag) printf("``");
            else printf("''");
            flag = !flag;
        }
        else printf("%c", s);
    }
    return 0;
}
