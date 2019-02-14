#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10000
using namespace std;
char str1[MAX], str2[MAX], ans[MAX];
int i, j, len, idx, db_ptr;
void multiple(char *a, char *b, int &f_ptr1, int f_ptr2){
    int t = 0, tt, aa, bb, c_len;
    char c[MAX];
    for(i = 1; i < MAX; i++) c[i] ='0';
    for(i = 1; b[i] != '\0'; i++){
        bb = b[i]-'0';
        for(j = 1; a[j] != '\0'; j++){
            aa = a[j]-'0';
            tt = aa*bb+t+c[i+j-1]-'0';
            t = tt/10;
            c[i+j-1] = (tt%10)+'0';
        }
        while(t){
            tt = t+c[i+j-1]-'0';
            t = tt/10;
            c[i+j-1] = (tt%10)+'0';
            j++;
        }
    }
    c_len = i+j-2;
    c[c_len] = '\0';
    for(i = 1; i <= c_len; i++) a[i] = c[i];
    f_ptr1 += f_ptr2;
}
void solve(char *a, int &f_ptr, int b){
    if(b == 1) return;
    solve(a, f_ptr, b>>1);
    multiple(a,a,f_ptr, f_ptr);
    if(b%2) multiple(a, str2, f_ptr, db_ptr);
}
int main(){
    int b, f_ptr;
    bool f = true;
    scanf("%s%d",str1+1, &b);
    len = strlen(str1+1);
    
    for(i = len; i >= 1; i--){
        if(str1[i] == '.') {f = false; continue; }
        if(f) db_ptr++;
        str2[++idx] = str1[i];
    }
    str2[++idx] = '\0';
    f_ptr = db_ptr;
    strcpy(str1+1, str2+1);
    
    solve(str1, f_ptr, b);
    len = strlen(str1+1);
    for(i = len; i >= 1; i--){
        if(i == f_ptr) printf(".");
        printf("%c", str1[i]);
    }
}