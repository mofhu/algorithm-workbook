// UVa 673 Parentheses Balance
// Mo Frank Hu

#include<iostream>
#include<string>
#include<stack>
using namespace std;
string input;

int main (){
    int kase;
    scanf("%d\n", &kase);  // 去掉 \n 的稳定方案
    while(kase){
        kase--;
        //cout << kase << endl;
        getline(cin, input);  // 空行可能为输入时的一个解决方法
        stack<char> s;
        //cout << input;
        int wrong = 0;
        //cout << kase << endl;
        //cout << input.size() << endl;
        //cout << input[0] << endl;
        for (int i = 0; i < input.size(); i++){
            //cout << wrong << "wrong" << endl;
            //cout << input[i];
            //cout << "for\n";
            //cout << i;
            if (input[i] == '(' || input[i] =='[')
                s.push(input[i]);
            else {
                if (s.empty()){
                    wrong = 1;
                    break;
                }
                else if ((s.top() == '(' && input[i] == ')') || (s.top() == '[' && input[i] == ']')){
                    s.pop();
                }
                else
                {
                    wrong = 1;
                    break;
                }
            }
            //cout << i;
        }
        if (wrong == 0 && s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
        //cout << input << endl;
    }
    return 0;
}
