#include <cstdio>
#include <queue>
#include <cmath>
#include <tuple>
#include <vector>
using namespace std;
typedef struct Point{
	int y;
	int x;
	int r;
} p;
vector<p> pos;
bool dist(int y, int x, int r, int idx){
	double dist = sqrt(pow(x-get<1>(pos[idx]), 2)+pow(y-get<0>(pos[idx]), 2));
	return dist<=(double)(r+get<2>(pos[idx]))?true:false;
}
int main(){
	int t, n, cnt, x, y, r;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		pos = vector<p>(n);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d",&x,&y,&r);
			pos[i] = make_tuple(x,y,r);
		}
		queue<tuple<int,int,int>> q;
		int ans = 0;
		while(n){
			int l = pos.size()-1;
			ans++;
			q.push(make_tuple(get<0>(pos[l]),get<1>(pos[l]),get<2>(pos[l])));
			pos.pop_back(); n--;
			while(!q.empty()){
				int yy = get<0>(q.front());
				int xx = get<1>(q.front());
				int rr = get<2>(q.front());
				q.pop();
				for(int i = pos.size()-1; i>=0; i--){
					if(dist(yy,xx,rr,i)){
						q.push(make_tuple(get<0>(pos[i]),get<1>(pos[i]),get<2>(pos[i])));
						pos.erase(pos.begin()+i); n--;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}