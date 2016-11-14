#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#define ALPHASIZE 26
using namespace std;
int adjan[ALPHASIZE][ALPHASIZE]; 
int visited[ALPHASIZE]; 
deque<char> result;
bool dfs(int idx)
{
    visited[idx] = 1;
    for(int i = 0; i < ALPHASIZE; i++)
        if(adjan[idx][i] && !visited[i])
        {
            if(adjan[i][idx]) return false;
            dfs(i); 
        }
    result.push_front(idx+97);
    return true;
}
bool dfsAll()
{
    for(int i = ALPHASIZE-1; i >= 0; i--)
        if(!visited[i])
            if(dfs(i)==false) return false;
    return true;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(&adjan, 0, sizeof(adjan));
        memset(&visited, 0, sizeof(visited));
        string input;
        vector<string> word;
        word.clear(), result.clear();
        cin>>n>>input;
        word.push_back(input);
        for(int i = 1; i < n; i++)
        {
            cin>>input, word.push_back(input);
            int size = min(input.size(), word[i-1].size());
            for(int j = 0; j < size; j++)
                if(input[j] != word[i-1][j])
                {
                    adjan[word[i-1][j]-97][input[j]-97] = 1;
                    break;
                }
        }
        if(dfsAll())
           for(char data:result)
               cout<<data;
        else cout<<"INVALID HYPOTHESIS";
        cout<<"\n";
    }
}