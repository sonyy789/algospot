#include <cstdio>
int arr[100];
int t, n, limit, i, j, k;
bool flag[4000];
int main(){
    for(i = 1; i <= 45; i++)
        arr[i] = (i*(i+1))/2;
    for(i = 1; i <= 45; i++)
        for(j = 1; j <= 45; j++)
            for(k = 1; k <=45; k++)
                flag[arr[i]+arr[j]+arr[k]] = true;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", flag[n]?1:0);
    }
}