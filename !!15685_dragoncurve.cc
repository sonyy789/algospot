#include <cstdio>
#include <vector>
using namespace std;
int B[101][101];
void dragon(int x, int y, int d, int g){
    B[y][x] = 1;
    int py = y, px = x;
    if(d==0) px++;
    else if(d==1) py--;
    else if(d==2) px--;
    else py++;
    B[py][px] = 1;
    if(g == 0) return;
    vector<pair<int, int>> A;
    A.push_back({y,x}); A.push_back({py, px});
    while(g--){
        for(int i = A.size()-2; i >= 0; i--){
            x = px+(-A[i].first+py);
            y = py+(A[i].second-px);
            A.push_back({y,x});
            B[y][x] = 1;
        }
        py = y; px = x;
    }
    return;
}
int main(){
    int n, x, y, d, g;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d%d", &x, &y, &d, &g);
        dragon(x, y, d, g);
    }
    int ans = 0;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            if(B[i][j]&B[i][j+1]&B[i+1][j]&B[i+1][j+1]) ans++;
    printf("%d\n", ans);
}