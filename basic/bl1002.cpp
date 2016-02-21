#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int sum,i,a[4],t;
    sum=0;
    i=3;
    char c;
    string s[4];
    while((c=getchar())!='\n')
        sum+=c-'0';
    t=sum;
    a[3]=sum%10;
    sum/=10;
    a[2]=sum%10;
    sum/=10;
    a[1]=sum%10;
    a[0]=sum/10;
    while(i+1)
    {
        switch(a[i])
        {
            case 0:
                s[i]="ling";
                --i;
                break;
            case 1:
                s[i]="yi";
                --i;
                break;
            case 2:
                s[i]="er";
                --i;
                break;
            case 3:
                s[i]="san";
                --i;
                break;
            case 4:
                s[i]="si";
                --i;
                break;
            case 5:
                s[i]="wu";
                --i;
                break;
            case 6:
                s[i]="liu";
                --i;
                break;
            case 7:
                s[i]="qi";
                --i;
                break;
            case 8:
                s[i]="ba";
                --i;
                break;
            case 9:
                s[i]="jiu";
                --i;
                break;

        }
    }
    while(t/1000)
    {
        cout<<s[0]<<' '<<s[1]<<' '<<s[2]<<' '<<s[3]<<endl;
        break;
    }
    while((t<1000)&&(t/100))
    {
        cout<<s[1]<<' '<<s[2]<<' '<<s[3]<<endl;
        break;
    }
    while((t<100)&&(t/10))
    {
        cout<<s[2]<<' '<<s[3]<<endl;
        break;
    }
    while((t<10)&&(t>0))
    {
        cout<<s[3]<<endl;
        break;
    }
    return 0;
}
