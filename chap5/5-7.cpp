//UVa 12100 Printer Queue
//Mo Frank Hu

#include<iostream>
#include<queue>
using namespace std;

int main() {
    int kase;
    cin >> kase;
    while (kase--){
        int m, n;
        cin >> n >> m;
        int d;
        queue<int> q;
        priority_queue<int> pq;
        for (int i = n; i>0; i--){ // init
            cin >> d;
            //cout << d << '-';
            q.push(d);
            pq.push(d);
        }
        int time = 0;
        while (1){
            //cout << q.front() << pq.top() << m << time <<endl;
            if (q.front() == pq.top()){
                time++;
                if (m == 0){
                    cout << time << endl;
                    break;
                } else {
                    m--;
                    q.pop();
                    pq.pop();
                }
            }else {
                if (m == 0){
                    m = q.size() - 1;
                    q.push(q.front());
                    q.pop();
                }else {
                    m--;
                    q.push(q.front());
                    q.pop();
                }

            }
        }
    }
    return 0;
}

