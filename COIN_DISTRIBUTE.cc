#include <iostream>
using namespace std;
int coin(int set[], int index, int rest, int N)
{
    if(index == N-1 && rest%set[N-1] == 0 ) return 1;
    if(index > N) return 0;
    int sum = 0;
    cout<<index<<" "<<rest<<endl;
    int tmp = rest/set[index];
    
    for(int i = tmp; i >=0; i--)
    {
        sum += coin(set, index + 1, rest-(set[index]*i), N);
    }
    return sum;
}
int main()
{
    int M;
    cin>>M;
    int a[3] = {1000, 500, 100};
    int result = coin(a, 0, M, 3);
    cout<<result<<endl;
}