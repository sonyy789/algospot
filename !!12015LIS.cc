#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, num;
int A[1000001];
int main(){
    int i, j;
    vector<int> ans;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &num);
        if(ans.size() == 0 || ans[ans.size()-1] < num)
            ans.push_back(num);
        else{
            auto it = lower_bound(ans.begin(), ans.end(), num);
            (*it) = num;
        }
    }
    printf("%d", (int)ans.size());
}