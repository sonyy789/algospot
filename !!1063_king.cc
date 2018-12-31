#include <cstdio>
int main(){
    int n;
    char k[3], r[3], c[3];
    scanf("%s%s", k, r);
    scanf("%d", &n);
    while(n--){
        scanf("%s", c);
        int ay = 0, ax =0;
        for(int i = 0; i < 2; i++){
            if(c[i]=='R') ax++;
            else if(c[i] == 'L') ax--;
            else if(c[i] == 'T') ay++;
            else if(c[i] == 'B') ay--;
        }
        k[0]+=ax; k[1]+=ay;
        if(k[0] < 'A' || k[0] >'H' || k[1] <'1'|| k[1] >'8') {k[0] -= ax; k[1]-=ay; continue;}
        if(k[0] == r[0] && k[1] == r[1]){
            r[0]+=ax; r[1]+=ay;
            if(r[0] < 'A' || r[0] >'H' || r[1] <'1'|| r[1] >'8') {k[0] -= ax; k[1]-=ay; r[0] -= ax; r[1]-=ay;continue;}
        }
    }
    printf("%s\n%s", k, r);
}