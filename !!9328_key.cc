#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Point{
    int y,x;
};
char key[101], B[103][103];
bool has_key[27], visit[103][103];
int D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int t,h,w;
vector<Point> door[27];
int main(){
    int i, j;
    scanf("%d", &t);
    while(t--){
        memset(&visit, false, sizeof(visit));
        memset(&has_key, false, sizeof(has_key));
        memset(&B, 0, sizeof(B));
        for(i = 0; i < 27; i++) door[i].clear();
        scanf("%d%d",&h,&w);
        for(i = 1; i <= h; i++)
            scanf("%s", B[i]+1);
        scanf("%s", key+1);
        for(i = 1; key[i] != '\0' && key[i] != '0'; i++){ 
            has_key[key[i]-'a'] = true;
        }
        queue<Point> q;
        visit[0][0] = true;
        q.push({0,0});
        int ans = 0;
        while(!q.empty()){
            int y = q.front().y;
            int x = q.front().x;
            q.pop();
            for(i = 0; i < 4; i ++){
                int ny = y+D[i][0], nx = x+D[i][1];
                if(ny < 0 || nx < 0 || ny > h+1 || nx > w+1) continue;
                if(visit[ny][nx] || B[ny][nx] == '*') continue;
                visit[ny][nx] = true;
                if('A' <= B[ny][nx] && B[ny][nx] <= 'Z'){
                    if(has_key[B[ny][nx]-'A']) q.push({ny,nx});
                    else door[B[ny][nx]-'A'].push_back({ny,nx});
                }else if('a' <= B[ny][nx] && B[ny][nx] <= 'z'){
                    q.push({ny,nx});
                    int idx = B[ny][nx]-'a';
                    if(has_key[idx]) continue;
                    else{
                        has_key[idx] = true;
                        for(j = 0; j < door[idx].size(); j++)
                            q.push({door[idx][j].y, door[idx][j].x});
                    }
                }else{
                    q.push({ny,nx});
                    if(B[ny][nx] == '$') ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}