// UVa 442 Matrix Chain Multiplication
// Mo Frank Hu
// 对于单个空白字符 '\n', cstdio 的 getline 会读入空行, 可能造成多循环一次
// 而用 cin >> string 读入到 string 则安全略过该行.

#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<sstream>
#include<map>
using namespace std;
const int MAXN = 30;

struct Matrix {
    int r, c;
    Matrix(int r=0, int c=0):r(r), c(c) {}
};

Matrix m[MAXN];
map<char, int> id;

int main (){
    int n;
    cin >> n;
    string line;
    for (int i = 0; i < n; i++){
        string c;
        int row, col;
        cin >> c >> row >> col;
        //cout << c;
        id[c[0]] = i;
        m[i] = Matrix(row, col);
    }
    while (cin >> line){
        //cout << line << ';';
        stack<Matrix> s;
        long long tot = 0; // store total Multiplication
        for (int i = 0; line[i] != '\0'; i++){ // getline get last '\0', no '\n' at the end
            //cout << line[i];
            if (line[i] == ')'){
                Matrix a, b;
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                if (a.c != b.r) {
                    cout << "error\n";
                    tot = -1;
                    break;
                }
                tot += a.r * a.c * b.c;
                s.push(Matrix(a.r, b.c));
            }
            else if (line[i] == '(') continue;
            else {
                //cout << line[i];
                s.push(m[id[line[i]]]);
            }
        }
        if (tot != -1)
            cout << tot << endl;
    }
}
