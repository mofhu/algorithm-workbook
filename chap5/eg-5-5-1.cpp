// UVa 12096 The SetStack Computer
// Mo Frank Hu

#include<iostream>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef set<int> Set;

int IDcache(Set s1, map<Set,int> id){
    if (id.count(s1) != 0)
        return id[s1];
    else {
        id[s1] = id.size();
        return id[s1];
    }
}

int main(){
    int kase;
    cin >> kase;
    while (kase--){
        int n;
        cin >> n;
        map<Set,int> id;
        stack<Set> s; // 这里的实现在书中是 stack<int>s; 同时建立一个 vector<set>, vector[id] = Set
        // stack<Set> 明显比 stack<int> 慢
        for (int i = 0; i < n; i++){
            string op;
            cin >> op;
            //cout << op << endl;
            if (op[0] == 'P'){
                //cout << IDcache(Set(), id);
                s.push(Set());
                //cout << s.size();
            }
            else if (op[0] == 'D'){
                Set top = s.top();
                s.push(top);
            }
            else {
                Set top, top2, x;
                top = s.top();
                s.pop();
                top2 = s.top();
                s.pop();
                if (op[0] == 'U'){
                    set_union(top.begin(), top.end(), top2.begin(), top2.end(), inserter(x, x.begin()));
                    id[x] = IDcache(x, id);
                    s.push(x);
                }
                else if (op[0] == 'I'){
                    set_intersection(top.begin(), top.end(), top2.begin(), top2.end(), inserter(x, x.begin()));
                    id[x] = IDcache(x, id);
                    s.push(x);
                }
                else {
                    top2.insert(id[top]);
                    id[top2] = IDcache(top2, id);
                    s.push(top2);
                }
            }
            Set top = s.top();
            cout << top.size() << endl;
        }
        cout << "***\n";
    }
    return 0;
}
