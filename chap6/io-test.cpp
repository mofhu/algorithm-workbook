// io test of cstdio and iostream
// Mo Frank Hu

#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

void scanf_getchar(){
    int a;
    char b;
    scanf("%d", &a);
    printf("%d\n", a);
    b = getchar(); // 读入末尾的 换行符 (ASCII 10)
    printf("%d\n", b);
    printf("%c\n", b);
}

void scanf_scanf_c(){
    int a;
    char b;
    scanf("%d", &a);
    printf("%d\n", a);
    scanf("%c", &b); // last \n
    printf("%c\n", b);
    scanf("%c", &b);  // next line a
    printf("%c\n", b);
    scanf("%c", &b);  // next line blank
    printf("%c\n", b);
}

void scanf_scanf_s(){
    int a;
    string b;
    scanf("%d", &a);
    printf("%d\n", a);
    cin >> b; // stops before blank
    cout << b; // output 'a'. i.e. ignore blank and NL
}

void scanf_getline(){
    int a;
    string b;
    scanf("%d\n", &a);
    printf("%d\n", a);
    //getline(b);
    getline(cin, b); // 读入的字符数组不含换行符
    cout << b;
    cout << "1" << endl;
    getline(cin, b);
    cout << b;
}

int main(){
    //scanf_getchar();
    scanf_getline();
    //scanf_scanf_c();
    //scanf_scanf_s();
}
