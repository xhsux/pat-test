#include <iostream>
#include <list>
#include <queue>
using namespace std;
#define MAXN 110
list<int> nd[MAXN];
int cnt[MAXN] = {0};
int levelcnt[MAXN] = {0};       //levelcnt[x]: number of the next level of x
int main()
{
    int m, n;
    cin >> n >> m;
    levelcnt[0] = 1;
    while(m--)
    {
        int node, ndcnt;
        cin >> node >> ndcnt;
        cnt[node] = ndcnt;
        while(ndcnt--)
        {
            int tmp;
            cin >> tmp;
            nd[node].push_back(tmp);
        }
    }
    queue<int> q;
    q.push(1);
    int depth = 1;
    int leftcnt = cnt[depth];
    levelcnt[1] = cnt[depth];
    while(!q.empty())
    {
        if(leftcnt == 0)
        {
            depth += 1;
            leftcnt = levelcnt[depth];
        }
        int cur = q.front();
        q.pop();
        for(list<int>::iterator it = nd[cur].begin(); it != nd[cur].end(); ++it)
        {
            int next = *it;
            q.push(next);
            levelcnt[depth + 1] += cnt[next];
        }
        leftcnt -= cnt[cur];
    }
    int maxcnt = levelcnt[0];
    int depthlevel = 1;
    for(int i = 1; levelcnt[i]; ++i)
    {
        if(levelcnt[i] > maxcnt)
        {
            maxcnt = levelcnt[i];
            depthlevel = i + 1;
        }
    }
    cout << maxcnt << " " << depthlevel << endl;
    return 0;
}