#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 1010
#define BIGN 10000
struct MOUSE
{
    int weight;
    int index;
    int rank = 0;
};
MOUSE mice[MAXN];

bool cmp(MOUSE& a, MOUSE& b)
{
    return a.weight < b.weight;
}

int order[BIGN];    // apply an big enough memory to store the order list

int main()
{
    int np, ng, cnt;
    cin >> np >> ng;
    cnt = np;
    memset(order, -1, sizeof(order));
    for(int i = 0; i != np; ++i)
    {
        int tmp;
        cin >> tmp;
        mice[i].index = i;
        mice[i].weight = tmp;
    }
    for(int i = 0; i != np; ++i)
    {
        int tmp;
        cin >> tmp;
        order[i] = tmp;
    }
    int res, cur_rank = 1, newix = np, ixoffset = 0;
    while(np != 1)  //only one people left.
    {
        res = np % ng ? 1 : 0;
        cur_rank = np / ng + res + 1;
        for(int ix = 0; ix < cur_rank - 1; ++ix)
        {
            int maxix = ix * ng + ixoffset;
            for(int i = 1; ; ++i)     //search each group to find its champion
            {
                if(i >= ng || (ix * ng + i) >= np) break;
                int cur_ix = ix * ng + i + ixoffset;
                if(mice[order[cur_ix]].weight > mice[order[maxix]].weight)
                {
                    mice[order[maxix]].rank = cur_rank;
                    maxix = cur_ix;
                }
                else
                    mice[order[cur_ix]].rank = cur_rank;
            }
            order[newix++] = order[maxix];  //add the winner to the end of the order list
        }
        ixoffset += np;
        np = cur_rank - 1;
    }
    bool startflag = true;
    for(int i = 0; i != cnt; ++i)
    {
        int rk = (!mice[i].rank) ? 1 : mice[i].rank;
        if(startflag)
        {
            cout << rk;
            startflag = false;
        }
        else
            cout << " " << rk;
    }
    cout << endl;
    return 0;
}