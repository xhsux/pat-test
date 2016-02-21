#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

struct node{
    int add;
    int dat;
    int nxt;
}tmp;
using namespace std;
int main()
{
    node invec[100010];
    vector<node> outvec,sortvec;
    int headAdd;
    int num,rev;
    scanf("%d %d %d",&headAdd,&num,&rev);
    for(int i = 0; i < num; ++i)
    {
        scanf("%d %d %d",&tmp.add,&tmp.dat,&tmp.nxt);
        invec[tmp.add] = tmp;
    }
    if(headAdd == -1)
        printf("-1\n");
    while(headAdd != -1)
    {
        sortvec.push_back(invec[headAdd]);
        headAdd = invec[headAdd].nxt;
    }
    int len = sortvec.size();
    for(int i = rev; i <= len; i += rev)
    {
        for(int j = i-1; j >= i-rev; --j)
        {
            outvec.push_back(sortvec[j]);
        }
    }
    for(int i = (len/rev)*rev; i < len; ++i)
        outvec.push_back(sortvec[i]);
    for(int i = 0; i < len-1; ++i)
    {
        outvec[i].nxt=outvec[i+1].add;
    }
        outvec[len-1].nxt = -1;
    vector<node>::iterator it;
    for(it = outvec.begin(); it < outvec.end()-1; ++it)
        printf("%05d %d %05d\n",it->add, it->dat, it->nxt);
    printf("%05d %d -1\n",it->add, it->dat);
    return 0;
}
