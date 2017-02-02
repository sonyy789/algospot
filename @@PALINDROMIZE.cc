#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 100001
using namespace std;
void getpi(vector<int> &set, char str[], int size)
{
    int i = 0, j = 1;
    while(j < size)
        if(str[i] == str[j])
        { 
            set[j] = i+1;
            i++, j++;
        }
        else
        {
            if(i) i = set[i-1];
            else j++;
        }
}
int chk(char str1[], char str2[], int size)
{
    int i, j;
    i = j = 0;
    vector<int> pi(size, 0);
    getpi(pi, str2, size);
    while(i < size)
        if(str1[i] == str2[j]) { i++, j++; }
        else
        {
            if(j) j = pi[j-1];
            else i++;
        }
    return j;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        char input1[MAX], input2[MAX];
        scanf("%s", input1);
        int size = strlen(input1);
        for(int i = 0; i < size; i++)
            input2[i] = input1[size-i-1];
        input2[size] = '\0';
        printf("%d\n", 2*size-chk(input1, input2, size));
    }
}