#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using  namespace std;
int H[101][2], C[15][2], c;
vector<vector<pair<int, int>>> D; 
int del[15];
int hIdx, cIdx;
int comb(int idx, int depth){
    if(depth == c){
        int sum = 0;
        for(int i = 0; i < hIdx; i++){
            for(int j = 0; j < cIdx; j++){
                int f = 1;
                for(int k = 0; k < c; k++)
                    if(del[k] == D[i][j].second) {f=0; break;}
                if(f){
                    sum += D[i][j].first;
                    break;
                } 
            }
        }
        return sum;
    }
    int ret = 1e9;
    for(int i = idx; i < cIdx; i++){
        del[depth] = i;
        int res = comb(i+1, depth+1);
        ret = ret < res ? ret: res;
    }
    return ret;
}
int main(){
    int n, m, a;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%d", &a);
            if(a==1) H[hIdx][0] = i, H[hIdx++][1] = j;
            else if(a==2) C[cIdx][0] = i, C[cIdx++][1] = j;
        }
    c = cIdx-m;
    D = vector<vector<pair<int, int>>>(hIdx);
    for(int i = 0; i < hIdx; i++)
        for(int j = 0; j < cIdx; j++)
           D[i].push_back({abs(H[i][0]-C[j][0])+abs(H[i][1]-C[j][1]), j});
    for(int i = 0; i < hIdx; i++)
        sort(D[i].begin(), D[i].end());
    printf("%d",comb(0, 0));
}