#include <iostream>
#include <climits>
using namespace std;

#define NODEN 1010
int tree[NODEN] = {0};
int n;
bool notfirst = false;

typedef struct NODE{
    int val;
    NODE* left = NULL;
    NODE* right = NULL;
}* PNODE;

PNODE isBST(int hd, int tl, int lwrbnd, int uppbnd, bool ismirror, bool& isok)
{
    if(tl < hd) return NULL;
    int value = tree[hd];
    int i = hd + 1;
    if(!ismirror)
    {
        for(; i <= tl; )
        {
            int cur = tree[i];
            if(cur >= lwrbnd && cur < uppbnd)
            {
                if(value - cur > 0)
                    i++;
                else
                    break;
            }
            else
            {
                isok = false;
                break;
            }
        }
    }
    else
    {
        for(; i <= tl; )
        {
            int cur = tree[i];
            if(cur >= lwrbnd && cur < uppbnd)
            {
                if(value - cur <= 0)
                    i++;
                else
                    break;
            }
            else
            {
                isok = false;
                break;
            }
        }
    }
    if(!isok) return NULL;
    PNODE cur = new NODE;
    cur->val = value;
    if(!ismirror)
    {
        cur->left = isBST(hd + 1, i - 1, lwrbnd, value, ismirror, isok);
        cur->right = isBST(i, tl, value, uppbnd, ismirror, isok);
    }
    else
    {
        cur->left = isBST(hd + 1, i - 1, value, uppbnd, ismirror, isok);
        cur->right = isBST(i, tl, lwrbnd, value, ismirror, isok);
    }
    return cur;
}

void printpostorder(PNODE root)   //dfs LRD
{
    if(root == NULL)
        return;
    printpostorder(root->left);
    printpostorder(root->right);
    if(notfirst)
        cout << " ";
    if(!notfirst)
        notfirst = true;
    cout << root->val;
}

int main()
{
    bool BSTflag = true;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> tree[i];
    }
    PNODE root = new NODE;
    root = isBST(0, n - 1, INT_MIN, INT_MAX, false, BSTflag);
    if(!BSTflag)
    {
        BSTflag = true;
        root = isBST(0, n - 1, INT_MIN, INT_MAX, true, BSTflag);
    }
    if(BSTflag)
    {
        cout << "YES" << endl;
        printpostorder(root);
    }
    else
        cout << "NO";
    cout << endl;
    return 0;
}