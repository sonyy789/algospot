#include <cstdio>
#include <map>
using namespace std;
map<int, int> arr;
int nerd2(int a, int b)
{
    map<int, int>::iterator pos;
    pos = arr.lower_bound(a);
    if(pos != arr.end())
        if((*pos).second > b) return arr.size();
    if(pos == arr.begin())
    {
        arr.insert(make_pair(a,b));
        return arr.size();
    }
    while(pos != arr.begin())
    {
      pos--;
      if((*pos).second < b) pos = arr.erase(pos);
      else break;
    }
    arr.insert(make_pair(a,b));
    return arr.size();
}
int main()
{
    int C, N, problem, eaten, sum;
    scanf("%d", &C);
    while(C--)
    {
        sum = 1;
        arr.clear();
        scanf("%d%d%d", &N, &problem, &eaten);
        arr.insert(make_pair(problem, eaten));
        for(int i = 1; i < N; i++)
        {
            scanf("%d%d", &problem, &eaten);
            sum += nerd2(problem, eaten);
        }
        printf("%d\n", sum);
    }
}