#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int a, cnt, S[2] = {0,};
    priority_queue<int> pq;
    for(int k = 0; k < 2; k++){
        cnt = 0;
        for(int i = 0; i < 10; i++)
            scanf("%d", &a), pq.push(a);
        while(!pq.empty()){ if(cnt < 3) S[k] += pq.top(); pq.pop(); cnt++;}
    }
    printf("%d %d", S[0], S[1]);
}