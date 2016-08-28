//UVa 10763 Foreign Exchange
//Mo Frank Hu

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<utility>
using namespace std;

typedef pair<int,int> Pair;

int main(){
    int n;
    while (1){
        cin >> n;
        if (!n) break;
        map<Pair, int> dict;
        vector<Pair> keys;
        int a, b;
        for (int i = 0; i<n; i++){
            cin >> a >> b;
            if (a<b){
                if (!dict.count(Pair(a,b))) {
                    dict[Pair(a,b)] = 0;
                    keys.push_back(Pair(a,b));
                }
                dict[Pair(a,b)]++;
            }
            if (a>b){
                if (!dict.count(Pair(b,a)))  {
                    dict[Pair(b,a)] = 0;
                    keys.push_back(Pair(b,a));
                }
                dict[Pair(b,a)]--;
            }
        }
        string ans = "YES\n";
        for (int i = 0; i < keys.size(); i++)
            if (dict[keys[i]]) {
                ans = "NO\n";
                break;
            }
        cout << ans;
    }
    return 0;
}
