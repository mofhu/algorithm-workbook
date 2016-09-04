// UVa 673 Parentheses Balance
// Mo Frank Hu

#include<iostream>
#include<string>
#include<stack>
using namespace std;
string input;

int main (){
    int kase;
    cin >> kase;
    while(kase){
        kase--;
        cout << kase << endl;
        cin >> input;
        cout << input;
        int wrong = 0;
        stack<char> s;
        //cout << kase << endl;
        //cout << input.size() << endl;
        cout << input[0] << endl;
        for (int i = 0; i < input.size(); i++){
            cout << "for\n";
            cout << i;
            if (input[i] == '(' || input[i] =='[')
                s.push(input[i]);
            else {
                if (!s.empty() && ((s.top() == '(' == input[i] - 1) || (s.top() == '[' == input[i] - 2))){
                    wrong = 1;
                    break;
                }
                else s.pop();
            }
        }
        if (wrong == 0 && s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << input << endl;
    }
    return 0;
}
