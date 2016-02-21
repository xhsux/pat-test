#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
    string rl,bk,outstr;
    cin>>rl>>bk;
    int i,j;
    i=j=0;
    while(rl[i])
    {
        while(rl[i]!=bk[j])
            {
                outstr+=toupper(rl[i]);
                ++i;
            }
                ++i;
                ++j;
    }
    i=0;
    j=1;
    while(outstr[i])
    {
        while(outstr[j])
        {
            if(outstr[i]==outstr[j])
            {
                if(j!=(outstr.length()-1))
                    outstr=outstr.substr(0,j)+outstr.substr(j+1);
                else
                    outstr=outstr.substr(0,j);
                --j;
            }
            ++j;
        }
        ++i;
        j=i+1;
    }
    cout<<outstr<<endl;
    return 0;
}
