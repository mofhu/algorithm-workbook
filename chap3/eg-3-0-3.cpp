#include<stdio.h>
#include<string.h>

#define maxn 10
int a[maxn][maxn];
int main(){
    int n = 0;
    int i = 1;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    int x = n-1;
    int y = 0;
    a[x][y] = 1;
    while (i < n*n){
        while (y<n-1 && !a[x][y+1]) a[x][++y] = ++i;
        while (x>0 && a[x-1][y] == 0) a[--x][y] = ++i;
        //printf( "x y i %d %d %d\n", x,y,i );
        while (y>0 && a[x][y-1] == 0) a[x][--y] = ++i;
        //printf( "x y i %d %d %d\n", x,y,i );
        while (x<n-1 && a[x+1][y] == 0) a[++x][y] = ++i;
        //printf( "x y i %d %d %d\n", x,y,i );
        //printf("%d ", i);
        //if use i++, have to add an extra line input n^2
    }
    for (int y=0; y<n; y++){
        for (int x=0; x<n; x++) printf("%3d ", a[x][y]);
        printf("\n");
    }
    return 0;
}
