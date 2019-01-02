#include <cstdio>
int main(){
    int y, n;
    float x, val;
    scanf("%f%d%d", &x, &y, &n);
    val = x/y;
    for(int i = 1; i <= n; i++){
        scanf("%f%d", &x, &y);
        float tmp = x/y;
        val = val < tmp ? val:tmp;
    }
    printf("%.2f", val*1000);
}
