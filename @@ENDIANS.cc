#include <iostream>
using namespace std;
int main()
{
    int T, shift;
    unsigned int result, input;
    unsigned int arr[4] = {255, 65280, 16711680, 4278190080};
    cin>>T;
    while(T--)
    {
        cin>>input;
        result = 0;
        result += (input&arr[0])<<24;
        result += (input&arr[1])<<8;
        result += (input&arr[2])>>8;
        result += (input&arr[3])>>24;
        cout<<result<<endl;
    }
}