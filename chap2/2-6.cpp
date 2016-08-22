#include<stdio.h>

int main(){
    for (int a = 1; a < 4; a++)
        for (int b = 1; b <= 9; b++){
            if (b == a) continue;
            else for (int c = 1; c <= 9; c++){
                    if (c == a || c == b) continue;
                    else {
                        int abc = 100*a + 10*b + c;
                        int def = 2 * abc;
                        int ghi = 3 * abc;
                        int d = def / 100;
                        int e = (def%100) / 10;
                        int f = def % 10;
                        int g = ghi / 100;
                        int h = (ghi%100) / 10;
                        int i = ghi % 10;
                        if (e == f || e == d || f == d ) continue;
                        if (g == h || h == i || i == g ) continue;
                        if (g > 9) continue;
                        if (a == e || a == f || a == h || a == i) continue;
                        if (b == d || b == e || b == f || b == g ||
                                b == h || b == i) continue;
                        if (c == d || c == e || c == f || c == g ||
                                c == h || c == i) continue;
                        if (d == h || d == i) continue;
                        if (e == g || e == h || e == i) continue;
                        if (f == g || f == h || f == i) continue;
                        else
                            printf("%d %d %d\n", abc, def, ghi);
                    }
            }
        }
    return 0;
}
