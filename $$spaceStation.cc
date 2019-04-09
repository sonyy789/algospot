#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;
int tc, t, n, m, ans;
int in[MAX];
vector<int> adj[MAX];
int main(){
   int i, j;
   scanf("%d", &t);
   for(tc = 1; tc <= t; tc++){
      memset(&in, 0, sizeof(in));
      for(i = 1; i < MAX; i++) adj[i].clear();
      
      scanf("%d%d", &n, &m);
      while(m--){
         scanf("%d%d", &i, &j);
         adj[i].push_back(j);
         adj[j].push_back(i);
         in[i]++, in[j]++;
      }
      ans = n;
      while(1){
         bool f1 = true;
         for(i = 1; i <= n; i++){
            if(in[i] == 2){
               in[i] = -1;
               int a = 0, b = 0;
               for(j = 0; j < adj[i].size(); j++){
                  if(in[adj[i][j]] > 0)
                     if(a == 0) a = adj[i][j];
                     else b = adj[i][j];
               }
               bool f2 = false;
               for(j = 0; j < adj[a].size(); j++){
                  if(in[adj[a][j]] < 0) continue;
                  if(adj[a][j] == b) {f2 = true; break;}
               }
               if(f2){ 
                  in[a]--, in[b]--;
                  ans--, f1 = false;
               }
            }
         }
         if(f1) break;
      }
      printf("Case #%d\n%d\n",tc, ans);
   }
}