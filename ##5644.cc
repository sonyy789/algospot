#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define MAX 10
using namespace std;
int t, z, n, m, x, y, c;
int P[10], M[2][101];
int D[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    int i, j, k;
    scanf("%d", &t);
    for(z=1;z<=t;z++){
        int ans = 0;
        int ax = 1, ay = 1, bx = MAX, by = MAX;
        map<pair<int, int>, int> mp;
        
        scanf("%d%d", &m, &n);
        for(i = 0; i < 2; i++)
            for(j = 1; j <= m; j++)
                scanf("%d", &M[i][j]);
        for(i = 0; i < n; i++){
            scanf("%d%d%d%d", &x, &y, &c, &P[i]);
            mp[{y,x}] |= (1<<i);
            for(j = y-c; j <= y+c; j++){
                if(j < 1 || j > MAX) continue;
                for(k = x-c; k <= x+c; k++){
                    if(k < 1 || k > MAX) continue;
                    if(abs(y-j)+abs(x-k) <= c) mp[{j,k}] |= (1<<i);
                }
            }
        }
        for(i = 0; i <= m; i++){
            ay += D[M[0][i]][0], ax += D[M[0][i]][1];
            by += D[M[1][i]][0], bx += D[M[1][i]][1];
            vector<pair<int, int>> A, B;
            int val_a = mp[{ay, ax}], val_b = mp[{by, bx}];
            int a;
            for(j = 0, a = 1; j < n; j++, a<<=1){
                if(val_a&a) A.push_back({P[j],j});
                if(val_b&a) B.push_back({P[j],j});
            }
            sort(A.begin(), A.end(), greater<pair<int,int>>());
            sort(B.begin(), B.end(), greater<pair<int,int>>());
            if(A.size() == 0 && B.size() == 0);
            else if(A.size() == 0) ans += B[0].first;
            else if(B.size() == 0) ans += A[0].first;
            else if(A[0].second != B[0].second) ans += (A[0].first+B[0].first);
            else{
                ans += A[0].first;
                if(A.size() == 1 && B.size() == 1);
                else if(A.size() == 1) ans += B[1].first;
                else if(B.size() == 1) ans += A[1].first;
                else ans += max(A[1].first, B[1].first);
            }
        }
        printf("#%d %d\n", z, ans);
    }
}