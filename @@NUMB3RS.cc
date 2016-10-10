#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
double mem[50][100];
int arr[50][50];
int count[50];
int T, n, d, p, t, q;
double numb3rs(int cur, int day)
{
    if(day == 0) return (cur == p? 1:0);
    double &result = mem[cur][day];
    if(result > -1) return result;
    result = 0;
    for(int i = 0; i < n; i++)
        if(arr[cur][i]) result += numb3rs(i, day-1)/count[i];
    return result;
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        memset(&count, 0, sizeof(int)*50);
        memset(&mem, -1, sizeof(double)*50*100);
        scanf("%d%d%d", &n, &d, &p);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
                if(arr[i][j]) count[i]++;
            }
        scanf("%d", &t);
        
        while(t--)
        {
            scanf("%d", &q);
            printf("%.9lf ", numb3rs(q, d));
        }printf("\n");
    }
}