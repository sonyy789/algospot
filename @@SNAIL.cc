#include <iostream>
#include <cstring>
#define DIV 0.00000001
using namespace std;
double mem[1001][1001];
double snail(int length, int day, double prob)
{
    if(length <= 0 | day >= length | prob < DIV ) return prob;
    if(day == 0 | day*2 < length ) return 0;
    if(mem[length][day]) return mem[length][day]*prob;
    double result = 0;
    result += snail(length-2, day-1, (double)3/4);
    result += snail(length-1, day-1, (double)1/4);
    mem[length][day] = result;
    return result*prob;
}
int main()
{
    int T, n, m;
    cin>>T;
    cout.setf(ios::fixed, ios_base::floatfield);
    cout.precision(10);
    memset(&mem, 0, sizeof(mem));
    while(T--)
    {
        cin>>n>>m;
        cout<<snail(n, m, (double)1)<<"\n";
    }
}

// 0.000000001 미만 return
