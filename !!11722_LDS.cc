#include <cstdio>
int main(){
    int n, temp, ans = 0;
    int arr[1001], mem[1001];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        mem[i] = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++)
            if(arr[i]>arr[j]){
                temp = mem[i]+1;
                mem[j] = mem[j]<temp?temp:mem[j];
            }
    }
    for(int i = 0; i < n; i++)
        ans = ans > mem[i]? ans:mem[i];
    printf("%d\n", ans+1);
}