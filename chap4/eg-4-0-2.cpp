#include<stdio.h>

int sum(int* s, int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum;
}

int main(){
    int a[] = {2, 3, 4, 5};
    int s = sum(a, 4);
    printf("%d\n", s);
    return 0;
}
