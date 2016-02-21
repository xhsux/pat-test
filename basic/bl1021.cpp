#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cnt[10],i;
    i=0;
    while(i-10)
    {
        cnt[i]=0;
        ++i;
    }
    i=0;
    char c[1000];
    while((c[i]=getchar())!='\n')
    {
        switch(c[i])
        {
            case '0':
                ++cnt[0];
                ++i;
                break;
            case '1':
                ++cnt[1];
                ++i;
                break;
            case '2':
                ++cnt[2];
                ++i;
                break;
            case '3':
                ++cnt[3];
                ++i;
                break;
            case '4':
                ++cnt[4];
                ++i;
                break;
            case '5':
                ++cnt[5];
                ++i;
                break;
            case '6':
                ++cnt[6];
                ++i;
                break;
            case '7':
                ++cnt[7];
                ++i;
                break;
            case '8':
                ++cnt[8];
                ++i;
                break;
            case '9':
                ++cnt[9];
                ++i;
                break;
        }
    }
    i=0;
    while(i-10)
    {
            if(cnt[i]!=0)
            cout<<i<<':'<<cnt[i]<<endl;
            ++i;
    }
    return 0;
}
