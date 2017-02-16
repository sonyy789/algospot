#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define MAX 22
using namespace std;
bool visited[MAX][MAX];
char arr[MAX][MAX];
char cache[MAX*MAX*5];
string input;
int limit, idx, r, c;
int add[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int solve(int y, int x, int dir, int depth)
{
    if(y == -1 || x == -1 || x == c || y == r) return 1;
    if(depth == idx) return 0;
    if(visited[y][x]) return 1;
    visited[y][x] = true;
    arr[y][x] = cache[depth];
    if(solve(y+add[dir][0], x+add[dir][1], dir, depth+1))
    {
        dir = (dir+1)%4;
        solve(y+add[dir][0], x+add[dir][1], dir, depth+1);
    }
    return 0;
}
int main()
{
    int n;
    int num = 1;
    cin>>n;
    while(n--)
    {
        cin>>r>>c;
        cin.ignore();
        getline(cin, input);
        cin.clear();
        memset(&visited, false, r*MAX);
        memset(&arr, '0', r*MAX);
        memset(&cache, '0', input.size()*5);
        idx = 0;
        for(int i = 0; i < input.size(); i++)
        {
            int value;
            if(input[i] == 32) { idx += 5; continue;}
            else value = input[i]-'@';
            for(int j = 0; j < 5; j++)
            {
                if(value&(1<<(4-j))) cache[idx] = '1';
                idx++;
            }
        }
        solve(0, 0, 0, 0);
        cout<<num++<<" ";
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cout<<arr[i][j];
        cout<<"\n";
    }
}