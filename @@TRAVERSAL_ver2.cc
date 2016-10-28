#include <cstdio>
using namespace std;
int cache[1001];
int arr[101];
void make_node(int idx1, int idx2)
{
    if(idx1 > idx2) return;
    int temp = idx2+1;
    int value = arr[idx1];
    for(int i = idx1+1; i <= idx2; i++)
    {
        if(cache[value]<cache[arr[i]])
        {
            temp = i;
            break;
        }
    }
    make_node(idx1+1,temp-1);
    make_node(temp, idx2);
    printf("%d ", value);
}
int main()
{
    int C, N, input;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
            scanf("%d",&arr[i]);
        for(int i = 0; i < N; i++)
            scanf("%d",&input), cache[input]=i;
        make_node(0,N-1);
        printf("\n");
    }
}