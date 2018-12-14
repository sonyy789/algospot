#include <cstdio>
#define INF 10000000
#define min(a,b) ((a)<(b)?(a):(b))
int n, h, m, a, b, ans = INF;
bool B[32][12];
int goDown(int cnt){
   for(int j = 1; j < n; j++){
      int curr = j;
      for(int i = 1; i <= h; i++){
         if(B[i][curr]) curr++;
         else if(B[i][curr-1]) curr--;
      }
      if(curr != j) return 0;
   }
   return ans = cnt;
}
void solve(int y, int x, int cnt){
   if(cnt >= ans) return;
   if(goDown(cnt)) return;
   if(cnt == 3) return;
   int ret = INF;
   for(y; y <= h; y++){
      for(x; x < n; x++){
         if(cnt+1 >= ans) return;
         if(B[y][x-1]) continue;
         if(B[y][x]){x++; continue;}
         if(B[y][x+1]) {x+=2; continue;}
         B[y][x] = true;
         solve(y, x+2, cnt+1);
         B[y][x] = false;
      }
      x=1;
   }
}
int main(){
   scanf("%d%d%d", &n, &m, &h);
   while(m--){
      scanf("%d%d", &a, &b);
      B[a][b] = true;
   }
   solve(0, 0, 0);
   if(ans == INF) printf("-1");
   else printf("%d\n", ans);
}