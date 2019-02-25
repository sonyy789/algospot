#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
int n, i, j;
string str;
int main(){
    ios_base::sync_with_stdio(false);
    unordered_map<string, int> um;
    vector<string> A;
    cin>>n;
    while(n--){
        cin>>str;
        if(um[str]) um[str]++;
        else um[str] = 1, A.push_back(str);
    }
    string ans;
    int num_ans = 0;
    for(string s:A){
        if(um[s] > num_ans) num_ans = um[s], ans = s;
        else if(um[s] == num_ans && ans > s) ans = s;
    }
    cout<<ans;
}