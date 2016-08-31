//UVa 540 Team Queue
//Mo Frank Hu
//似乎 q 开在main()函数里会bug

#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

int main(){
    int kase = 0;
    int n;
    int qi = 0;
    while (1){
        cin >> n;  // num of teams
        if (!n) break;
        kase++;
        cout << "Scenario #" << kase << '\n';
        map<int, int> m; //guy, queue
        int people;
vector< queue<int> > q;
        while (n--) {
            int num_qi;
            queue<int>q0;
            q.push_back(q0);
            cin >> num_qi;
            while (num_qi--){
                cin >> people;
                //cout << people << ' ';
                m[people] = qi;
            }
            qi++;
            //cout << endl;
        }
        //cout << q.size();
        queue<int> qq;
        string s;
        int qp;
        while (1){
            cin >> s;
            cout << s << endl;
            if (s[0] == 'E') {
                cin >> people;
                cout << people << m[people] << endl;
                q[m[people]].push(people);
                cout << people << m[people] << endl;
                if (q[m[people]].size() == 1){
                    qq.push(m[people]);
                }
                cout << people << m[people] << endl;
            }
            else if (s[0] == 'D'){
                int front_queue;
                front_queue = qq.front();
                cout << q[front_queue].front() << endl;
                q[front_queue].pop();
                if (q[front_queue].empty())
                    qq.pop();
            }
            else {
                cout << endl;
                break;
            }
        }
    }
    return 0;

}
