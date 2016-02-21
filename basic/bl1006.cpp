#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int ipt,b,s,g;
    cin>>ipt;
    b=ipt/100;
    s=(ipt-b*100)/10;
    g=ipt%10;
    for(int i=0;i<b;++i)
    cout<<'B';
    for(int i=0;i<s;++i)
    cout<<'S';
    for(int i=0;i<g;++i)
    cout<<i+1;
    return 0;
}
