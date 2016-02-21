#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,i,ans[32],sum;
    cin>>a>>b>>c;
    sum=a+b;
    if(!sum)
        cout<<'0'<<endl;
    for(i=0;sum>0;++i)
    {
        ans[i]=sum%c;
        sum/=c;
    }
    while(i)
    {
        cout<<ans[i-1];
        --i;
    }
    return 0;
}

