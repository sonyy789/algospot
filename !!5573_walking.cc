#include <cstdio>
int T[1002][1002], A[1001][1001];
int D[2][2] = {{1,0},{0,1}};
int h,w,n,i,j,t;
int main(){
    scanf("%d%d%d",&h,&w,&n);
    T[1][1] = n;
    for(i = 1; i <= h; i++){
        for(j = 1; j <= w; j++){
            scanf("%d", &A[i][j]);
            int val = T[i][j]>>1;
            T[i+1][j] += val;
            T[i][j+1] += val;
            if(T[i][j]&1)
                A[i][j]? T[i][j+1]++:T[i+1][j]++;
        }
    }
    i = 1, j = 1;
    while(i <= h && j <= w){
        int is_odd = T[i][j]%2;
        if(is_odd) t = D[A[i][j]][0], j += D[A[i][j]][1];
        else t = D[(A[i][j]+1)%2][0], j += D[(A[i][j]+1)%2][1];
        i += t;
    }
    printf("%d %d",i,j);
}