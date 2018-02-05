#include <cstdio>
#include <vector>
#define MAX 1000002
using namespace std;
int main()
{
    long long a, b, ans;
    vector<int> prime;
    bool chk[MAX] = {false};
    for(int i = 2; i <= MAX; i++){
        if(chk[i]) continue;
        prime.push_back(i);
        for(int j = i; j < MAX; j+=i)
            chk[j] = true;
    }
    for(int i = 0; i < MAX; i++) chk[i] = false;
    scanf("%lld%lld", &a, &b);
    ans = b-a+1;
    for(int data:prime){
        long long curr = data;
        curr *= curr;
        long long idx = a/curr;
        if(!(a%curr)) idx--;
        for(long long j = idx+1; j*curr<=b; j++){
            if(chk[j*curr-a]) continue;
            chk[j*curr-a] = true, ans--;
        }
    }
    printf("%lld", ans);
}