#include <cstdio>
#include <algorithm>
char A[2][100*100];
char in[101];
int n, a, b, size, st[100*100];
void dfs(int f, int idx){
    int num = 0;
    char flag = A[f][idx];
    st[num++] = idx;
    while(num){
        int cur = st[--num];
        if(A[f][cur] == 'G') A[1][cur] = 'R';
        int y = cur/n;
        int x = cur%n;
        A[f][cur] = 'X';    
        if(x > 0 && A[f][cur-1] == flag) st[num++] = cur-1;
        if(y > 0 && A[f][cur-n] == flag) st[num++] = cur-n;
        if(x < n-1  && A[f][cur+1] == flag) st[num++] = cur+1;
        if(y < n-1  && A[f][cur+n] == flag) st[num++] = cur+n;
    }
}
void dfsAll(){
    a = b = 0;
    std::copy(A[0], A[0]+n*n,A[1]);
    for(int i = 0; i < size; i++)
        if(A[0][i] != 'X') dfs(0,i), a++;
    for(int i = 0; i < size; i++)
        if(A[1][i] != 'X') dfs(1,i), b++;
}
int main(){
    scanf("%d", &n);
    size = n*n;
    for(int i = 0; i < n; i++){
        scanf("%s", in);
        for(int j = 0; j < n; j++)
            A[0][i*n+j] = in[j];
    }
    dfsAll();
    printf("%d %d\n", a, b);
}