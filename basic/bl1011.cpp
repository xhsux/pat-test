#include<iostream>
using namespace std;
int main()
{
    int len,c[10];
    long a[10],b[10];
    cin>>len;
    for(int i=0;i<len;++i)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<len;++i)
    {
        if(a[i]+b[i]>c[i])
            cout<<"Case #"<<i+1<<": true"<<endl;
        else
            cout<<"Case #"<<i+1<<": false"<<endl;
    }

    return 0;
}
