#include <cstdio>
int n, m, i, j, a, b, a_idx;
int A[1001], T[1001], IN[1001];
bool flag;
bool adj[1001][1001];
int main(){
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d", &a);
        for(i = 0; i < a; i++){
            scanf("%d", &T[i]);
            for(j = i-1; j >= 0; j--){
                if(adj[T[j]][T[i]]) continue;
                adj[T[j]][T[i]] = true;
                IN[T[i]]++;
            }
        }
    }
    while(a_idx < n){
        flag = true;
        for(i = 1; i <= n; i++){
            if(IN[i] == 0){
                flag = false;
                IN[i] = -1;
                A[++a_idx] = i;
                for(j = 1; j <= n; j++)
                    if(adj[i][j]) IN[j]--;
            }    
        }
        if(flag) break;
    }
    if(flag) a_idx = 1, A[1] = 0;
    for(i = 1; i <= a_idx; i++)
        printf("%d\n", A[i]);
}