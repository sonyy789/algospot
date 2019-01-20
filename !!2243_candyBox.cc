#include <cstdio>
#include <cmath>
using namespace std;
int tree[2097200];
int nodeIdx;
void update(int curr, int diff){
    while(curr > 0){
        tree[curr] += diff;
        curr /= 2;
    }
}
int search(int order){
    int idx = 1;
    while(1){
        if(idx > nodeIdx){
            update(idx, -1);
            return idx-nodeIdx;
        }
        if(tree[idx*2] >= order) idx *= 2;
        else order -= tree[idx*2], idx = 2*idx+1;
    }
}
int main(){
    int a,b,c,i, j, n, size;
    nodeIdx = 1<<((int)ceil(log2(1000000)));
    size = (nodeIdx<<1)+1; 
    nodeIdx--;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &a, &b);
        if(a == 1){
            printf("%d\n", search(b));
        }else{
            scanf("%d", &c);
            update(nodeIdx+b, c);
        }
    }
}