#include <cstdio>
int main(){
    int n, X[10002], Y[10002];
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        scanf("%d%d",&X[i],&Y[i]);
    Y[0] = Y[n]; Y[n+1] = Y[1];
    for(int i = 1; i <= n; i++)
        sum += ((long long)X[i]*Y[i+1])-((long long)X[i]*Y[i-1]);
    if(sum < 0) sum = -sum;
    double ans = sum/2;
    if(sum%2) ans+=0.5;
    printf("%.1f", ans);
}