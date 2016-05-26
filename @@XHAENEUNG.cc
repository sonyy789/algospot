#include <iostream>
#include <unordered_map>
using namespace std;
int ans_chk(string a, string b)
{
    int stat = 0, asize = a.size(), bsize = b.size();
    if(a.size() == 0 | asize != bsize ) return 0;
    for(int i = 0; i < asize; i++)
    {
        if(stat) return 0;
        stat = 1;
        for(int j = 0; j < bsize; j++)
        {
            if(a[i] == b[j])
            {
                b[j] = 0, stat = 0;
                break;
            }
        }
    }
    return 1;
}
int main()
{
    int T, result;
    string a, b, op, tmp, ans, temp;
    unordered_map<string, int> arr = {{"zero",0},{"one",1},{"two",2},
                                    {"three",3},{"four",4},{"five",5},
                                    {"six",6},{"seven",7},{"eight",8},
                                    {"nine",9}, {"ten",10}};
    unordered_map<string, int>::iterator pos;
    cin>>T;
    while(T--)
    {
        result = 0;
        cin>>a>>op>>b>>tmp>>ans;
        pos = arr.find(a);
        result += (*pos).second;
        pos = arr.find(b);
        if(op == "+") result += (*pos).second;
        else if(op == "-") result -= (*pos).second;
        else result *= (*pos).second;
        
        for(pos = arr.begin(); pos != arr.end(); ++pos)
            if((*pos).second == result) temp = (*pos).first;
        
        if(ans_chk(temp, ans)) cout<<"Yes\n";
        else cout<<"No\n";
        temp.clear();
    }
}