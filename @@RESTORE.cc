#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#define MAXLEN 1000
using namespace std;
vector<string> str;
int cache[15][15];
int path_cache[15][32768];
int size;
int C, k;
int rept()
{
    vector<string>::iterator pos = str.begin();
    for(int i = 0; i < str.size(); i++)
    {
        for(int j = 0; j < str.size(); j++)
            if(i != j)
            {
                if(str[j].find(str[i]) != string::npos)
                {
                    str.erase(pos+i);
                    i--;
                    break;
                }
            }
    }
    return str.size();
}
int restore()
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(i != j)
            {
                int size1 = str[i].size();
                int size2 = str[j].size();
                int cover, idx, length;
                cache[i][j] = size2;
                if(size1 <= size2) cover = size1, idx = 0, length = size2-size1; 
                else cover = size2-1, idx = size1-size2+1, length = 1;
                while(cover)
                {
                    if(str[i].substr(idx, cover) == str[j].substr(0,cover))
                    {
                        cache[i][j] = length;
                        break;
                    }
                    length++, idx++, cover--;
                }
            }
            else cache[i][j] = str[i].size();
}
int search(int path, int curr, int depth)
{
    if(path == (1<<size)-1) return 0;
    int &ret = path_cache[curr][path];
    if(ret != -1) return ret;
    ret = MAXLEN;
    int temp1, temp2;
    for(int i = 0; i < size; i++)
    {
        temp1 = (1<<i);
        if((path&temp1) == 0)
        {
            if(depth == 0) curr = i;
            temp2 = search(path+temp1, i, depth+1)+cache[curr][i];
            ret = min(ret, temp2);
        }
    }
    return ret;
}
string make_str(int path, int curr, int depth)
{
    if((1<<size)-1 == path) return "";
    int temp1, temp2, idx;
    int temp3 = path_cache[curr][path];
    int ret = MAXLEN;
    for(int i = 0; i < size; i++)
    {
        temp1 = (1<<i);
        if((temp1&path)==0)
        {
            if(depth == 0) curr = i;
            temp2 = search(path+temp1, i,depth+1)+cache[curr][i];
            if(temp3 == temp2)
                return str[i].substr(str[i].size()-cache[curr][i],cache[curr][i])+make_str(path+temp1, i, depth+1);
        }
    }
}
int main()
{
    scanf("%d", &C);
    string input;
    while(C--)
    {
        str.clear();
        scanf("%d", &k);
        memset(&cache, 0, sizeof(cache));
        memset(&path_cache,-1, sizeof(path_cache));
        for(int i = 0; i < k; i++)
            cin>>input, str.push_back(input);
        size = rept();
        restore();
        search(0,0,0);
        cout<<make_str(0,0,0)<<"\n";
    }
}