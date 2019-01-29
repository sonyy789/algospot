#include <cstdio>
#include <queue>
using namespace std;
int n, x, i, sz1, sz2;
int main(){
    scanf("%d", &n);
    priority_queue<int> pq1, pq2;
    while(n--){
        scanf("%d", &x);
        pq1.push(x); sz1++;
        int tmp = sz1-sz2-1;
        while(tmp-- > 0){
            pq2.push(-pq1.top());
            pq1.pop();
            sz2++; sz1--;
        }
        while(sz1 && sz2 && pq1.top() > -pq2.top()){
            int a = pq1.top(); pq1.pop();
            int b = pq2.top(); pq2.pop();
            pq1.push(-b); pq2.push(-a); 
        }
        printf("%d\n", pq1.top());
    }
}