#include <cstdio>
#include <cmath>
int mag[4][8];
int t[4], r[4], l[4], f[4];
void rot(int idx){
    if(f[idx] == 0) return;
    int dir;
    if(f[idx] == 1) dir = 7;
    else dir = 1;
    t[idx] = (t[idx]+dir)%8;
    r[idx] = (r[idx]+dir)%8;
    l[idx] = (l[idx]+dir)%8;
}
int main(){
    int tt, k, a, b, dir;
    scanf("%d", &tt);
    for(int z = 1; z <= tt; z++){
        int ans = 0;
        t[0] = t[1] = t[2] = t[3] = 0;
        r[0] = r[1] = r[2] = 2;
        l[1] = l[2] = l[3] = 6;
        scanf("%d", &k);
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 8; j++)  scanf("%d", &mag[i][j]);
        while(k--){
           scanf("%d %d",&a,&b);
           a--;
           f[0] = f[1] = f[2] = f[3] = 0;
           f[a] = b;
           int tmp = -b;
           for(int i = a-1; i>=0&&(mag[i][r[i]]!=mag[i+1][l[i+1]]); i--, tmp = -tmp) {f[i] = tmp;}
           tmp = -b;
           for(int i = a+1; i<4 &&(mag[i-1][r[i-1]]!=mag[i][l[i]]); i++, tmp = -tmp) { f[i] = tmp;}
           for(int i =0 ; i < 4; i++) rot(i);
        }
        //summation
        for(int i = 0; i < 4; i++)
             if(mag[i][t[i]]) ans += pow(2,i);
        printf("#%d %d\n", z, ans);
    }
}