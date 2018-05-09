#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 20001
using namespace std;
vector<int> G[MAX];
int st[MAX], flag[MAX];
int k, e, v, a, b;
bool ans;
void dfs(int idx){
    flag[idx] = 1;
    int num = 0;
    st[num++] = idx;
    while(num){
        int cur = st[--num];
        for(int i = 0; i < G[cur].size(); i++){
            int next = G[cur][i];
            if(flag[next] == 0){
                st[num++] = next;
                flag[next] = -flag[cur];
            }else{
                if(flag[cur] == flag[next]){
                    ans = false;
                    return;
                }
            }
        }
    }
}
int main(){
    scanf("%d", &k);
    while(k--){
        scanf("%d %d", &v, &e);
        for(int i = 1; i <= v; i++){
            G[i].clear();
            flag[i] = 0;
        }
        while(e--){
            scanf("%d %d", &a, &b);
            G[b].push_back(a);
            G[a].push_back(b);
        }
        ans = true;
        for(int i = 1; i <= v; i++){
            if(!ans) break;
            if(flag[i] == 0) dfs(i);
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
}