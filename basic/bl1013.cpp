#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    bool isprime(int);
    int m,n,i,prm[10000],row;
    cin>>m>>n;
    i=row=0;
    for(int j=2;i!=10000;++j)
            if(isprime(j))
                prm[i++]=j;
    for(int i=m-1;i!=n;++i)
    {
            if(row!=9&&i!=(n-1))        //�ڲ������һ�����Ҳ���ÿ�е�ʮ�����ʱҪ����ո�
            {
                cout<<prm[i]<<' ';
                ++row;
            }
            else
            {
                cout<<prm[i]<<endl;
                row=0;
            }
    }
    return 0;
}

bool isprime(int a)
{
    for(int i=2;i<=(int)sqrt(a);++i)
    {
        if((a%i)==0&&(a!=2))
            return false;
        if(a==2)
            return true;
    }
    return true;
}
