#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

int t, n, i;
int order[1001];
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int idx = 0;
        unordered_map<string, int> um;
        queue<int> q[1001];
        cin>>n;
        for(i = 1; i<= n; i++){
            cin>>str;
            if(um[str] == 0) um[str] = ++idx;
            q[um[str]].push(i);
        }
        for(i = 1; i <= n; i++){
            cin>>str;
            order[i] = q[um[str]].front();
            q[um[str]].pop();
        }
        vector<pair<int, string>> word(n+1);
        for(i = 1; i <= n; i++){
            cin>>str;
            word[i] = {order[i], str};
        }
        sort(&word[1], &word[n+1]);
        for(i = 1; i <= n; i++){
            cout<<word[i].second<<" ";
        }cout<<"\n";
    }
}