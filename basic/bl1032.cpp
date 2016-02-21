#include<iostream>
#include<bitset>
#define MAX_NUM 100001
using namespace std;

void cmp(int score,int school,int& hscore,int& hschool)
{
    if(score>hscore)
    {
        hscore=score;
        hschool=school;
    }
}

int main()
{
    int num,school,score;
    int scr[MAX_NUM]={0};
    cin>>num;
    bitset<MAX_NUM> msk;
    while(num)
    {
        cin>>school>>score;
        msk.set(school);
        scr[school]+=score;
        --num;
    }
    int REAL_NUM=msk.count();
    int maxscr_num,maxscr;
    maxscr_num=1;
    maxscr=scr[1];
    for(int i=2;i!=REAL_NUM+1;++i)
        cmp(scr[i],i,maxscr,maxscr_num);
    cout<<maxscr_num<<' '<<maxscr<<endl;
    return 0;
}
