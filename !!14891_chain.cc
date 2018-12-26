#include <cstdio>
#include <cmath>
int L[4], R[4];
char A[4][9];
int B[4];
int score(int num){
    char top = A[num][(L[num]+2)%8];
    if(top != '0') return pow(2,num);
    else return 0;
}
int main(){
    int num, dir, a = 0, b = 1, k;
    for(int i = 0; i < 4; i++) scanf("%s", A[i]);
    L[0] = L[1] = L[2] = L[3] = 6;
    R[0] = R[1] = R[2] = R[3] = 2;
    scanf("%d", &k);
    while(k--){
        scanf("%d%d", &num, &dir);
        num--;
        for(int i = 0; i < 4; i++) B[i] = 0;
        B[num] = dir;
        int tmpDir = -dir;
        for(int i = num; i < 3; i++){
            if(A[i][R[i]] == A[i+1][L[i+1]]) break;
            B[i+1] = tmpDir; tmpDir = -tmpDir;
        }
        tmpDir = -dir;
        for(int i = num; i > 0; i--){
            if(A[i][L[i]] == A[i-1][R[i-1]]) break;
            B[i-1] = tmpDir; tmpDir = -tmpDir;
        }
        for(int i = 0; i < 4; i++){
    		if(B[i] == 0) continue;
    		else if(B[i] > 0) L[i] = (L[i]+7)%8, R[i] = (R[i]+7)%8; 
			else L[i] = (L[i]+1)%8, R[i] = (R[i]+1)%8;
        }
    }
    int ans = 0;
	for(int i = 0; i < 4; i++)
		ans += score(i);
    printf("%d", ans);
}