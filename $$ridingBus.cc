#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int t, n, k;
int A[200001];
int main(){
    int i, j, z;
    cin>>t;
    for(z = 1; z <= t; z++){
        cin>>n>>k;
        for(i = 1; i <= n; i++) cin>>A[i];
        sort(A+1, A+1+n);
        priority_queue<int> pq;
        pq.push(-A[1]);
        int ans = 1;
        for(i = 2; i <= n; i++){
            if((A[i]+pq.top()) > k) pq.pop();
            pq.push(-A[i]);
        }
        cout<<"Case #"<<z<<"\n";
        cout<<pq.size()<<"\n";
    }
}