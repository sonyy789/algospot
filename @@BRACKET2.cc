#include <iostream>
#include <vector>
using namespace std;
int bracket2(string input)
{
    string temp;
    int index = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '(' || input[i] =='[' || input[i] =='{')
            temp[index++] = input[i];
        else
       {
           if(!(temp[index-1] == input[i]-2 || temp[index-1] == input[i]-1)) return 0;
           else index--;
       }
    }
    if(index) return 0;
    else return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string input;
        cin>>input;
        if(bracket2(input)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}