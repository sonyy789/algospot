#include <cstdio>
#include <cmath>
using namespace std;
int B[6][6];
int main(){
    char P[3];
    scanf("%s", P);
    int y = P[1]-'1', x = P[0]-'A', cnt = 1;
    int sy = y, sx = x;
    B[y][x] = cnt++;
    int f= 0;
    for(int i = 0; i < 35; i++){
        scanf("%s", P);
        int ny = P[1]-'1', nx = P[0]-'A';
        if(abs(ny-y)*abs(nx-x) != 2 || B[ny][nx]) {f = 1; break;}
        y = ny; x = nx;
        B[y][x] = cnt++;
    }
    if(abs(sy-y)*abs(sx-x) != 2) f =1;
    if(f) printf("Invalid");
    else printf("Valid");
}