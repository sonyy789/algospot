#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int tc, z, n, s_idx, p_idx, ans;
int A[2][11], C[11], D[2][11], L[2];
struct Point{
    int y, x;
};
Point P[11], S[2];
int solve(int idx, int size){
    if(size == 0) return 0;
    sort(A[idx], A[idx]+size);
    queue<int> q;
    int i, a;
    for(i = 0, a = 0;;i++){
        while(!q.empty()&&q.front()<=i) q.pop();
        if(a == size && q.empty()) break;
        while(q.size() < 3 && a < size && A[idx][a] < i) q.push(i+L[idx]), a++;
    }
    return i;
}
void perm(int idx){
    int i;
    if(idx == p_idx){
        int size1 = 0, size2 = 0;
        for(i = 0; i < p_idx; i++){
            if(C[i]) A[1][size2++] = D[1][i];
            else A[0][size1++] = D[0][i];
        }
        ans = min(ans, max(solve(0, size1), solve(1, size2)));
        return;
    }
    for(i = 0; i < 2; i++)
        C[idx] = i, perm(idx+1);
}
int main(){
    int i, j, data;
    scanf("%d", &tc);
    for(int z=1;z<=tc;z++){
        s_idx = p_idx = 0;
        ans = 1e9;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++){
                scanf("%d", &data);
                if(data == 1) P[p_idx++] = {i,j};
                else if(data > 1) S[s_idx] = {i,j}, L[s_idx++] = data;
            }
        
        for(i = 0; i < 2; i++)
            for(j = 0; j < p_idx; j++){
                D[i][j] = abs(S[i].y-P[j].y)+abs(S[i].x-P[j].x);
            }
                
        perm(0);
        printf("#%d %d\n", z, ans);
    }
}