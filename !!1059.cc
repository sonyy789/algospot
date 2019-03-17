#include <cstdio>
#include <algorithm>
using namespace std;
int l, n, ans;
int L[1001];
int main(){
    int i;
    scanf("%d", &l);
    for(i = 1; i <= l; i++)
        scanf("%d", L+i);
    scanf("%d", &n);
    sort(L, L+l+1);
    for(i = 0; i < l; i++){
        if(L[i] < n && n < L[i+1]){
            int left = n-L[i]-1;
            int right = L[i+1]-n-1;
            ans += left*(right+1)+right;
            break;
        }
    }
    printf("%d", ans);
}