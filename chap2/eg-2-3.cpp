#include<stdio.h>

int main(){
    double sum = 0;
    int i = 1;
    do{
        if (i%4 == 1)
            sum += 1.0 / i;
        else
            sum -= 1.0 / i;
        i += 2;
    }while(1.0 / i > 1e-6);

    printf("%.6f\n", sum);

    return 0;
}

