#include <cstdio>
#include <queue>
using namespace std;
int T[1001], A[10], AA[10], AAA[10], B[10], BB[10];
int main(){
    int t, n, m, k, a, b;
    scanf("%d", &t);
    for(int z = 1; z<=t;z++){
        int ans = 0;
        queue<pair<int, int>> q;
        scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);
        int idx1 = 1;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &B[i]);
        for(int i = 1; i <= k; i++) scanf("%d", &T[i]);
        T[k+1] = 1;
        while(1){
            for(int i = 1; i <= n; i++){
                if(AA[i] == 0){
                    if(AAA[i] > 0){
                        q.push(make_pair(i,AAA[i]));
                        AAA[i] = 0;
                    }
                    if(T[idx1] == 0){
                        AA[i] = A[i];
                        AAA[i] = idx1;
                        idx1++;
                    }
                }
            }
            for(int i = 1; i <= m; i++){
                if(q.empty()) break;
                if(BB[i] == 0){
                    BB[i] = B[i];
                    if(q.front().first == a && i == b){ 
                        ans += q.front().second;
                    }
                    q.pop();
                }
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++) if(AA[i] > 0) AA[i]--, cnt++;
            for(int i = 1; i <= m; i++) if(BB[i]> 0) BB[i]--, cnt++;
            for(int i = idx1; i <= k; i++) if(T[i]> 0) T[i]--, cnt++;
            if(cnt == 0) break;
        }
        if(ans == 0) ans = -1;
        printf("#%d %d\n", z, ans);
    }
}