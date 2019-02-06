#include <cstdio>
#include <cstring>
using namespace std;
int g, p, g_num, ans;
int root[100001];
int find(int a){
    if(root[a] < 0) return a;
    return root[a] = find(root[a]);
}
void merge(int a, int b){
    a = find(a); b = find(b);
    if(a==b) return;
    root[b] = a;
}
int main(){
    int i;
    scanf("%d%d",&g,&p);
    memset(root, -1, sizeof root);
    while(p--){
        scanf("%d", &g_num);
        int r = find(g_num);
        if(r == 0) break;
        merge(r-1, r);
        ans++;
    }
    printf("%d", ans);
}