#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxline=60;

int main(){
    int n;
    while(cin >> n){
        if (n){
            string ss[65];
            for (int i = 0; i < 60; i++)
                cout << '-';
            cout << endl;
            int maxlen = 0;
            //cout << n << endl;
            string s;
            for (int i = 0; i < n; i++) { // init vector
                cin >> s;
                ss[i] = s;
                if (s.length() > maxlen) maxlen = s.length();
            }
            sort(ss, ss+n);
            //cout << maxlen << endl;
            int cols = (maxline+2)/(maxlen+2);
            int rows = n / cols;
            if (n%cols) rows++;
            int col_nums[65];
            //cout << rows << "r,c" << cols << endl;
            for (int i = 0; i < cols; i++){
                if (!i)
                    col_nums[i] = 0;
                else if (n%cols == 0)
                    col_nums[i] = col_nums[i-1] + rows;
                else
                    col_nums[i] = col_nums[i-1] + rows;
                //cout << col_nums[i] << ' ' << endl;
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++){
                    string t = ss[i + col_nums[j]];
                    if (i + col_nums[j]> n-1) break;
                    cout << t ; //< i + col_nums[j] ;
                    if (j == cols - 1 || i + col_nums[j] + rows> n-1){
                        for (int k = t.size(); k < maxlen; k++)
                            cout << ' ';
                        continue;
                    }
                    for (int k = t.size(); k < maxlen+2; k++)
                        cout << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}
