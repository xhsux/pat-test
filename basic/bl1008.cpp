#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int m,n,i;
    cin>>n>>m;
    i=0;
    int *a=new int[n];
    for(;i!=n;++i)
        cin>>a[i];
    m%=n;
    if(m==0)
    {
        cout<<a[0];
        for(i=1;i!=n;++i)
            cout<<' '<<a[i];
    }
    else
    {
        cout<<a[n-m];
        for(i=n-m+1;i!=n;++i)
            cout<<' '<<a[i];
        for(i=0;i!=n-m;++i)
            cout<<' '<<a[i];
    }
    cout<<endl;
    delete [] a;
    return 0;
}
