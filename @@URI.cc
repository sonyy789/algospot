#include <iostream>
using namespace std;
int main()
{
    int T;
    char ch[2];
    string input, result;
    cin>>T;
    while(T--)
    {
        cin>>input;
        result.clear();
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] =='%')
            {
                ch[0] = input[++i], ch[1] = input[++i];
                result.push_back(strtol(ch, NULL, 16));
            }
            else
                result.push_back(input[i]);
        }
        cout<<result<<"\n";
    }
}