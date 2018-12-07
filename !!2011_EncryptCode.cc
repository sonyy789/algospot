#include <cstdio>
#define MOD 1000000
int main(){
    char prev = '0', in[5001];
    int idx = 0, A = 0, B = 1, C = 2, dp[3] = {1,1,0};
    bool flag = true;
    scanf("%[^\n]s", in);
    while(in[idx]){
        if(in[idx] < '0' || in[idx] > '9' || (in[idx]=='0'&& prev != '1' && prev != '2' )){
            flag = false;
            break;
        }
        if(in[idx] == '0') dp[B] = 0;
        dp[C] = dp[B];
        int num = (prev-48)*10+(in[idx]-48);
        if(num >= 10 && num <= 26) dp[C] += dp[A];
        if(dp[C] >= MOD) dp[C] -= MOD;
        int temp = C;
        C = A; A = B; B = temp;
        prev = in[idx++];
    }
    if(!flag) dp[B] = 0;
    printf("%d\n", dp[B]);
}
