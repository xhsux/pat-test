#include<iostream>
using namespace std;
int main()
{
    string s1;
    int b,q,i,j,s2[1000];
    i=j=q=0;
    for(;j!=1000;++j)
        s2[j]=-1;
    cin>>s1>>b;
    while(s1[i])
    {
        s2[i]=(q*10+s1[i]-'0')/b;
        q=(q*10+s1[i]-'0')%b;
        ++i;
    }
    if(s2[0]==0&&s2[1]!=-1)
        j=1;
    else
        j=0;
    while(j!=i)
    {
        cout<<s2[j];
        ++j;
    }
    cout<<' '<<q<<endl;
    return 0;
}
