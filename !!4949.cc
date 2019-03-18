#include <cstdio>
char st[101], in[102];
int main(){
    int i;
    while(1){
        scanf("%[^\n]s", in+1);
        getchar();
        if(in[1] == '.' && in[2] =='\0') break;
        int st_idx = 0;
        for(i = 1; in[i] != '\0'; i++){
            if(in[i] == '(' || in[i] == '[') st[++st_idx] = in[i];
            else if(in[i] == ')' || in[i] == ']'){
                if(st[st_idx] != in[i]-1 && st[st_idx] != in[i]-2) break;
                st_idx--;
            }
        }
        printf("%s\n", (st_idx||(in[i] != '\0'))?"no":"yes");
    }
}