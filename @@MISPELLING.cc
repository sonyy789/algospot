#include <iostream>
using namespace std;
int main()
{
    int T, N;
    int cnt = 1;
    cin>>T;
    while(T--)
    {
        string input;
        cin>>N>>input;
        input.erase(N-1,1);
        cout<<cnt++<<" "<<input<<endl;
        input.clear();
    }
}