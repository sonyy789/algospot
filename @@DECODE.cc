#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
#define MAX 21
using namespace std;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int add[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int main()
{
    int r, c, n, num = 1;
    char str[MAX*MAX];
    scanf("%d", &n);
    while(n--)
    {
        string input, result;
        scanf("%d%d", &r, &c);
        scanf("%s", str);
        memset(&visited, false, MAX*r);
        int limit = strlen(str);
        int idx, temp, x, y, dir;
        int depth = 1;
        idx = temp = x = y = dir = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++) arr[i][j] = str[idx++];
        while(depth <= limit)
        {
            if(x == -1 | y == -1 || x == c || y == r || visited[y][x])
            { 
                y -= add[dir][0]; x -= add[dir][1]; 
                dir = (dir+1)%4;
                y += add[dir][0]; x += add[dir][1];
                continue;
            }
                visited[y][x] = true;
                if(arr[y][x] == '1') temp += 1<<(4-(depth-1)%5);
                if(!(depth%5))
            {
                if(!temp) result.push_back(' ');
                else result.push_back(temp+'@');
                temp = 0;
            }
                y += add[dir][0];
                x += add[dir][1];
                depth++;
        }
        printf("%d %s\n", num++, result.c_str());
    }
}