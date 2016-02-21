#include<iostream>
#include<cctype>
#include<bitset>
#define MAX_NUM 100000
using namespace std;

void removeupper(string text,bitset<MAX_NUM>& flag)
{
    unsigned int i=0;
    while(text[i])
    {
        if(text[i]<='Z' && text[i]>='A')
        {
            flag.set(i);
        }
        ++i;
    }
}

void removeletter(string text, char msk,bitset<MAX_NUM>& flag)
{
    unsigned int i=0;
    while(text[i])
    {
        if(msk == toupper(text[i]))
        {
            flag.set(i);
        }
        ++i;
    }
}

void removeothers(string text,char msk,bitset<MAX_NUM>& flag)
{
    unsigned int i=0;
    while(text[i])
    {
        if(msk == text[i])
        {
            flag.set(i);
        }
        ++i;
    }
}

int main()
{
    string msk,txt,outtxt;
    getline(cin,msk);
    cin>>txt;
    int n=txt.length();
    bitset<MAX_NUM> flag;
    int i=0;
    while(msk[i])
    {
        if(msk[i]=='+')
            removeupper(txt,flag);
        else
            if(msk[i]>='A' && msk[i]<='Z')
                removeletter(txt,msk[i],flag);
            else
                removeothers(txt,msk[i],flag);
        ++i;
    }
    if(flag.any())
    {
        for(int i=0;i!=n;++i)
        {
            if(!flag[i])
                cout<<txt[i];
        }
        cout<<endl;
    }
    else
        cout<<txt<<endl;
    return 0;
}
