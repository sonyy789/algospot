#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 15000
using namespace std;
double arr[9][9];
double tsp1(int visit[], int N, double sum, int curr, int depth)
{
    if(depth == N) return sum;
    else if(depth == 1) sum = 0;
    double result = MAX;
    for(int i = 0; i < N; i++)
    {
        if(visit[i])
        {
            visit[i] = 0;
            result = min(result, tsp1(visit, N, sum+arr[curr][i], i,depth+1));
            visit[i] = 1;
        }
    }
    return result;
}
int main()
{
    
    int T, N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        int *temp = new int[N];
        memset(&arr, 0, sizeof(arr));
        for(int i = 0; i < N; i++)
        {   temp[i] = 1;
            for(int j = 0; j < N; j++)
                scanf("%lf", &arr[i][j]);
        }
        printf("%.10lf\n", tsp1(temp, N, 0, 0, 0));
        delete[] temp;
    }
}