#include <cstdio>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;
int main()
{
	int n, m, a, b, in[MAX];
	scanf("%d%d", &n, &m);
	vector<vector<int>>e(n+1);
	for(int i = 1; i <= n; i++) in[i] = 0;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		in[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= n; i++)
		if(in[i] == 0) pq.push(i);
	while(!pq.empty()){
		int curr = pq.top();
		pq.pop();
		printf("%d ", curr);
		for(int i = 0; i < e[curr].size(); i++){
			int idx = e[curr][i];
			in[idx]--;
			if(in[idx] == 0) {in[idx] = -1, pq.push(idx);}
		}	
	}
}