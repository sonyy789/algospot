#include <cstdio>
#include <algorithm>
using namespace std;
struct Person { 
    int a, b;
    bool operator <(const Person &P)const{return a<P.a;}
};
Person P[100001];
int t, n, i;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d%d", &P[i].a, &P[i].b);
        
        sort(&P[1], &P[n+1]);
        int cnt = 1, rank = P[1].b;
        for(i = 2; i <= n; i++)
            if(rank > P[i].b){ 
                cnt++;
                rank = P[i].b;
            }
        printf("%d\n", cnt);
    }
}