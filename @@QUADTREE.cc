#include <iostream>
using namespace std;
typedef struct NODE{
    pair<char, NODE *> p[4];
} node;
NODE* quadtree(string set, int &index)
{
    node *A = new node;
    for(int i = 0; i < 4; i++)
    {
        A->p[i].second = NULL;
    }
    for(int i = 0 ; i < 4; i++)
    {
        A->p[i].first = set[++index];
        if(set[index] == 'x') A->p[i].second = quadtree(set, index);
    }
    return A;
}
int del(NODE *pr)
{
    for(int i = 0;  i< 4; i++)
    {
        if(pr->p[i].second) del(pr->p[i].second);
    }
    delete[] pr;
}
void print(NODE *pr)
{
    for(int i = 2; i < 4; i++)
    {
        cout<<pr->p[i].first;
        if(pr->p[i].second) print(pr->p[i].second);
    }
    for(int i = 0; i < 2; i++)
    {
        cout<<pr->p[i].first;
        if(pr->p[i].second) print(pr->p[i].second);
    }
    return;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a = 0;
        string input;
        cin>>input;
        if(input.size() == 1) cout<<input<<endl;
        else
        {
         NODE *tmp = quadtree(input, a);
         cout<<"x";
         print(tmp);
         cout<<endl;
         del(tmp);
        } 
        input.clear();
    }
}

// quadtree !! using linked - node 
/*

####example
1. quadtree little solution
input : 1234
output : 3412

2. using recursion

3. delete node that dynamic allocation node using in recursion
   <!!!! THIS PART is obscure !!!!! Have to modify >

*/