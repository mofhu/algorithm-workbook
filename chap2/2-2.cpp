#include<stdio.h>

int main(){
    int a, b, c;
    int i = 0;
    while (scanf("%d%d%d", &a, &b, &c) == 3){
        //printf("%d%d%d\n", a,b,c);
        i++;
        int flag = 0;
        for (int n=10; n <= 100; n++){
            if ((n%3 == a) && (n%5 == b) && (n%7 == c)){  // bug: no bracket in line 12-14... no python style here in c/cpp
                flag = n;
                //printf("%d\n", n);
                break;
            }
        }
        if (flag != 0) printf("Case %d: %d\n", i, flag);
        else printf("Case %d: No answer\n", i);
    }
    return 0;
}
