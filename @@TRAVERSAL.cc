#include <cstdio>
#include <map>
using namespace std;
map<int, int> index;
typedef struct node
{
    int value;
    node *left = NULL;
    node *right = NULL;
} NODE;
void make_node(NODE *comp1, NODE *comp2)
{

    if(  index[comp1->value] < index[comp2->value])
    {
        if(comp2->left) make_node(comp1, comp2->left);
        else comp2->left = comp1;
    }
    else
    {
        if(comp2->right) make_node(comp1, comp2->right);
        else comp2->right = comp1;
    }
}
void print(node *curr)
{
    if(curr->left) print(curr->left);
    if(curr->right) print(curr->right);
    printf("%d ",curr->value);
}
int main()
{
    int C, N, input, cnt;
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d", &N);
        cnt = 0;
        NODE *set = new NODE[N];
        for(int i = 0; i < N; i++)
            scanf("%d", &set[i].value);
        for(int i = 0; i < N; i++)
            scanf("%d", &input), index.insert(make_pair(input, cnt++));
        for(int i = 1; i < N; i++)
            make_node(&set[i], &set[0]);
        print(&set[0]);
        printf("\n");
        delete[] set;
        index.clear();
    }
}