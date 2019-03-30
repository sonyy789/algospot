#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
int t, n, m, z;
char A[40];
int B[40], C[20];
int main(){
    int i, j, k, l;
    scanf("%d", &t);
    for(z=1; z<=t; z++){
        scanf("%d%d%s", &n, &m, A+1);
        //init
        int c_idx = 0, len = n/4, max = pow(16,len-1);
        for(i = 1; i <= n; i++)
            B[i] = ('A' <= A[i] && A[i] <= 'F')?A[i]-55:A[i]-'0';
        for(i = 1; i <= len; i++) B[n+i] = B[i];
        unordered_map<int, bool> um;
        //op
        for(i = 1; i <= len; i++){
            for(j = 0; j < n; j += len){
                int val = 0;
                for(k = 0, l = max; k < len; k++, l>>=4)
                    val += B[i+j+k]*l;
                if(um[val]) continue;
                else um[val] = true, C[++c_idx] = val;
            }
        }
        sort(C+1, C+1+c_idx, greater<int>());
        printf("#%d %d\n",z, C[m]);
    }
}