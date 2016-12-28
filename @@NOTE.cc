#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string input;
    vector<int> arr(8, 0);
    for(int i = 0; i < 8; i++)
        cin>>arr[i];
    int sum = 0, flags = 0;
    for(int i = 0; i < 7; i++) if(abs(arr[i+1]-arr[i]) > 1) flags = 1;
    if(flags) cout<<"mixed\n";
    else if(arr[0] < arr[1]) cout<<"ascending\n";
    else cout<<"descending\n";
}