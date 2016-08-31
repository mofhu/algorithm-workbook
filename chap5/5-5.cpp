//UVa 10391 Compound Words
//Mo Frank Hu
//Note: 2x iteration - TLE: too slow
//用多个集合加速, 只有完整序列属于后一个词才可能为 first word.
//然而上面的算法还是不够快
//改用一个vector 保存目前可用的首序列(也可用栈, 但考虑到栈反向遍历成本大, 改用了vector)
//然后维护并通过vector 用 minus 操作搜索尾序列

#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
set<string> s, s_begin, s_final;
vector<string> first;

int contain(string a, string b){
    int i = a.length();
    //cout << a << ' ' << b << endl;
    //cout << a.length() << b.length();
    if (a.length() > b.length()) return 0;
    for (int j = 0; j < i; j++) {
        if (a[j] != b[j])
            return 0;
    }
    //cout << a << b;
    return 1;
}

string endstring(string a, string b){
    // return b - a;
    string b_a = "";
    for (int i = a.length(); i < b.length(); i++)
        b_a += b[i];
    return b_a;
}

int main (){
    string a, a0, b;
    while (cin >> a)
        s.insert(a);  // init

    set <string>::iterator it, it2;
    vector <string>:: iterator vit;
    it = s.begin();
    a0 = *(it);
    it++;
    for (; it != s.end(); it++){
        a = *it;
        if (contain(a0, a)){
            first.push_back(a0);
        }
        //cout << a0 << ' '<< a;
        //cout << first.size() << "size\n";
        for (int i = first.size(); i > 0; i--){
            //cout << first[i-1] << "first\n";
            if (contain(first[i-1], a)) {
                //cout << "contain!";
                b = endstring(first[i-1], a);
                //cout << b << endl;
                if (s.count(b)) {
                    //cout << b <<'!';
                    s_final.insert(a);
                }
            } else {
                first.pop_back();
            }
        }
        a0 = a;
    }

    for (it = s_final.begin(); it != s_final.end(); it++)
        cout << *it << endl;

    return 0;
}
