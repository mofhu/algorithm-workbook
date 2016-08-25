#include<stdio.h>
#include<ctype.h>
#define maxn 100

/* note that getchar() not work in this problem.
 * seems that the blanks in the input file is unknown.
 * so the getchar() may get some blanks and WA. */

int main(){
    int kase;
    char s[100];
    scanf("%d", &kase);
    const char* e = "CHON";
    double mwe[] = {12.01, 1.008, 16.00, 14.01}; // float will not pass!
    while (kase--) {
        double mw = 0;
        int n = 0;
        double ele = 0;
        char c;
        scanf("%s",s);
        int i = 0;
        while ((c = s[i++]) != '\0') {
            if (isdigit(c)) {
                n = n*10 + c - '0';
            } else {
                if (n == 0) n++;
                if (ele) mw += ele * n;
                n = 0;
                for (int i = 0; i < 4; i++)
                    if (e[i] == c) ele = mwe[i]; // catch element mw
            }
        }
        if (n == 0) n++;
        if (ele) mw += ele * n;
        printf("%.3lf\n", mw);
        }
    return 0;
}
