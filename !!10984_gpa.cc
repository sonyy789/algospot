#include <cstdio>
#include <cmath>
int main(){
    int t, n, a;
    float b;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int sum = 0;
        float gpa = 0.0f;
        for(int i = 0; i < n; i++){
            scanf("%d %f", &a, &b);
            sum += a; gpa += b*a;
        }
        printf("%d %.1f\n", sum, gpa/sum);
    }
}