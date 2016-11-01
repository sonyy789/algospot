#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
#define MAX 50001
using namespace std;
vector<int> result;
struct Node
{
    int key, priority = rand();
    int size = 0;
    Node *left, *right;
    Node(const int value) : key(value), priority(rand()), size(1), left(NULL), right(NULL) { }
    void setleft(Node *newleft) { left = newleft; calcSize();}
    void setright(Node *newright) { right = newright; calcSize();}
    int calcSize()
    {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};
typedef pair<Node *, Node *> Nodepair;
Nodepair split(Node *root, int key)
{
    if(root == NULL) return Nodepair(NULL, NULL);
    if(root->key < key)
    {
        Nodepair temp = split(root->right, key);
        root->setright(temp.first);
        return Nodepair(root, temp.second);
    }
    Nodepair temp = split(root->left, key);
    root->setleft(temp.second);
    return Nodepair(temp.first, root);
}
Node *add_Node(Node *root, Node *Node)
{
    if(root == NULL) return Node;
    if(root->priority < Node->priority)
    {
        Nodepair temp = split(root, Node->key);
        Node->setleft(temp.first);
        Node->setright(temp.second);
        return Node;
    }
    else if(root->key > Node->key)
        root->setleft(add_Node(root->left, Node));
    else
        root->setright(add_Node(root->right, Node));
    return root;
}
Node *merge(Node *a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a->priority < b->priority)
    {
        b->setleft(merge(a,b->left));
        return b;
    }
    else
    {
        a->setright(merge(a->right, b));
        return a;
    }
}
Node *kth_search(Node *root, int k)
{
    int left_size = 0;
    if(root->left)  left_size = root->left->size;
    if(left_size >= k) root->setleft(kth_search(root->left, k));
    else if(left_size+1 < k) root->setright(kth_search(root->right, k-(left_size+1)));
    else if(left_size+1 == k)
    {
        result.push_back(root->key);
        Node *ret = merge(root->left, root->right);
        return ret;
    }
    return root;
}
int main()
{
    srand((unsigned int)time(NULL));
    int C, N;
    int rank[MAX];
    cin>>C;
    while(C--)
    {
        
        result.clear();
        cin>>N;
        for(int i = 0; i < N; i++)
            cin>>rank[i];
        Node *root = NULL;
        for(int i = 0; i < N; i++)
            root = add_Node(root, new Node(i+1));
            
        int size = N;
        for(int i = N-1; i > 0; i--)
        {
            root = kth_search(root, size-rank[i]);
            size--;
        }
        int index = result.size()-1;
        cout<<root->key;
        for(int i = index; i >= 0; i--)
            cout<<" "<<result[i];
        cout<<endl;
    }
}