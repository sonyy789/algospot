#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
int t, f, a_idx, b_idx;
int root[100005], C[100005];
int find(int a){
    if(root[a] == a) return a;
    return root[a] = find(root[a]);
}
int merge(int a, int b){
    a = find(a); b = find(b);
    if(a != b){
        C[a] += C[b];
        C[b] = 0;
        root[b] = a;
    }
    return C[a];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        string a, b;
        int idx = 0;
        unordered_map<string, int> um;
        memset(&root, 0, sizeof(root));
        memset(&C, 0, sizeof(C));
        cin>>f;
        while(f--){
            cin>>a>>b;
            if(um[a]) a_idx = um[a];
            else um[a] = ++idx, a_idx = root[idx] = idx, C[idx] = 1;
            if(um[b]) b_idx = um[b];
            else um[b] = ++idx, b_idx = root[idx] = idx, C[idx] = 1;
            printf("%d\n", merge(a_idx,b_idx));
        }
    }
}