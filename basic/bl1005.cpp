#include<iostream>
using namespace std;
void maxtomin(int*,int);
int main()
{
    int len,k;
    cin>>len;
    int *a=new int[len];
    k=0;
    for(int i=0;i!=len;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i!=len;++i)
    {
        k=a[i];
        while(k&&(k!=1))
        {
            if(!(k%2))
                k/=2;
            else
                k=(3*k+1)/2;
            for(int j=0;j!=len;++j)
                if(j!=i)
                    if(a[j]==k)
                        a[j]=0;
        }
    }
    maxtomin(a,len);
    int i=0;
    for(;i!=len&&(a[i+1]!=0);++i)
    {
        cout<<a[i]<<' ';
    }
        cout<<a[i]<<endl;
    return 0;
}

void maxtomin(int *a,int len)
{
    int temp;
    for(int i=0;i<len;++i)
        for(int j=i+1;j<len;++j)
            if(a[i]<=a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
}
