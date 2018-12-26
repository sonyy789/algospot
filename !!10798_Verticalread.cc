#include <cstdio>
int main(){
	int i, j;
	char A[6][16] = {0, };
	for(i = 0; i < 5; i++)
		scanf("%s", A[i]);
	for(j = 0; j < 15; j++)
		for(i = 0; i < 5; i++)
			if(A[i][j]) printf("%c", A[i][j]);
}