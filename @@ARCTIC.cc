#include <iostream>
#include <math.h>
using namespace std;

typedef struct NODE{
    float x, y;
    int prev, next;
} node;
float mem[101][101] = {0};
void setup_mem(NODE *set, int N)
{
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            mem[i][j] = sqrt((set[i].x - set[j].x)*(set[i].x - set[j].x)+(set[i].y - set[j].y)*(set[i].y - set[j].y)); //distance;
        }
    }
}

void print(NODE *set2,int cnt)
{
    cout<<set2[cnt].next<<" ";
    if(set2[cnt].next == -1)
    {
        return;
    }
    else print(set2, set2[cnt].next);
}

float arctic(NODE *p, int N)
{
    pair<int, int> index;
    int tmp_index, index1, index2 = 1;
    float tmp, min, K = 0;
    for(int i = 0; i < N-1; i++)
    {
        tmp_index = index2;
        index1 = 0;
        min = 1000;
        while(index1 != -1)
        {
            index.first = index1;
            while(index2 != -1)
            {
                tmp = index1 > index2? mem[index2][index1]:mem[index1][index2];
                if(tmp < min)
                {
                    min = tmp;
                    index.second = index2;
                }
                index2 = p[index2].next;
            }
            index1 = p[index1].next;
            index2 = tmp_index;
        }
        K = K > min ? K:min;
        if(tmp_index == index.second) index2 = p[tmp_index].next;
        else p[p[index.second].prev].next = p[index.second].next;
        if(p[index.second].next != -1) p[p[index.second].next].prev = p[index.second].prev;
        p[index.first].next = index.second;
        p[index.second].next = -1;
        if(index.first > index.second) mem[index.second][index.first] = 1000;
        else mem[index.first][index.second] = 1000;
       //print(p, 0);
    }
    return K;
}
int main()
{
    int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        node *arr = new node[N];
        cin>>arr[0].x>>arr[0].y;
        arr[0].next = -1;
        for(int i = 1; i < N;i++)
        {
            cin>>arr[i].x>>arr[i].y;
            arr[i].prev = i - 1;
            arr[i].next = i + 1;
        }
        arr[N-1].next = -1;
        setup_mem(arr, N);
        float result = arctic(arr, N);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.precision(2);
        cout<<result<<"\n";
        delete[] arr;
    }
}