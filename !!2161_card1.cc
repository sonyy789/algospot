#include <cstdio>
#include <queue>
using namespace std;
int main(){
   queue<int> q;
   int n; scanf("%d", &n);
   for(int i =1; i <= n; i++) q.push(i);
   while(!q.empty()){
      printf("%d ",q.front());
      q.pop();
      q.push(q.front());
      q.pop();
   }
}