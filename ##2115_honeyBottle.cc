#include <cstdio>
int M[11][11];
int R[11][11];
int t, n, m, c;
int max(int a, int b ){return a>b?a:b;}
int getSum(int y, int x, int yy, int xx, int val, int sum){
    if(val < 0) return 0;
    if(y > yy || x > xx || val == 0) return sum;
    int ret = getSum(y, x+1, yy, xx, val, sum);
    ret = max(ret, getSum(y, x+1, yy, xx, val-M[y][x], sum+M[y][x]*M[y][x]));
    return ret;
}
int main(){
    scanf("%d", &t);
    for(int z=1; z<=t; z++){
        scanf("%d %d %d", &n, &m, &c);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &M[i][j]);
                R[i][j] = 0;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= n-m; j++)
                R[i][j] = getSum(i, j, i, j+m-1, c, 0);
        int maxVal1, maxVal2, ans;
        ans = maxVal1 = maxVal2 = 0;
        for(int i = 0; i < n; i++){
            maxVal2 = 0;
            for(int j = 0; j <= n-m; j++){
                maxVal2 = max(maxVal2, R[i][j]);
                ans = max(ans, maxVal1+R[i][j]);
                for(int k = j+m; k <= n-m; k++){
                    ans = max(ans, R[i][j]+R[i][k]);
                }
            }
            maxVal1 = max(maxVal1, maxVal2);
            maxVal2 = 0;
        }
        printf("#%d %d\n", z, ans);
    }
}