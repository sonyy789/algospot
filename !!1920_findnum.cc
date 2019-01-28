#include <cstdio>
#include <unordered_map>
using namespace std;

int n, m, i, num;
int main(){
    unordered_map<int, bool> um;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &num);
        um[num] = true;
    }
    scanf("%d", &m);
    for(i = 1; i <= m; i++){
        scanf("%d", &num);
        printf("%d\n", um[num]?1:0);
    }
}