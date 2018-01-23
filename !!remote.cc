#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 500000
using namespace std;
vector<int> input;
int res = 2e9;
void solve(int sum, int len, int n)
{
	if(len > 6 || len >= res) return;
	int temp = abs(sum-n)+len;
	if(len&&temp<res) res = temp;
	sum *= 10;
	for(int data : input)
		solve(sum+data, len+1, n);
}
int main()
{
	int n, m, temp[10] = {-1}, idx = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) scanf("%d", &temp[i]);
	sort(&temp[0], &temp[m]);
	for(int i = 0; i < 10; i++)
	{
		if(i == temp[idx]) {idx++; continue;}
		input.push_back(i);
	}
	solve(0, 0, n);
	res = abs(100-n)<res?abs(100-n):res;
	printf("%d\n",res);
}