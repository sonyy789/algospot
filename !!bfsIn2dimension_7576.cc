#include <cstdio>
#include <queue>
using namespace std;
int box[1002][1002];
int n, m, zeroCnt = 0;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
queue<pair<int,int>> q;
int bfs2d(){
	int ret = 0;
	int temp = -1;
	while(1){
		if(zeroCnt == 0) break;
		if(zeroCnt == temp) return -1;
		temp = zeroCnt;
		ret++;
		size_t size = q.size();
		for(int i = 0; i < size; i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int j = 0; j < 4; j++){
				int yy = y+dir[j][0]; 
				int xx = x+dir[j][1];
				if(box[yy][xx] == 0 && yy > 0 && xx > 0 && yy <= n && xx <= m){
					q.push(make_pair(yy, xx));
					box[yy][xx] = 1;
					zeroCnt--;
				}
			}
		}
		
	}
	return ret;
}
int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++)
		for(int j =1; j <= m; j++){
			scanf("%d", &box[i][j]);
			if(box[i][j] == 1) q.push(make_pair(i,j));
			else if(box[i][j] == 0) zeroCnt++;
		}
	printf("%d\n", bfs2d());
}