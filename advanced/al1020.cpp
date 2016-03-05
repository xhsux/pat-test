#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct NODE
{
    int value;
    NODE* left;
    NODE* right;
} *PNODE;
int postord[35] = {0}, inord[35] = {0};
int n;

void getnode(int* order, int n)
{
    for(int i = 0; i != n; ++i)
    {
        int tmp;
        cin >> tmp;
        order[i] = tmp;
    }
}

PNODE buildtree(int pl, int pr, int il, int ir)
{
    if(pl > pr) return NULL;
    int val = postord[pr];
    int inpos = find(inord, inord + n, val) - inord;
    PNODE cur = new NODE;
    cur->value = val;
    cur->left = buildtree(pl, pr - ir + inpos - 1, il, inpos - 1);  // pr - (ir - inpos) - 1
    cur->right = buildtree(pr - ir + inpos, pr - 1, inpos + 1, ir); // pr - (ir - inpos)
    // ir - inpos 个数肯定在inpos数的右边
    return cur;
}

void levelprint(PNODE root) //bfs
{
    queue<PNODE> q;
    PNODE cur = NULL;
    q.push(root);
    bool isbg = true;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if(cur == NULL) continue;
        if(isbg)
        {
            cout << cur->value;
            isbg = false;
        }
        else
            cout << " " << cur->value;
        q.push(cur->left);
        q.push(cur->right);
    }
    cout << endl;
}

int main()
{
    cin >> n;
    getnode(postord, n);
    getnode(inord, n);
    NODE* root = new NODE; //create root node
    root = buildtree(0, n - 1, 0 , n - 1);
    levelprint(root);
    return 0;
}