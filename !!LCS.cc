#include <cstdio>
#include <cstring>
int max(int a, int b) {return a>b? a:b;}
int main()
{
    int a, b, ans = 0;
    char A[1001], B[1001], c;
    short cache[1000]={0};
    scanf("%s%s", A, B);
    a = strlen(A)-1;
    b = strlen(B)-1;
    for(a; a >= 0; a--)
    {
        int temp = 0;
        for(int i = b; i >= 0; i--)
        {
            if(A[a]==B[i])
            {
                if(cache[i]<=temp) cache[i] = temp+1;
                else temp = max(temp, cache[i]);
            }
            else temp = max(temp, cache[i]);
        }
    }
    for(int i = 0; i <= b; i++)
        ans = max(ans, cache[i]);
    printf("%d\n", ans);
}