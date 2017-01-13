#include <iostream>
#include <vector>
using namespace std;
int best, t, n, m;
vector<string> arr;
bool check(int y, int x, int h)
{
    int half = h/2;
    if(y+h > n || x-half < 0 || x+half >= m) return false;
    int value = 0;
    for(int i = y; i <= y+half; i++)
    {
        for(int j = x-value; j <= x+value; j++)
            if(arr[i][j] != 35) return false;
        value++;
    }
    value = half-1;
    for(int i = y+half+1; i < y+h; i++)
    {
        for(int j = x-value; j <= x+value; j++)
            if(arr[i][j] != 35)
                return false;
        value--;
    }
    return true;
}
int diamond()
{
    for(int i = 0; i < n-2; i++)
        for(int j = 0; j < m-1; j++)
        {
            if(j-(best/2) <= 0) continue;
            if(j+(best/2) >= m) break;
            if(i+best >= n) return 1;
            if((arr[i][j] & arr[i+1][j]) == 35)
            {
                int temp = 3;
                while(check(i, j, temp))
                    temp += 2;
                best = max(best, temp-2);
            }
        }
}
int main()
{
    string input;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt = 0;
        best = 1;
        arr.clear();
        for(int i = 0; i < n; i++)
        {
            cin>>input;
            arr.push_back(input);
            for(int j = 0; j < input.size(); j++)
                if(input[j] == 35)  cnt++;
        }
        m = input.size();
        if(cnt <= 4)
        {
            if(cnt) cout<<"1\n";
            else cout<<"0\n";
            continue;
        }
        diamond();
        cout<<best<<"\n";
    }
}