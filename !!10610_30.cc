#include <cstdio>
#include <algorithm>
using namespace std;
int C[10];
int main(){
    char N[100002];
    scanf("%s", N);
    int len = 0, sum = 0;
    for(len; N[len] != '\0'; len++){
        int num = N[len]-'0';
        C[num]++;
        sum += num;
    }
    if(sum%3 || C[0] == 0) printf("-1");
    else{
        for(len = 9; len >= 0; len--){
            while(C[len]--){
                printf("%d",len);
            }
        }
    }
}