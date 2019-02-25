#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, i, j, idx;
int main(){
    vector<int> A;
    A.push_back(666);
    for(i = 1000; i <= 1000000; i *= 10){
        int size = A.size();
        for(idx; idx<size; idx++){
            int data = A[idx];
            for(j = 0; j <= 9; j++){
                A.push_back(data*10+j);    
                A.push_back(i*j+data);
            }
        }
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()),A.end());
    scanf("%d", &n);
    printf("%d", A[n-1]);
}
