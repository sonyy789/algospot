#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long int lld;
lld A[4000000];
int main(){
    lld a, b, c;
    int k, idx;
    for(k = 1;; k++){
        unordered_map<lld,lld> IN;
        unordered_map<lld,bool> L;
        idx = 0;
        while(1){
            c = 0;
            scanf("%lld%lld", &a, &b);
            if((a==0&&b==0)||(a==-1&&b==-1)) { break;}
            if(IN[b] == 0) IN[b] = 1;
            else IN[b]++;
            if(L[a] == 0) A[idx++] = a, L[a] = true;
            if(L[b] == 0) A[idx++] = b, L[b] = true;
        }
        if((a==-1&&b==-1)) break;
        int cnt = 0;
        for(int i = 0; i < idx; i++){
            if(IN[A[i]] == 1) cnt++;
        }
        if((cnt == idx-1)|| idx == 0) printf("Case %d is a tree.\n", k);
        else printf("Case %d is not a tree.\n", k);
    }
}