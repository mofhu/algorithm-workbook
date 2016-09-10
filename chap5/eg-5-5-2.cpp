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
map<Set,int> id; // 如果把 map vector stack 都放在外面, 多个case 的重复集合效率更高.
vector<Set> Setcache;

int IDcache(Set s1){
    if (id.count(s1) != 0)
        return id[s1];
    else {
        id[s1] = id.size();
        Setcache.push_back(s1);
        return id[s1];
    }
}

int main(){
    int kase;
    cin >> kase;
    while (kase--){
        int n;
        cin >> n;
        stack<int> s; // 这里的实现在书中是 stack<int>s; 同时建立一个 vector<set>, vector[id] = Set, 使用 stack<Set> 需要更多空间.
        for (int i = 0; i < n; i++){
            string op;
            cin >> op;
            //cout << op << endl;
            if (op[0] == 'P'){
                //cout << IDcache(Set(), id);
                s.push(IDcache(Set()));
                //cout << s.size();
            }
            else if (op[0] == 'D'){
                int top = s.top();
                s.push(top);
            }
            else {
                Set top, top2, x;
                top = Setcache[s.top()];
                s.pop();
                top2 = Setcache[s.top()];
                s.pop();
                if (op[0] == 'U'){
                    set_union(top.begin(), top.end(), top2.begin(), top2.end(), inserter(x, x.begin())); // #define ALL(x) x.begin(), x.end() 还可define inserter, 可减少输入.
                    s.push(IDcache(x));
                }
                else if (op[0] == 'I'){
                    set_intersection(top.begin(), top.end(), top2.begin(), top2.end(), inserter(x, x.begin()));
                    s.push(IDcache(x));
                }
                else {
                    top2.insert(id[top]);
                    s.push(IDcache(top2));
                }
            }
            Set top = Setcache[s.top()];
            cout << top.size() << endl;
        }
        cout << "***\n";
    }
    return 0;
}
