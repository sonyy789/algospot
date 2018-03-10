#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int box[102][102][102];
int n, m, h, zeroCnt = 0;
queue<tuple<int, int, int>> q;
int bfs(int cnt){
	int ans, temp, x, y, z;
	ans = 0, temp = -1;
	while(1){
		if(cnt == 0) break;
		if(temp == cnt) return -1;
		ans++;
		temp = cnt;
		size_t size = q.size();
		for(int i = 0; i < size; i++){
			x = get<0>(q.front());
			y = get<1>(q.front());
			z = get<2>(q.front());
			q.pop();
			if(box[x-1][y][z] == 0 && x-1 != 0) box[x-1][y][z] = 1, cnt-- ,q.push(make_tuple(x-1,y,z));
			if(box[x+1][y][z] == 0 && x+1 != h+1) box[x+1][y][z] = 1, cnt-- ,q.push(make_tuple(x+1,y,z));
			if(box[x][y-1][z] == 0 && y-1 != 0) box[x][y-1][z] = 1,cnt-- ,q.push(make_tuple(x,y-1,z));
			if(box[x][y+1][z] == 0 && y+1 != m+1) box[x][y+1][z] = 1, cnt--,q.push(make_tuple(x,y+1,z));
			if(box[x][y][z-1] == 0 && z-1 != 0) box[x][y][z-1] = 1, cnt--,q.push(make_tuple(x,y,z-1));
			if(box[x][y][z+1] == 0 && z+1 != n+1) box[x][y][z+1] = 1, cnt--,q.push(make_tuple(x,y,z+1));
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d", &n, &m, &h);
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 1; k <= n; k++){
				scanf("%d", &box[i][j][k]);
				if(box[i][j][k] == 0) zeroCnt++;
				else if(box[i][j][k] == 1) q.push(make_tuple(i,j,k));
			}
	printf("%d\n", bfs(zeroCnt));
}