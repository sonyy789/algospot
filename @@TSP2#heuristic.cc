#include <iostream>
#include <cstring>
#include <iomanip>
#define MAX 225000
#define MAX_VALUE 1500
using namespace std;
double arr[16][16];
double skip, shortest;
double hrsc_arr[16];
double hrsc_sum;
int visit[16];
int C, N;
double tsp2(int depth, int curr, double sum, double sum_shortest)
{
    if(depth == 1) sum = 0;
    else if(depth == N)
    {
        if(skip > sum) skip = sum;
        return 1.0;
    }
    if(sum_shortest+sum >= skip) return 0.0;
    for(int i = 0; i < N; i++)
        if(!visit[i])
        {
            visit[i] = 1;
            tsp2(depth+1, i, sum+arr[curr][i], sum_shortest-hrsc_arr[i]);
            visit[i] = 0;
        }
    return 1.0;
}
int main()
{
    cout.setf(ios_base::floatfield, ios_base::fixed);
    cout.precision(10);
    cin>>C;
    while(C--)
    {
        cin>>N;
        skip = MAX;
        memset(&visit, 0 , sizeof(visit));
        memset(&hrsc_arr, 0 , sizeof(hrsc_arr));
        hrsc_sum = 0.0;
        for(int i = 0; i < N; i++)
        {
            shortest = MAX_VALUE;
            for(int j = 0; j < N; j++)
            {
                cin>>arr[i][j];
                if(i != j) shortest = min(shortest, arr[i][j]);
            }
            hrsc_arr[i] = shortest, hrsc_sum += shortest;
        }
        tsp2(0, 0, 0.0, hrsc_sum);
        cout<<skip<<"\n";
    }
}