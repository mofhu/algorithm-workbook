#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10010;

int s[maxn];

int main(){
    int kase = 0;
    int n, q;
    while (1){
        scanf("%d %d\n", &n, &q);
        if (n == 0 && q == 0) break;
        printf("CASE# %d:\n", ++kase);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        sort(s, s + n);
        for(int i = 0; i < q; i++) {
            int j;
            cin >> j;
            //cout << *lower_bound(s, s+n, j);
            if( *lower_bound(s, s+n-1, j) == j)
                printf("%d found at %ld\n", j, lower_bound(s, s+n, j)-s+1);
            else
                printf("%d not found\n", j);
        }

    }
    return 0;
}
