
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,s_rev[40];
    getline(cin,s);     //将整行输入传入string s；
    int i,j;
    i=j=0;
    while(s[i])
    {
        if(s[i]!=' ')
            s_rev[j]+=s[i];
        else
            ++j;
        ++i;
    }
    while(j)
    {
        cout<<s_rev[j]<<' ';
        --j;
    }
        cout<<s_rev[0]<<endl;
    return 0;
}

