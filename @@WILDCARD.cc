#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int t, n, len_a, len_b;
string a, b;
bool solve(int idx_a, int idx_b){
    int i;
    while(idx_a != len_a && idx_b != len_b){
        if(a[idx_a] == '?'){
        }else if(a[idx_a] =='*'){
            while(a[idx_a+1] == '*') {idx_a++;}
            if(idx_a == len_a-1) return true;
            for(i = idx_b; i < len_b; i++)
                if(solve(idx_a+1, i)) return true;
            return false; 
        }else if(a[idx_a] != b[idx_b]) return false;
        idx_a++; idx_b++;
    }
    while(a[idx_a] =='*') {idx_a++;}
    return (idx_a == len_a && idx_b == len_b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>n;
        len_a = a.size();
        vector<string> ans;
        while(n--){
            cin>>b;
            len_b = b.size();
            if(solve(0,0)) ans.push_back(b);
        }
        sort(ans.begin(), ans.end());
        for(string str:ans) cout<<str<<"\n";
    }
}