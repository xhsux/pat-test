#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float num,sqnum,intsq;
    char c;
    cin>>num>>c;
    sqnum=sqrt((num+1)/2);
    intsq=floor(sqnum);         //intsq�����ж��Ƿ������ж����ַ��޷����
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
        for(int i=2;i<=intsq;++i)   //i<=intsq�ж��Ƿ���ڶ���һ�е����,���������
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
        for(int i=2;i<=intsq;++i)   //i<=intsq�ж��Ƿ���ڶ���һ�е����,���������
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
