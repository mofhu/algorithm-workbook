#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    const int maxn = 10000;
    int s[maxn];
    int kase = 0, n, q;
    while (1){
        cin >> n >> q;
        if (!n) break;
        kase++;
        printf("Case# %d:\n",kase);
        for (int i = 0; i < n; i++) cin >> s[i]; // init
        sort(s, s + n);
        for (int i = 0; i < q; i++) {
            int p;
            cin >> p;
            int pos;
            pos = lower_bound(s, s+n, p) - s;
            if (s[pos] == p) printf("%d found at %d\n", p, pos+1);
            else printf("%d not found\n", p);
        }
    }
    return 0;
}
