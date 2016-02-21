#include<iostream>
#include<string>
using namespace std;
int main()
{
    bool is_pass(string,int,int);
    int n;
    cin>>n;
    string *in_str=new string[n];
    bool *type=new bool[n];
    int *fore_acnt=new int[n];
    int *mid_acnt=new int[n];
    for(int i=0;i!=n;++i)
    {
         type[i]=1;
         fore_acnt[i]=0;
         mid_acnt[i]=0;
    }
    for(int i=0;i!=n;++i)
        cin>>in_str[i];     //read in_str[i] from istream;
    for(int i=0;i!=n;++i)
    {
        int step=0;    //判断现在读取位置，读到P为1，再读到A后为2，再读到T为3;
            for(int j=0;(j!=in_str[i].length())&&type[i];++j)
            {
                if(step==0) //step为0时候还没遇到P
                {
                    switch(in_str[i][j])
                    {
                        case 'A':
                            ++fore_acnt[i];
                            break;
                        case 'P':
                            step=1;
                            break;
                        default:
                            type[i]=0;
                            break;
                    }
                }
                else if(step<3) //step为1时候，将检测是否按顺序出现A...T
                {
                    switch(in_str[i][j])
                    {
                        case 'A':
                            ++mid_acnt[i];
                            if(step!=2)
                                step=2;
                            break;
                        case 'T':
                            if(step==2)
                                step=3;
                            else
                                type[i]=0;
                            break;
                        default:
                            type[i]=0;
                            break;
                    }
                }
            }
    }
    for(int i=0;i!=n;++i)
    {
        if(type[i])
            type[i]=is_pass(in_str[i],fore_acnt[i],mid_acnt[i]);
    }

    for(int i=0;i!=n;++i)
        {
            if(type[i])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    delete [] in_str;
    delete [] type;
    delete [] fore_acnt;
    delete [] mid_acnt;
}

bool is_pass(string str,int fore_cnt,int mid_cnt)
{
    string fore_str(fore_cnt,'A');
    string mid_str(mid_cnt,'A');
    string last_str(mid_cnt*fore_cnt,'A');
    string rl_str;
    rl_str=fore_str+'P'+mid_str+'T'+last_str;
    if(rl_str==str)
        return 1;
    else
        return 0;
}
