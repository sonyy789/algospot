#include <cstdio>
int M[21][21];
int C[4], S[2];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int main(){
    int i, j, n, m, y, x, k, tmp1, tmp2, a, b, in, idx = 0;
    scanf("%d %d %d %d %d",&n,&m,&y,&x,&k);
    for(i = 0; i < n; i++)  
        for(j = 0; j < m; j++) scanf("%d", &M[i][j]);
    while(k--){
        scanf("%d", &in);
        in--;
        int ny = y+dir[in][0]; int nx = x+dir[in][1];
        if(ny >= n || nx >= m || ny < 0 || nx < 0) continue;
        y = ny; x = nx;
        //rotate
        if(in == 2){ idx = (idx+3)%4; }
        else if(in == 3){ idx = (idx+1)%4; }
        else{
            if(in == 0) {a=1; b=0; tmp1 = S[0]; tmp2 = S[1];}
            else {a=0; b=1; tmp1 = S[1]; tmp2 = S[0];}
            S[a] = C[idx]; S[b] = C[(idx+2)%4];
            C[idx] = tmp1; C[(idx+2)%4] = tmp2;
        }
        //process
        if(M[y][x]){
            C[(idx+2)%4] = M[y][x];
            M[y][x] = 0;
        }else{M[y][x] = C[(idx+2)%4];}
        printf("%d\n", C[idx]);
    }
}