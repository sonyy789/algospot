#include <cstdio>
char dict[2502], word[52];
int i, j, ans;
int main(){
    scanf("%[^\n]s", dict+1);
    getchar();
    scanf("%[^\n]s", word+1);
    for(i = 1; dict[i] != '\0'; i++){
        for(j = 1; word[j] != '\0'; j++)
            if(dict[i+j-1] != word[j]) break; 
        if(word[j] == '\0'){
            ans++;
            i = i+j-2;
        }   
    }
    printf("%d", ans);
}
