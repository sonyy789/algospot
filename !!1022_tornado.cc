#include <cstdio>
int A[50][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(){
    int r1, r2, c1, c2, x, y, n, len1 = 1, len2 = 1, cnt = 2, val = 2, dir = 0;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    x = y = 0; n = (r2-r1+1)*(c2-c1+1);
    if(r1<=0 && 0 <= r2 && c1 <= 0 && 0 <= c2){
        A[y-r1][x-c1] = 1;
        n--;
    }
    while(n){
        if(dir == 0 || dir == 2){
            if(y > r2 || y < r1) x += dx[dir]*len2, val += len2, len2 = 0;
            else{
                while(len2){
                    x += dx[dir];
                    if(x >= c1 && x <= c2){ n--; A[y-r1][x-c1] = val;}
                    if(n == 0) break;
                    val++; len2--;
                }    
            }
        }else{
            if(x > c2 || x < c1) y += dy[dir]*len2, val += len2, len2 = 0;
            else{
                while(len2){
                    y += dy[dir];
                    if(y >= r1 && y <= r2) {n--; A[y-r1][x-c1] = val;}
                    if(n == 0) break;
                    val++; len2--;
                }
            }
        }
        if(len2 == 0){
            len2 = len1;
            dir = (dir+1)%4;
            cnt--;
        }
        if(cnt == 0){
            len1++;
            len2 = len1;
            cnt = 2;
        }
    }
    len1 = 0;
    while(val){
        val/=10;
        len1++;
    }
    r2 = (r2-r1)+1; c2 = (c2-c1)+1;
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++)
            printf("%*d ", len1, A[i][j]);
        printf("\n");
    }
}