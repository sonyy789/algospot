#include <cstdio>
#include <queue>
using namespace std;
int c, n;
int main(){
    int i, data;
    scanf("%d", &c);
    while(c--){
        scanf("%d", &n);
        priority_queue<int> pq;
        for(i = 1; i <= n; i++){ 
            scanf("%d", &data);
            pq.push(-data);
        }
        int ans = 0;
        while(pq.size() != 1){
            int a = -pq.top(); pq.pop();
            int b = -pq.top(); pq.pop();
            ans += a+b;
            pq.push(-(a+b));
        }
        printf("%d\n", ans);
    }
}