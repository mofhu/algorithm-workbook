// UVa 1594 Ducci Sequence
// Mo Frank Hu

#include<iostream>
#include<cstring>
#include<cmath>
#define maxn 20
#define maxiter 1010
using namespace std;

int ss[maxiter][maxn];

int is_equal(int a[], int b[], int len){
    //compare length and return
    //for (int i = 0; i < len; i++) {
    //    cout << a[i] << 'a';
    //}
    //cout << '\n';
    //for (int i = 0; i < len; i++) {
    //    cout << b[i] << 'b';
    //}
    //cout << '\n';
    for (int i=0; i < len; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

void act(int row, int n){
    int d0 = ss[row][0];
    int i = 0;
    for (; i < n - 1; i++){
        ss[row + 1][i] = abs(ss[row][i+1] - ss[row][i]);
    }
    ss[row+1][i] = abs(ss[row][i] - d0);
}

int main(){
    int kase;
    cin >> kase;
    while (kase--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> ss[0][i];

        int all_zero[maxn];
        memset(all_zero,0, sizeof(all_zero));
        int iter = 0;
        int flag = 0;
        while ( !flag){
            act(iter, n);
            iter++;
            if (is_equal(ss[iter], all_zero, n)) {
                cout << "ZERO\n";
                flag = 1;
                break;
            }
            for (int i = 0; i < iter; i++){
                if (is_equal(ss[i], ss[iter], n)){
                    cout << "LOOP\n";
                    flag = 1;
                    break;
                }
            }
        }
    }
    return 0;
}
