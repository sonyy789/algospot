#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int visit[26];
int main(){
    char s[51];
    int len, cnt = 1, oddCnt = 0;
    vector<char> st[2]; //even//odd
    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; i++) visit[s[i]-'A']++;
    for(int i = 0; i < 26; i++){
        if(!visit[i]) continue;
        while(visit[i] >= 2){
            visit[i] -= 2;
            st[0].push_back(i+'A');
        }
        if(visit[i]) {st[1].push_back(i+'A'); oddCnt++;}
    }
    if(oddCnt > 1) printf("I'm Sorry Hansoo");
    else{
        for(char data:st[0]) printf("%c", data);
        for(char data:st[1]) printf("%c", data);
        for(int i = st[0].size()-1; i >=0; i--) printf("%c", st[0][i]);
    }
}