#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int n, x, i;
int main(){
    priority_queue<pair<int, bool>> pq;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        if(x){
            if(x < 0) pq.push({x,true});
            else pq.push({-x, false});
        }else{
            if(pq.empty()) printf("0\n");
            else{
                printf("%d\n", pq.top().second?pq.top().first:-pq.top().first);
                pq.pop();
            }
        }
    }
}