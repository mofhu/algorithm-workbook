// UVa 1593 Alignment of Code
// Author: Mo Frank Hu
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

string ss[1010][100];
int maxlen[100];
int rowlength[1010];

string print(string s, int len){
    //cout << len - s.length();
    string s2 = s; 
    // have to init a new variable, not work using &s or s 
    // the += only work once.
    for (int i = 0; i < len - s.length(); i++)
        s2 += ' ';
    return s2;
}

int main(){
    int i = 0;
    string s;
    memset(maxlen, sizeof(maxlen), 0);
    while (getline(cin, s)){
        stringstream st(s);
        int j = 0;
        while (st >> ss[i][j]) {
            //cout << ss[i][j] << ' ' << i << ' ' << j << '-';
            maxlen[j] = max(maxlen[j], (int)ss[i][j].length());
            j++;
        }
        rowlength[i] = j;
        i++;
    }
    //for (int i = 0; i < 10; i++) {
    //    cout << maxlen[i] << ' ';
    //}
    //cout << ss[0][0];
    for (int j = 0; j < i; j++){
        int k = 0;
        for (; maxlen[k+1] != 0 && k < rowlength[j]-1; k++)
            cout << print(ss[j][k], maxlen[k]+1); // add a blank after it
        cout << ss[j][k] << endl; // WA due to wrong blank after final word in the line.
    }
    return 0;
}
