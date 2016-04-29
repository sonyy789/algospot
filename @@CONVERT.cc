#include <iostream>
using namespace std;
float mem[4] = {2.2046, 0.4536, 0.2642, 3.7854};
int main()
{
    int T, cnt = 1;
    string input;
    float value;
    cin>>T;
    while(T--)
    {
        cin>>value>>input;
        cout<<cnt++<<" ";
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.precision(4);
        if(input == "kg") cout<<value*mem[0]<<" lb\n";
        if(input == "lb") cout<<value*mem[1]<<" kg\n";
        if(input == "l") cout<<value*mem[2]<<" g\n";
        if(input == "g") cout<<value*mem[3]<<" l\n";
    }
}