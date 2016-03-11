#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;
#define MAXN 1000000
// this macro is set to improve
#define pos(i, j, k) node[i + 1][j + 1][k + 1]
int fa[MAXN] = {0};     //initialize father node with a unique index
int visited[MAXN] = {0};
int vol[MAXN] = {0};
int m, n, l, t;
int node[65][1300][140] = {0};
queue<int> q;
int faset[MAXN] = {0};  //an array to store every unique father node

void setneighbor(const int& hgt, const int& row, const int& col,const int& ix)  //up right forward
{
    int nb = hgt * m * n + row * n + col;
    if(visited[nb] || !pos(hgt, row, col)) return;
//    printf("current (%d, %d, %d), ix (%d)\n", hgt, row, col, nb);
    q.push(nb);
    int hd = fa[ix];
    vol[hd]++;
//    printf("volume of (%d, %d, %d): %d\n", hgt, row, col, vol[hd]);
    fa[nb] = hd;            // similar to union-find set, set every node in the same tree with a same father.
    visited[nb] = 1;
}

int getindex(const int& x, const int& y, const int& z)       //give each node an index by its coordinates
{
    return x * m * n + y * n + z;
}

bool quickfind(int* arr, int hd, int ed, int& tar)      // a binary search is required to meet the time limits
{
    // To satisfy the condition below, the last number should be replaced by a big number if it is zero.
    // Otherwise the right-side inequality will always hold and this check would fail.
    if(tar < arr[hd] || tar > arr[ed - 1]) return false;
    int mid = ( hd + ed ) / 2;
    int diff = arr[mid] - tar;
    if(diff == 0) return true;
    else
    if(diff < 0)
        return quickfind(arr, mid + 1, ed, tar);
    else
        return quickfind(arr, hd, mid, tar);
}

int main()
{
    cin >> m >> n >> l >> t;
    for(int i = 0; i != l; ++i)
        for(int j = 0; j != m; ++j)
            for(int k = 0; k != n; ++k)
            {
                int cur_nd;
                cin >> cur_nd;
                int ix = getindex(i, j, k);
                fa[ix] = ix;    //initialize father node of each node to itself
                if(cur_nd)  vol[ix] = 1;
                pos(i, j, k) = cur_nd;
            }
    for(int i = 0; i != l; ++i)
        for(int j = 0; j != m; ++j)
            for(int k = 0; k != n; ++k)
            {
                if(!pos(i, j, k)) continue; // process only if its a "1" node
                int ix = getindex(i, j, k);
                q.push(ix);
                while(!q.empty())       // bfs, traverse every unique core
                {
                    int cur = q.front();
                    q.pop();
                    visited[cur] = 1;
                    int hgt, row, col;
                    hgt = row = col = 0;
                    // resolve (cur, row, hgt) from its index
                    col = cur % n;
                    row = (cur - col) / n % m;
                    hgt = (cur - col - row * n) / m / n;
//                    printf("resolved index: (%d) %d %d %d\n", cur, hgt, row, col);
                    if(pos(hgt, row, col))
                    {
                        setneighbor(hgt, row, col - 1, cur);
                        setneighbor(hgt, row - 1, col, cur);
                        setneighbor(hgt - 1, row, col, cur);
                        setneighbor(hgt, row, col + 1, cur);
                        setneighbor(hgt, row + 1, col, cur);
                        setneighbor(hgt + 1, row, col, cur);
                    }
                }
            }
    int total = 0;
    int edix = 1;
    for(int i = 0; i != l; ++i)
        for(int j = 0; j != m; ++j)
            for(int k = 0; k != n; ++k)
            {
                if(!pos(i, j, k)) continue;
                int ix = getindex(i, j, k);
                int hd = fa[ix];
                int tstkey = hd + 1;
                if(!quickfind(faset, 0, edix, tstkey))
                {
                    faset[edix - 1] = tstkey;
                    faset[edix] = INT_MAX;  // a large number to ensure the upper bound enough big
                    edix++;
                    if(vol[hd] >= t)
                        total += vol[hd];
                }
            }
    cout << total << endl;
    return 0;
}