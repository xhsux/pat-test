#include<iostream>
using namespace std;
int main()
{
    int a[10],i,flag;
    i=0;
    flag=1;
    while(i-10)
    {
        a[i]=0;
        ++i;
    }
    i=0;    //reset i to 0;
    while(i-10)
    {
        cin>>a[i];
        ++i;
    }
    i=0;
    if(a[i]==0)
        for(i=1;i!=10;++i)
            while(a[i])
            {
                cout<<i;
                --a[i];
            }
    else
    {
         for(i=1;i!=10&&flag;++i)
            while(a[i]&&flag)     //先找到0之后出现的最小数字
            {
                cout<<i;    //将该数字输出一个，并将a[i]-1
                --a[i];
                flag=0;
            }
        for(i=0;i!=10;++i)
            while(a[i])
            {
                cout<<i;
                --a[i];
            }
    }
    return 0;
}
