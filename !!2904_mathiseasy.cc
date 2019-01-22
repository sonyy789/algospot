#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int p_idx;
bool visit[1001];
int A[200], prime[200];
int C[101][200];
int main(){
    int n, i, j, k, val;
    // prime
    prime[++p_idx] = 2;
    for(i = 3; i <= 1e3; i+=2){
        if(visit[i]) continue;
        prime[++p_idx] = i;
        k = 2*i;
        for(j = i+k; j <= 1e3; j+=k) visit[j] = true;
    }
    
    scanf("%d", &n);
    int tmp = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &val);
        for(j = 1; j <= p_idx && val!=1; j++){
            int p_num = prime[j];
            while((val%p_num)==0){
                val /= p_num;
                C[i][j]++; A[j]++;
            }
        }
        if(val){
            if(tmp == 0) tmp = val;
            else if(tmp != val) tmp = -1;
        }
    }
    int ans = 1, cnt = 0;
    if(tmp > 0) ans = tmp;
    for(i = 1; i <= p_idx; i++){
        if(A[i] < n) continue;
        A[i] /= n;
        ans *= pow(prime[i],A[i]);
        for(j = 1; j <= n; j++){
            int inv = A[i]-C[j][i];
            if(inv < 0) continue;
            cnt += inv;
        }
    }
    printf("%d %d\n", ans, cnt);
}