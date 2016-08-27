#include<iostream>
#include<cstring>

using namespace std;

int s0[5];

void print(int s[], int n){
    for (int i = 0; i < n; i++)
        cout << s[i] << ',';
    cout << endl;
}

int main() {
    int n = 10;
    int s[n];
    print(s0, 5);
    print(s, 10);
    memset(s, -1, sizeof(s));
    print(s, 10);
    return 0;
}
