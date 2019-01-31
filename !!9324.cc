#include <cstdio>
using namespace std;

int t, n, i, j;
char m[100005];
int C[27];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", m+1);
        for(i = 1; m[i] != '\0'; i++){
            if(C[m[i]-'A'] == 0) C[m[i]-'A'] = 1;
            else{
                if(++C[m[i]-'A'] == 3){
                    if(m[i] != m[i+1]) break;
                    C[m[i]-'A'] = 0;
                    i++;
                }
            }
        }
        printf("%s\n", m[i] =='\0'?"OK":"FAKE");
    }
}    
