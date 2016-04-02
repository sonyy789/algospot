#include <iostream>
#include <algorithm>
#define ALPA 26
using namespace std;
typedef struct NODE{
    int count = 0;
    string str;
} node;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string input;
        cin>>input;
        node *p = new node[ALPA];
        for(int i = 0; i < input.size(); i+=2)
        {
            p[input[i]-97].count++;
            p[input[i]-97].str.push_back(input[i+1]);
        }
        for(int i = 0; i < ALPA; i++)
        {
            if(p[i].count) sort(p[i].str.begin(),p[i].str.end());
        }
        
        for(int i = 0; i < ALPA; i++)
        {
            if(p[i].count)
            {
                for(int j = 0; j < p[i].count; j++)
                {
                    cout<<(char)(i+97)<<p[i].str[j];
                }
            }
        }cout<<endl;
        input.clear();
        delete[] p;
    }
}