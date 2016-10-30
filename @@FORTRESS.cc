#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int cache[101];
int result;
typedef struct node
{
    int x, y, r;
    vector<node *> next;
} NODE;
vector<NODE> arr;
double dist(node &set1, node &set2)
{
    return sqrt(pow(set1.x-set2.x,2)+pow(set1.y-set2.y,2));
}
void made_tree( node *A, node *B)
{
    (*A).next.push_back(&(*B));
}
int depth_tree(node *root)
{
    int size = (*root).next.size();
    if(size)
    {
        int length1, length2;
        length1 = length2 = 0;
        for(int i = 0; i < size; i++)
        {
            int temp = depth_tree((*root).next[i])+1;
            if(length1 < temp) length2 = length1, length1 = temp;
            else if(length2 < temp) length2 = temp; 
        }
        result = max(result, length1+length2-2);
        result = max(result, length1-1);
        return length1;
    }
    else return 1;
}
int main()
{
    int T, N, min_r, index;
    NODE input;
    cin>>T;
    while(T--)
    {
        cin>>N;
        result = 0;
        memset(&cache, -1, sizeof(cache));
        for(int i = 0; i < N; i++)
            cin>>input.x>>input.y>>input.r, arr.push_back(input);
        for(int i = 0 ; i < N; i++)
        {
            index = -1, min_r = 1001;
            for(int j = 0; j < N; j++)
                if(i != j && arr[i].r < arr[j].r)
                {
                    int radius = arr[i].r + arr[j].r;
                    if(dist(arr[i], arr[j]) < radius && min_r > arr[j].r)
                        min_r = arr[j].r, index = j;
                }
            cache[i] = index;
        }
        for(int i = 0; i < N; i++)
        {
            if(cache[i] > -1) made_tree(&arr[cache[i]], &arr[i]);
            else index = i;
        }
        depth_tree(&arr[index]);
        cout<<result<<endl;
        arr.clear();
    }
}
