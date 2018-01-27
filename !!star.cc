#include <cstdio>
char ans[3000][3000];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) ans[i][j] = 32;
	ans[0][0] = '*';
	for(int i = 3; i <= n; i *=3)
	{
		int inv = i/3;
		for(int y = 0; y < inv; y++)
			for(int x = 0; x < inv; x++)
			{
				ans[y+inv][x] = ans[y][x+inv] = ans[y][x];
				ans[y+2*inv][x] = ans[y][x+2*inv] = ans[y][x];
				ans[y+2*inv][x+inv] = ans[y+inv][x+2*inv] = ans[y][x];
				ans[y+2*inv][x+2*inv] = ans[y][x];
			}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}