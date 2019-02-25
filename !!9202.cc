#include <cstdio>
#include <cstring>
#define MAX 300001
using namespace std;
int score[MAX];
int D[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
char word[MAX][10], board[6][6];
bool visit[5][5], is_detect[MAX];
int solve(int y, int x, int idx, int len){
    if(word[idx][len] == '\0') return len-1;
    int i, ret = 0;
    visit[y][x] = true;
    for(i = 0; i < 8; i++){
        int ny = y+D[i][0], nx = x+D[i][1];
        if(visit[ny][nx] || word[idx][len] != board[ny][nx]) continue;
        ret |= solve(ny, nx, idx, len+1);
    }
    visit[y][x] = false;
    return ret;
}
int main(){
    int w, b, i, j, k;
    scanf("%d", &w);
    for(i = 1; i <= w; i++){
        scanf("%s", word[i]+1);
        int len = strlen(word[i]+1);
        if(len == 8) score[i] = 11;
        else if(len == 7) score[i] = 5;
        else if(len == 6) score[i] = 3;
        else if(len == 5) score[i] = 2;
        else if(len >= 3) score[i] = 1;
    }
    scanf("%d", &b);
    while(b--){
        for(i = 1; i <= 4; i++)
            scanf("%s", board[i]+1);
        int len, cnt, sc, res;
        char long_word[10];
        len = cnt = sc = 0;
        for(i = 1; i <= w; i++) is_detect[i] = false;
        for(i = 1; i <= 4; i++)
            for(j = 1; j <= 4; j++)
                for(k = 1; k <= w; k++){
                    if(board[i][j] == word[k][1]){
                        res = solve(i, j, k, 2);
                        if(res == 0 || is_detect[k]) continue;
                        is_detect[k] = true;
                        cnt++; sc += score[k];
                        if(res > len)
                            strcpy(long_word+1, word[k]+1), len = res;
                        else if(res == len && strcmp(long_word+1, word[k]+1) > 0)
                            strcpy(long_word+1, word[k]+1);
                    }
                }
        printf("%d %s %d\n", sc, long_word+1, cnt);
    }
}