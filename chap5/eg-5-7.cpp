// UVa 136 Ugly Numbers
// Author: Mo Frank Hu
#include<iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;
typedef long long LL;
#define maxn 1500

int main(){
    priority_queue <LL, vector<LL>, greater<LL> > pq;
    set <LL> s;

    LL i = 1;
    s.insert(i);
    pq.push(i);
    for (int j = 1; ; j++){
        i = pq.top();
        pq.pop();
        if (j == maxn){
            // cout << "The 1500's ugly number is " << i << ".\n";
            // above is a WA...
            cout << "The 1500'th ugly number is " << i << ".\n";
            break;
        }
        if (!s.count(2*i)){
            s.insert(2*i);
            pq.push(2*i);
        }
        if (!s.count(3*i)){
            s.insert(3*i);
            pq.push(3*i);
        }
        if (!s.count(5*i)){
            s.insert(5*i);
            pq.push(5*i);
        }
    }
    return 0;
}

