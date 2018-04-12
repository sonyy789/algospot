#include <cstdio>
int t, n, m, k, ans, y, x, a, b, idx;
int M[1001][2];
int C[1001];
int dir[1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        idx = ans = 0;
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 0; i < n; i++)
            C[i] = 0;
        for(int i = 0; i < k; i++){
            scanf("%d %d %d %d", &y, &x, &a, &b);
            M[idx][0] = y; M[idx][1] = x;
            C[idx] = a; dir[idx] = b-1;
            idx++;
        }
        while(m--){
            for(int i = 0; i < idx; i++)
                M[i][0] += dy[dir[i]], M[i][1] += dx[dir[i]];
                
            int idx2 = 0;
            for(int i = 0; i < idx; i++){
                if(M[i][0] == -1) continue;
                int sum = C[i];
                int val = C[i];
                int newDir = dir[i];
                for(int j = i+1; j < idx; j++){
                    if(M[i][0] == M[j][0] && M[i][1] == M[j][1]){
                        M[j][0] = -1;
                        sum += C[j];
                        if(val < C[j]){
                            val = C[j];
                            newDir = dir[j];
                        }
                    }
                }
                M[idx2][0] = M[i][0];
                M[idx2][1] = M[i][1];
                C[idx2] = sum;
                dir[idx2] = newDir;
                if(M[i][0] == 0 || M[i][1] == 0 || M[i][0] == n-1 || M[i][1] == n-1){
                    C[idx2] /= 2;
                    if(C[idx2] == 0) continue;
                    if(dir[idx2] == 0 || dir[idx2] == 2) dir[idx2]++;
                    else dir[idx2]--;
                }
                idx2++;
            }
            idx = idx2;
        }
        for(int i = 0; i < idx; i++) ans += C[i];
        printf("#%d %d\n", z, ans);
        }
}