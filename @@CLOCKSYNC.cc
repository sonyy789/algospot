#include <iostream>
#include <cstring>
#include <limits>
#include <vector>
#define CLOCK_COUNT 16
#define SWITHCH_COUNT 10
using namespace std;
int result = numeric_limits<int>::max();
vector<vector<int>> swit = {{0,1,2}, {3,7,9,11}, {4,10,14,15},
                              {0,4,5,6,7}, {6,7,8,10,12}, {0,2,14,15},
                              {3,14,15}, {4,5,7,14,15}, {1,2,3,4,5},
                              {3,4,5,9,13}};
void clock_sync(vector<int> set, int sum, int index)
{
    if(sum >= result) return;
    if(index == SWITHCH_COUNT)
    {
        for(int data:set)
            if(data) return;
        result = min(result, sum);
        return;
    }
        clock_sync(set, sum, index+1);
        for(int i=1; i < 4; i++)
        {
            for(int index1:swit[index])
                set[index1] +=3, set[index1] %= 12;
            clock_sync(set,sum+i,index+1);
        }
}
int main()
{
    int T, input;
    cin>>T;
    while(T--)
    {
        vector<int> clk;
        clk.clear();
        result = numeric_limits<int>::max();
        for(int i = 0; i < CLOCK_COUNT; i++)
        {
            cin>>input;
            if(input == 12) input = 0;
            clk.push_back(input);
        }
        clock_sync(clk,0, 0);
        if(result == numeric_limits<int>::max())
            cout<<"-1\n";
        else
            cout<<result<<"\n";
    }
}