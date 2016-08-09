#include <iostream>
#define MOD 61
using namespace std;
int main()
{
    string input;
    while(1)
    {
        cin>>input;
        if(input == "end")
            break;
        else
        {
            int size = input.size();
            int result = 0;
            for(int i = 0; i < size; i++)
            {
                if(input[i] > 64)
                {
                    if(input[i] < 91)
                        result += (int)(input[i]-55);
                    else
                        result += (int)(input[i]-61);
                }
                else
                    result += (int)(input[i]-48);
                result %= MOD;
            }
        if(result)
            cout<<"no\n";
        else
            cout<<"yes\n";
        }
    }
}
