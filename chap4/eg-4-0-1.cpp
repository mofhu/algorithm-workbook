#include<stdio.h>

void swap(int* a, int* b){
    int t = *a; *a = *b; *b = t;
    printf("swap %d %d\n", *a, *b);
}

int main(){
    int a = 3; int b = 4;
    printf("main %d %d\n", a, b);
    swap(&a, &b);
    printf("main %d %d\n", a, b);
    return 0;
}
