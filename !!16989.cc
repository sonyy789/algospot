#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
struct Point{
   int y, x;
   bool operator<(const Point &P) const{
      return y==P.y?(x<P.x):(y<P.y);
   }
   bool operator==(const Point &P) const{
      return y==P.y&&x==P.x;
   }
};
int n, m, e_idx;
int A[1001][1001];
int D[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[1001][1001];
Point empty[1000001];
map<Point, int> mp1;
map<pair<Point, Point>, int> mp2;
map<Point, int>::iterator it1;
map<pair<Point, Point>, int>::iterator it2;
int dfs(int y, int x){
   int i, ret = 1;
   visited[y][x] = true;
   queue<Point> q;
   q.push({y,x});
   while(!q.empty()){
      y = q.front().y, x = q.front().x;
      q.pop();
      for(i = 0; i < 4; i++){
         int ny = y+D[i][0], nx = x+D[i][1];
         if(ny < 1 || nx < 1 || ny > n || nx > m || visited[ny][nx] || A[ny][nx] == 1) continue;
         if(A[ny][nx] == 0){
            A[ny][nx] = -1;
            empty[++e_idx].y = ny, empty[e_idx].x = nx;
         }else if(A[ny][nx] == 2){
            ret++;
            visited[ny][nx] = true;
            q.push({ny,nx});
         }
      }
   }
   return ret;
}
int main(){
   int i, j;
   scanf("%d%d", &n, &m);
   for(i = 1; i <= n; i++)
      for(j = 1; j <= m; j++)
         scanf("%d", &A[i][j]);
   for(i = 1; i <= n; i++)
      for(j = 1; j <= m; j++)
         if(A[i][j] == 2 && visited[i][j] == 0){ 
            int res = dfs(i, j);
            if(e_idx == 2){ 
                bool f = true;
                pair<Point, Point> p = {{empty[1].y,empty[1].x},{empty[2].y, empty[2].x}};
                for(it2 = mp2.begin(); it2 != mp2.end(); it2++){
                   if(((*it2).first.first == p.first && (*it2).first.second == p.second)) (*it2).second += res, f = false;
                   else if(((*it2).first.first == p.second && (*it2).first.second == p.first)) (*it2).second += res, f = false; 
                }
                if(f) mp2[p] = res;
            }
            else if(e_idx == 1){
               Point p = {empty[1].y,empty[1].x};
               for(it2 = mp2.begin(); it2 != mp2.end(); it2++)
                  if((*it2).first.first == p || (*it2).first.second == p) (*it2).second += res;
               mp1[p] += res;
            }
            while(e_idx){ A[empty[e_idx].y][empty[e_idx--].x] = 0; }
         }
   int a = 0, b = 0;
   for(it1 = mp1.begin(); it1 != mp1.end(); it1++){
      if((*it1).second > a){
         if(a) b = a; 
         a = (*it1).second;
      }else if((*it1).second > b) b = (*it1).second;
   }
   a += b;
   for(it2 = mp2.begin(); it2 != mp2.end(); it2++)
      a = max(a, (*it2).second);
   printf("%d", a);
}