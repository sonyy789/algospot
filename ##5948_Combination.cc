#include <cstdio>
#include <cstring>
int main(){
    int i, j , k, t, arr[7];
    scanf("%d", &t);
    for(int w = 1; w <= t; w++){
        for(i = 0; i < 7; i++)
            scanf("%d", &arr[i]);
        for(i = 0; i < 5; i++)
            for(j = i+1; j < 6; j++)
                for(k = j+1; k < 7; k++)
                    flag[arr[i]+arr[j]+arr[k]] = true;
        i = 298;
        int cnt = 0;
        while(i--){
            if(flag[i])
                if(++cnt == 5) break; 
        }            
        printf("#%d %d\n", w, i);
    }
}