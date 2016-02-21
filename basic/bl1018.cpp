#include<iostream>
#include<string>
using namespace std;
int main()
{
    int ismax(int,int,int);
    char a,b;
    int d[3],c,n,acnt[3],bcnt[3];
    c=0;
    for(int i=0;i!=3;++i)
    {
        d[i]=0;          //initialize d[i],cnt[i] to zero;
        acnt[i]=0;
        bcnt[i]=0;
    }
    cin>>n;
    while(c!=n)
    {
        cin>>a>>b;
        if((a=='J'&&b=='B')||(a=='B'&&b=='J'))
        {
            if(a>=b)
                if(a>b)
                    {
                        ++d[0];
                        switch(a)
                            {
                                case 'B':
                                    ++acnt[0];
                                    break;
                                case 'J':
                                    ++acnt[2];
                                    break;
                                default:
                                    break;
                            }
                    }
                else
                    ++d[1];
            else
                    {
                        ++d[2];
                        switch(b)
                            {
                                case 'B':
                                    ++bcnt[0];
                                    break;
                                case 'J':
                                    ++bcnt[2];
                                    break;
                                default:
                                    break;
                            }
                    }
            c=d[0]+d[1]+d[2];

        }
        else
        {
            if(a<=b)
                if(a<b)
                    {
                        ++d[0];
                        switch(a)
                            {
                                case 'B':
                                    ++acnt[0];
                                    break;
                                case 'C':
                                    ++acnt[1];
                                    break;
                                case 'J':
                                    ++acnt[2];
                                    break;
                                default:
                                    break;
                            }
                    }
                else
                    ++d[1];
            else
            {
                     ++d[2];
                     switch(b)
                            {
                                case 'B':
                                    ++bcnt[0];
                                    break;
                                case 'C':
                                    ++bcnt[1];
                                    break;
                                case 'J':
                                    ++bcnt[2];
                                    break;
                                default:
                                    break;
                            }
            }

            c=d[0]+d[1]+d[2];
        }
    }
    cout<<d[0]<<' '<<d[1]<<' '<<d[2]<<endl;
    cout<<d[2]<<' '<<d[1]<<' '<<d[0]<<endl;
    //cout<<acnt[0]<<' '<<acnt[1]<<' '<<acnt[2]<<endl;
    //cout<<bcnt[0]<<' '<<bcnt[1]<<' '<<bcnt[2]<<endl;
    switch(ismax(acnt[0],acnt[1],acnt[2]))
    {
       case 0:
        cout<<"B ";
        break;
       case 1:
        cout<<"C ";
        break;
       case 2:
        cout<<"J ";
        break;
    }
    switch(ismax(bcnt[0],bcnt[1],bcnt[2]))
    {
        case 0:
        cout<<'B';
        break;
       case 1:
        cout<<'C';
        break;
       case 2:
        cout<<'J';
        break;
    }
    return 0;
}

int ismax(int a,int b,int c)
{
    if(a>=b)
        if(b>=c)
            return 0;
        else
            if(a>=c)
                return 0;
            else
                return 2;
    else
        if(b>=c)
            return 1;
        else
            return 2;
}
