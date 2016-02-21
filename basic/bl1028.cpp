#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define MAX 100001
int main()
{
    bool is_real(int,int,int);
    int is_max(int *,int *,int *,int ,int);
    int is_min(int *,int *,int *,int ,int);
    char stu[MAX][6];       //最多应该是读6个字符，c字符串有结束符\'0'勿忘
    int num,yr[MAX],mth[MAX],dy[MAX],cnt,old,yng;
    bool rl[MAX];
    old=yng=0;
    cnt=0;
    scanf("%d",&num);
    for(int i=0;i!=num;++i)
        rl[i]=false;
    for(int i=0;i!=num;++i)
    {
        scanf("%s %d/%d/%d",stu[i],&yr[i],&mth[i],&dy[i]);
    }
    for(int i=0;i!=num;++i)
    {
        rl[i]=is_real(yr[i],mth[i],dy[i]);
        if(rl[i])
        {
            ++cnt;
            old=is_max(yr,mth,dy,i,old);
            yng=is_min(yr,mth,dy,i,yng);
        }
    }
    if(cnt>0)
        printf("%d %s %s",cnt,stu[old],stu[yng]);
    else
        printf("0");
    return 0;
}

bool is_real(int yr,int mth,int dy)
{
    if(yr>1814&&yr<2014)
        return true;
    else
    {
        switch(yr)
        {
            case 1814:
                if(mth>9)
                    return true;
                else
                    if(mth==9)
                        if(dy>=6)
                            return true;
                        else
                            return false;
                    else
                        return false;
                break;
            case 2014:
                if(mth<9)
                    return true;
                else
                    if(mth==9)
                        if(dy<=6)
                            return true;
                        else
                            return false;
                    else
                        return false;
                break;
            default:
                return false;
                break;
        }
    }
}

int is_max(int *yr,int *mth,int *dy,int crt_ix,int old_ix)
{
    if(is_real(yr[old_ix],mth[old_ix],dy[old_ix]))
    {
        if(yr[crt_ix]<yr[old_ix])
            return crt_ix;
        else
            if(yr[crt_ix]==yr[old_ix])
            {
                if(mth[crt_ix]<mth[old_ix])
                    return crt_ix;
                else
                {
                    if(mth[crt_ix]==mth[old_ix])
                    {
                        if(dy[crt_ix]<dy[old_ix])
                            return crt_ix;
                        else
                            return old_ix;
                    }
                    else
                        return old_ix;
                }
            }
            else
                return old_ix;
    }
    else
        return crt_ix;
}

int is_min(int *yr,int *mth,int *dy,int crt_ix,int yng_ix)
{
    if(is_real(yr[yng_ix],mth[yng_ix],dy[yng_ix]))
    {
        if(yr[crt_ix]>yr[yng_ix])
            return crt_ix;
        else
            if(yr[crt_ix]==yr[yng_ix])
            {
                if(mth[crt_ix]>mth[yng_ix])
                    return crt_ix;
                else
                {
                    if(mth[crt_ix]==mth[yng_ix])
                    {
                        if(dy[crt_ix]>dy[yng_ix])
                            return crt_ix;
                        else
                            return yng_ix;
                    }
                    else
                        return yng_ix;
                }
            }
            else
                return yng_ix;
    }
    else
        return crt_ix;
}

