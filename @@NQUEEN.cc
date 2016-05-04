#include <iostream>
#include <unistd.h>
using namespace std;
int mem[13][13] = {0};
int zero_chk(int x, int y, int N)
{
    int tmp_x = x-1, tmp_y = y-1;
    while(tmp_x >= 0 && tmp_y >=0) if(mem[tmp_y--][tmp_x--] == 1) return 1;
    tmp_x = x+1; tmp_y = y-1;
    while(tmp_x < N && tmp_y >=0) if(mem[tmp_y--][tmp_x++] == 1) return 1;
    while(y > 0) if(mem[--y][x] == 1) return 1; 
    return 0;
}
void print(int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<mem[i][j]<<" ";
        }cout<<"\n";
    }cout<<"\n";
}
int nqueen(int y, int N)
{
    //print(N);
    ///sleep(2);
    if(y == N) return 1;
    int cnt  = 0;
    for(int i = 0; i < N; i++)
    {
        //zero_check
        if(zero_chk(i, y, N)) continue;
        mem[y][i] = 1;
        cnt += nqueen(y+1, N);
        mem[y][i] = 0;
    }
    return cnt;
}
int main()
{
    int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        cout<<nqueen(0, N)<<"\n";
    }
}
