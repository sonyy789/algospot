#include <cstdio>
using namespace std;
int tree[10001];
int node_cnt = 0;
int post_order(int idx, int root){
    int left_sub = 0, right_sub = 0;
    if(idx+1 <= node_cnt && tree[idx+1] < tree[idx]) left_sub = post_order(idx+1, tree[idx]);
    if(left_sub+idx+1 <=node_cnt && tree[left_sub+idx+1] > tree[idx] && tree[left_sub+idx+1] < root) 
        right_sub = post_order(left_sub+idx+1, root);
    printf("%d\n",tree[idx]);
    return left_sub+right_sub+1;
}
int main(){
    int val;
    while(scanf("%d",&val) != -1){
        tree[++node_cnt] = val;
    }
    post_order(1, 1e9);
}