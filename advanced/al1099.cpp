#include <iostream>
#include <algorithm>
#include <queue>
using  namespace std;

struct NODE; typedef NODE* PNODE;
struct NODE
{
    int value;
    PNODE left = NULL;
    PNODE right = NULL;
};

#define MAXN 110
NODE tree[MAXN];
int ndval[MAXN] = {0};
static int ix = 0;
void buildtree(int i)
{
    int lnd, rnd;
    cin >> lnd >> rnd;
    PNODE cur = &tree[i];
    if(lnd != -1)
        cur->left = &tree[lnd];
    if(rnd != -1)
        cur->right = &tree[rnd];
}

void insertval(PNODE cur)    //dfs
{
    if(cur->left == NULL && cur->right == NULL)
    {
        cur->value = ndval[ix++];
        return;
    }
    if(cur->left != NULL) insertval(cur->left);
    cur->value = ndval[ix++];
    if(cur->right != NULL) insertval(cur->right);
    return;
}

void printval(PNODE root) //bfs
{
    queue<PNODE> q;
    q.push(root);
    bool space = false;
    while(!q.empty())
    {
        PNODE cur = q.front();
        q.pop();
        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);
        if(!space)
        {
            cout << cur->value;
            space = true;
        }
        else
            cout << " " << cur->value;
    }
}

int main()
{
    int n;
    cin >> n;
    int i = 0;
    for(; i != n; ++i)
        buildtree(i);
    for(i = 0; i != n; ++i)
        cin >> ndval[i];
    sort(ndval, ndval + i);
    insertval(&tree[0]);
    printval(&tree[0]);
    return 0;
}