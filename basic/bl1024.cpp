#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
    string sci,cmn,sci_pow;
    bool flag;
    cin>>sci;
    if(sci[0]=='-')
        cout<<sci[0];
    cmn+=sci[1];
    int E_pos=sci.find('E');
    for(int i=3;i!=E_pos;++i)
        cmn+=sci[i];
    if(sci[E_pos+1]=='+')
        flag=true;
    else
        flag=false;
    sci_pow=sci.substr(E_pos+2);
    int s_pow;
    char *end;
    s_pow=static_cast<int>(strtol(sci_pow.c_str(),&end,10));
    if(flag)                        //��������1ʱ
    {
        int res=s_pow-E_pos+3;      //Ҫ�����0����Ϊָ��-��Ч���λ��+1����λ��1λ��
        if(res>0)
        {
            cout<<cmn;
            string str_left(res,'0');   //str_left��str_head������ѭ�����ᳬʱ
            cout<<str_left;
        }
        else if(res<0)
        {
            cout<<cmn.substr(0,s_pow+1);
            cout<<'.';
            cout<<cmn.substr(s_pow+1);
        }
        else
        {
            cout<<cmn;
        }
    }
    else
    {
        cout<<"0.";
        string str_head(s_pow-1,'0');
        cout<<str_head;
        cout<<cmn;
    }
    cout<<endl;
    return 0;
}
