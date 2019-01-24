#include <cstdio>

using namespace std;

char A[503][503], B[503][503];
char str_D[5] = {'U','R','D','L'};
int D[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int n, m, i, j, k, sy, sx, y, x;

int main(){
    scanf("%d%d", &n,&m);
    for(i = 1; i <= n; i++){
        scanf("%s", A[i]+1);
    }
    for(i = 1; i <= n; i++)
        A[i][0] = A[i][m+1] = 'C';
    for(j = 1; j <= m; j++)
        A[0][j] = A[n+1][j] = 'C';
    scanf("%d%d",&sy,&sx);
    
    int ans = 0;
    char ans_dir;
    for(k = 0; k < 4; k++){
        for(i = 0; i <= n+1; i++)
            for(j = 0; j <= m+1; j++)
                B[i][j] = A[i][j];
        int dir = k;
        y = sy, x = sx;
        B[y][x] = str_D[k];
        int t = 1;
        while(1){
            y += D[dir][0], x += D[dir][1];
            if(B[y][x] == 'C') break;
            else if(B[y][x] == '/'){   
                if(dir%2) dir = (dir+3)%4;
                else dir = (dir+1)%4;
            }else if(B[y][x] == '\\'){  
                if(dir%2) dir = (dir+1)%4;
                else dir = (dir+3)%4;
            }else if(B[y][x] != '.'){
                if(B[y][x] == str_D[dir]){
                    t = 2e9;
                    break;
                }
            }else B[y][x] = str_D[dir];
            t++;
        }
        if(t > ans){
            ans_dir = str_D[k];
            ans = t;
        }
    }
    printf("%c\n", ans_dir);
    if(ans == 2e9) printf("Voyager");
    else printf("%d", ans);
    
}