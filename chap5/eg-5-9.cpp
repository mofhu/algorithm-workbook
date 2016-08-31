// UVa 1592 Database
// Mo Frank Hu

#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;

typedef pair<string,string> Cols;

int main(){
    int m, n;
    while (scanf("%d %d", &n, &m) && n > 0){
        //printf("%d %d", n, m);
        int row = 1;
        int dup = 0;
        map<Cols, int> sets[100]; // int is row number, (cols noted in replicate, only need row num)
        while (n-- > -1){
            //cout << n << endl;
            char c;
            int i = 0;
            string ss[10];
            string s = "";
            while((c = getchar()) != EOF){
                if (dup) continue;
                if (c != ',' && c != '\n')
                    ss[i] += c;
                else {
                    //cout << ss[i] << endl;
                    for (int j = 0; j < i; j++){
                        Cols p = Cols(ss[j], ss[i]);
                        if (sets[j*m + i].count(p)){
                            dup = 1;
                            //cout << '!'<<  ss[j] << ss[i] << endl;
                            //cout << '!'<<  j << i << endl;
                            printf("NO\n%d %d\n", sets[j*m+i][p], row);
                            printf("%d %d\n", j+1, i+1);
                            break;
                        } else {
                            sets[j*m + i][p] = row;
                        }
                        //cout << i << j << endl;
                    }
                    i++;
                    if (c == '\n') break;
                }
            }
            //cout << i << endl;
            if(i == m) row++;
        }
        if (!dup)
            printf("YES\n");
    }
    return 0;
}
