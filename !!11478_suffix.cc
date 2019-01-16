#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char T[1002];
int LCP[1002];
struct A{
    int fr, sr, idx;
}SA[1002];
int R[1001];
bool compare(const struct A &A, const struct A &B){
    return A.fr==B.fr?(A.sr<B.sr):(A.fr<B.fr);
}
int main(){
    int i;
    scanf("%s", T+1);
    int tLen = strlen(T+1);
    for(i = 1; i <= tLen; i++)
        SA[i] = {T[i]-'a'+1,0,i};
    sort(SA+1, SA+tLen+1, compare);
    for(int len = 1; len < tLen; len <<= 1){
        int rank = 1;
        R[SA[1].idx] = rank;
        for(int i = 2; i <= tLen; i++)
            R[SA[i].idx] = (SA[i-1].fr==SA[i].fr && SA[i-1].sr==SA[i].sr)?rank:++rank;
        for(int i= 1; i <= tLen; i++){
            SA[i].fr = R[SA[i].idx];
            if(SA[i].idx+len > tLen) SA[i].sr = 0;
            else SA[i].sr = R[SA[i].idx+len];
        }
        sort(SA+1, SA+tLen+1, compare);
    }
    for(int i = 2; i <= tLen; i++){
        int prevIdx = SA[i-1].idx;
        int currIdx = SA[i].idx;
        int cnt = 0;
        while(1){
            if(T[prevIdx] != T[currIdx] || prevIdx > tLen || currIdx > tLen) break;
            prevIdx++, currIdx++;
            cnt++;
        }
        LCP[i] = cnt;
    }
    int ans = 0;
    for(int i = 1; i <= tLen; i++)
        ans += (tLen-i+1-LCP[i]);
    printf("%d", ans);
}#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char T[1002];
int LCP[1002];
struct A{
    int fr, sr, idx;
}SA[1002];
int R[1001];
bool compare(const struct A &A, const struct A &B){
    return A.fr==B.fr?(A.sr<B.sr):(A.fr<B.fr);
}
int main(){
    int i;
    scanf("%s", T+1);
    int tLen = strlen(T+1);
    for(i = 1; i <= tLen; i++)
        SA[i] = {T[i]-'a'+1,0,i};
    sort(SA+1, SA+tLen+1, compare);
    for(int len = 1; len < tLen; len <<= 1){
        int rank = 1;
        R[SA[1].idx] = rank;
        for(int i = 2; i <= tLen; i++)
            R[SA[i].idx] = (SA[i-1].fr==SA[i].fr && SA[i-1].sr==SA[i].sr)?rank:++rank;
        for(int i= 1; i <= tLen; i++){
            SA[i].fr = R[SA[i].idx];
            if(SA[i].idx+len > tLen) SA[i].sr = 0;
            else SA[i].sr = R[SA[i].idx+len];
        }
        sort(SA+1, SA+tLen+1, compare);
    }
    for(int i = 2; i <= tLen; i++){
        int prevIdx = SA[i-1].idx;
        int currIdx = SA[i].idx;
        int cnt = 0;
        while(1){
            if(T[prevIdx] != T[currIdx] || prevIdx > tLen || currIdx > tLen) break;
            prevIdx++, currIdx++;
            cnt++;
        }
        LCP[i] = cnt;
    }
    int ans = 0;
    for(int i = 1; i <= tLen; i++)
        ans += (tLen-i+1-LCP[i]);
    printf("%d", ans);
}