#include <cstdio>
#define CITY 5000
using namespace std;
int min(int a, int b)
{
    int tmp;
    tmp = a < b ? a:b;
    return tmp;
}
int main()
{
    int N, K, T;
    int L[CITY];
    int M[CITY];
    int G[CITY];
    int temp  = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &K);
        for(int i = 0; i < N; i++)
        {
            scanf("%d%d%d", &L[i], &M[i], &G[i]);
        }
        int high = 8030001;
        int low = -1;
        int mid = low + (high - low)/2;
        while(high > low + 1)
        {
            mid = low + (high - low)/2;
            int cnt = 0;
            for(int i = 0; i < N; i++)
            {
                if(mid < L[i]-M[i]) continue;
                temp = (min(L[i],mid)-(L[i]-M[i]))/G[i] + 1;
                if(temp > 0) cnt+=temp;
            }
            if(cnt >= K) high = mid;
            else low = mid;
            
        }
        printf("%d\n", low + 1);
    }
}