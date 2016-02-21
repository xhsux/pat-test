#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
    string a,b,c,d;
    int i,day,hr,mn;
    i=day=hr=mn=0;
    cin>>a>>b>>c>>d;
    while(a[i]&&b[i])
    {
        if(a[i]==b[i])
            if((a[i]<='G')&&(a[i]>='A')) //一周只有7天，就A~G
                {
                    day=a[i]-'A'+1;
                    break;
                }
        ++i;
    }
    ++i;
    while(a[i]&&b[i])
    {
        if(a[i]==b[i])
            if((a[i]<='N')&&(a[i]>='A')) //0~9后还剩下14个数，只需A~N
                {
                    hr=a[i]-'A'+10;
                    break;
                }

            else
                if((a[i]<='9')&&(a[i]>='0'))
                {
                    hr=a[i]-'0';
                    break;
                }
        ++i;
    }
    i=0;
    while(c[i]&&d[i])
    {
         if(c[i]==d[i])
            if(((c[i]<='Z')&&(c[i]>='A'))||((c[i]<='z')&&(c[i]>='a')))
            {
                mn=i;
                break;
            }
        ++i;
    }
    switch(day)
    {
        case 1:
            cout<<"MON ";
            break;
        case 2:
            cout<<"TUE ";
            break;
        case 3:
            cout<<"WED ";
            break;
        case 4:
            cout<<"THU ";
            break;
        case 5:
            cout<<"FRI ";
            break;
        case 6:
            cout<<"SAT ";
            break;
        case 7:
            cout<<"SUN ";
            break;
    }
    cout<<setw(2)<<setfill('0')<<hr<<':';
    cout<<setw(2)<<setfill('0')<<mn<<endl;
    return 0;
}

