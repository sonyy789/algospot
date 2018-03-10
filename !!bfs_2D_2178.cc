#include <cstdio>
#include <queue>
using namespace std;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int main(){
	bool road[101][101] = {false};
	short cost[101][101];
	char in[102];
	queue<pair<int, int>> q;
	int n, m, y, x, yy, xx;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%s", in);
		for(int j = 1; j <= m; j++)
			if(in[j-1] == '1') road[i][j] = true;
	}
	
	cost[1][1] = 1;
	road[1][1] = false;
	q.push(make_pair(1,1));
	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		if(y == n && x == m) break;
		q.pop();
		for(int i = 0; i < 4; i++){
			yy = dir[i][0]+y; xx = dir[i][1]+x;
			if(road[yy][xx] && yy > 0 && xx > 0 && yy <= n && xx <= m){
				q.push(make_pair(yy,xx));
				cost[yy][xx] = cost[y][x]+1;
				road[yy][xx] = false;
			}
		}
	}
	printf("%d", cost[n][m]);
}