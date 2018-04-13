#include <cstdio>
int t, n, m, in, house, ans;
int K[42];
bool A[21][21];
int max(int a, int b){return a>b?a:b;}
int main(){
    for(int i = 1; i <= 41; i++)
        K[i] = i*i+(i-1)*(i-1);
    scanf("%d", &t);
    for(int z = 1; z <= t; z++){
        house = 0;
        ans = 1;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &in);
                if(in == 1) A[i][j] = true, house++;
                else A[i][j] = false;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int cnt = 0;
                if(A[i][j]) cnt = 1;
                for(int k = 1; cnt < house; k++){
                    //vertical
                    if(i-k >= 0 && A[i-k][j]) cnt++;
                    if(j-k >= 0 && A[i][j-k]) cnt++;
                    if(i+k < n && A[i+k][j]) cnt++;
                    if(j+k < n && A[i][j+k]) cnt++;
                    //digonal
                    for(int d = 1; d <= k-1; d++){
                        if(i-k+d >= 0){
                            if(j-d>=0 && A[i-k+d][j-d]) cnt++;
                            if(j+d<n && A[i-k+d][j+d]) cnt++;
                        }
                        if(i+k-d < n){
                            if(j-d>=0 && A[i+k-d][j-d]) cnt++;
                            if(j+d<n && A[i+k-d][j+d]) cnt++;
                        }
                    }
                    //process
                    if(cnt*m >= K[k+1])
                        ans = ans>cnt?ans:cnt;
                }
            }
        printf("#%d %d\n", z, ans);
    }
}