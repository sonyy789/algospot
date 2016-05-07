#include <cstdio>
int mem[101][101] = {0};
int tripathcnt( int set[],  int N)
{
    int max = 0, cnt;
    for( int i = 0; i < N-1; i++) mem[i+1][0] += mem[i][0], mem[i+1][i+1] += mem[i][i];
    for( int i = 0; i < N; i++)
    {
        for( int j = i-1; j > 0; j--)
        {
            if(mem[i-1][j-1]==mem[i-1][j]) 
                set[j] += set[j-1], mem[i][j] += mem[i-1][j];
            else if(mem[i-1][j-1] < mem[i-1][j]) 
                mem[i][j] += mem[i-1][j];
            else mem[i][j] += mem[i-1][j-1], set[j]=set[j-1];
        }
    }
    max = mem[N-1][0], cnt = set[0];
	for(int i=1; i<N; i++)
	{
		if(mem[N-1][i]>max) max=mem[N-1][i], cnt=set[i];
		else if(mem[N-1][i] == max) cnt += set[i];
	}
    return cnt;
}
int main()
{
    int N, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        int *arr = new  int[N];
        for( int i = 0; i < N; i++) arr[i] = 1;
        for( int i = 0; i < N; i++)
        {
            for( int j = 0 ; j < i + 1; j++) scanf("%d", &mem[i][j]);
        }
        printf("%d\n", tripathcnt(arr, N));
        delete[] arr;
    }
}