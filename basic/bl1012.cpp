#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int b,len;
    int a1,a2,a5,flag,cnt[5];
    for(int i=0;i!=5;++i)
        cnt[i]=0;
    a1=a2=a5=flag=0;
    float a4;
    a4=0;
    cin>>len;
        while(len)
        {
            cin>>b;
            switch(b%5)
            {
            case 0:
                if(!(b%10))
                {
                   a1+=b;
                   ++cnt[0];
                }
                break;
            case 1:
                if(flag)
                {
                     a2-=b;
                     flag=0;
                }
                else
                {
                     a2+=b;
                     flag=1;
                }
                ++cnt[1];
                break;
            case 2:
                ++cnt[2];
                break;
            case 3:
                a4+=b;
                ++cnt[3];
                break;
            case 4:
                if(a5<b)
                    a5=b;
                ++cnt[4];
                break;
            }
        --len;
        }
    if(cnt[0]==0)
        cout<<'N';
    else
        cout<<a1;
    if(cnt[1]==0)
        cout<<" N";
    else
        cout<<' '<<a2;
    if(cnt[2]==0)
        cout<<" N";
    else
        cout<<' '<<cnt[2];
    if(cnt[3]==0)
        cout<<" N";
    else
    {
        a4/=cnt[3];
        cout<<' '<<fixed<<setprecision(1)<<a4;     //setprecision(n),控制总有效位数，用fixed以后n变为小数点后位数
    }
    if(cnt[4]==0)
        cout<<" N";
    else
        cout<<' '<<a5;
    return 0;
}
