//UVa 10935 Throwing cards away I
//Mo Frank Hu

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


int main() {
    int n;
    while (1){
        cin >> n;
        if (!n) break;
        int i;
        queue<int> q;
        for (i=1; i<=n; i++)
            q.push(i);
        if (i>2)
            cout << "Discarded cards: ";
        else
            cout << "Discarded cards:\n";
        while (i > 2){
            cout << q.front();
            if (i > 3)
                cout << ", ";
            else
                cout << endl;
            q.pop();
            q.push(q.front());
            q.pop();
            i -= 1;
        }
        cout << "Remaining card: " << q.front() << endl;
    }
    return 0;
}
