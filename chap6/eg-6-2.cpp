// UVa 514 Rails
// Mo Frank Hu

#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;
#define maxn 1010

int main() {
    int n;
    while (1){
        cin >> n;
        if (!n) break;
        //readline
        while (1) {
            queue<int> q;
            int seq[maxn];
            cin >> seq[0];
            if (!seq[0]){
                cout << endl;
                break;
            }
            for (int i=1; i < n; i++)
                cin >> seq[i];
            for (int i=1; i <= n; i++)
                q.push(i);
            int out;
            stack<int> s;
            string output = "Yes\n";
            for (int i = 0; i < n; i++){
                out = seq[i];
                if (!q.empty() && out > q.front()){
                    while (out > q.front()){
                        s.push(q.front());
                        q.pop();
                    }
                    q.pop();
                }
                else if (!q.empty() && out == q.front())
                    q.pop();
                else if (!s.empty() && out == s.top())
                    s.pop();
                else {
                    output = "No\n";
                    break;
                }
            }
            cout << output;
        }
    }
}
