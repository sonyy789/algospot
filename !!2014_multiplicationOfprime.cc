#include <cstdio>
#include <queue>
using namespace std;
int K[101];
int main(){
    int n, k, val;
    priority_queue<int> pq;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &K[i]);
        pq.push(-K[i]);
    }
    while(!pq.empty()){
        long long num = -pq.top();
        pq.pop();
        k--;
        if(k == 0){
            printf("%lld", num);
            while(!pq.empty()) {pq.pop();}
            break;
        }
        for(int i = 0; i < n; i++){
            if(num*K[i] > 2147483647) continue;
            pq.push(-num*K[i]);
            if(num%K[i] ==0 ) break;
        }
    }
}