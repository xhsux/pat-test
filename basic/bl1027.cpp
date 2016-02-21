#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float num,sqnum,intsq;
    char c;
    cin>>num>>c;
    sqnum=sqrt((num+1)/2);
    intsq=floor(sqnum);         //intsq用于判断是否满足有多余字符无法输出
    if(intsq==sqnum)
    {
        for(int i=intsq;i!=0;--i)
        {
            for(int j=intsq-i;j!=0;--j)
            {
                cout<<' ';
            }
            for(int k=0;k!=2*i-1;++k)
                cout<<c;
            cout<<endl;
        }
        for(int i=2;i<=intsq;++i)   //i<=intsq判断是否存在多于一行的情况,再逆向输出
        {
            for(int j=intsq-i;j!=0;--j)
            {
                cout<<' ';
            }
            for(int k=0;k!=2*i-1;++k)
                cout<<c;
            cout<<endl;
        }
        cout<<num-intsq*intsq*2+1;
    }
    else
    {
        for(int i=intsq;i!=0;--i)
        {
            for(int j=intsq-i;j!=0;--j)
            {
                cout<<' ';
            }
            for(int k=0;k!=2*i-1;++k)
                cout<<c;
            cout<<endl;
        }
        for(int i=2;i<=intsq;++i)   //i<=intsq判断是否存在多于一行的情况,再逆向输出
        {
            for(int j=intsq-i;j!=0;--j)
            {
                cout<<' ';
            }
            for(int k=0;k!=2*i-1;++k)
                cout<<c;
            cout<<endl;
        }
        cout<<num-intsq*intsq*2+1;
    }
    return 0;
}
