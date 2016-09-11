// UVa 1595 Symmetry
// Mo Frank Hu

#include<iostream>
#include<utility>
#include<set>
using namespace std;
typedef pair<int, int> Point;

int main() {
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        int x, y;
        set <Point> s;
        for (int i = 0; i < n; i++){
            cin >> x >> y;
            Point a(x,y);
            s.insert(a);
        }
        //cout << s.size() << endl;
        Point minp, maxp;
        set<Point>::iterator it = s.begin();
        minp = *it;
        it = s.end();
        maxp = *(--it); // get last element
        int mid = minp.first + maxp.first; // use 2* mid to avoid float
        it = s.begin();
        int i = 0, flag = 1;
        // only need to check first half + 1 element's pair
        for (; i < s.size() / 2 + 1; i++){
            Point mirror(mid - (*it).first, (*it).second);
            if (s.count(mirror) == 0) {
                flag = 0;
                break;
            }
            it++;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
