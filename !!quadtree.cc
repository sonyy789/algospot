#include <cstdio>
int A[65][65], cnt = 0;
char ans[10000];
void solve(int y, int x, int n)
{
    int temp = A[y][x]+A[y-n][x-n]-A[y-n][x]-A[y][x-n];
    if(temp == 0) {ans[cnt++] = '0'; return;}
    else if(temp == n*n) {ans[cnt++]='1'; return;}
    ans[cnt++]='(';
    n/=2;    
    for(int i = n; i >=0; i-= n)
        for(int j = n; j>=0; j-=n)
            solve(y-i, x-j,n);
    ans[cnt++]=')';
}
int main()
{
    int n;
    char str[65];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        for(int j =1; j <= n; j++)
            A[i][j] = str[j-1]-'0'+ (A[i-1][j]+A[i][j-1]-A[i-1][j-1]);
    }
    solve(n,n,n);
    printf("%s\n", ans);
}