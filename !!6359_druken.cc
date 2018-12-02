#include <cstdio>
int main(){
    int i, j, t, n;
    bool room[101];
    scanf("%d", &t);
    for(int r = 0; r < t; r++){
        int ans = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; i++) room[i] = true;
        for(i = 2; i <= n; i++)
            for(j = i; j <=n; j+=i)
                room[j] = !room[j];
        for(i = 1; i <= n; i++)
            if(room[i]){
                printf("%d ", i);
            }
        printf("%d\n", ans);
    }
}