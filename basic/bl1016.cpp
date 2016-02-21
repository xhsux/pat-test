#include<iostream>
using namespace std;
int main()
{
    string a,b;
    char da,db;
    int i,cnt[2];
    long ansa,ansb;
    i=cnt[0]=cnt[1]=0;
    cin>>a>>da>>b>>db;
    while(a[i])
    {
        if(a[i]==da)
            ++cnt[0];
        ++i;
    }
    i=0;
    while(b[i])
    {
        if(b[i]==db)
            ++cnt[1];
        ++i;
    }
    switch(cnt[0])
    {
        case 0:
            ansa=0;
            break;
        case 1:
            ansa=da-'0';
            break;
        case 2:
            ansa=(da-'0')*11;
            break;
        case 3:
            ansa=(da-'0')*111;
            break;
        case 4:
            ansa=(da-'0')*1111;
            break;
        case 5:
            ansa=(da-'0')*11111;
            break;
        case 6:
            ansa=(da-'0')*111111;
            break;
        case 7:
            ansa=(da-'0')*1111111;
            break;
        case 8:
            ansa=(da-'0')*11111111;
            break;
        case 9:
            ansa=(da-'0')*111111111;
            break;
    }
    switch(cnt[1])
    {
        case 0:
            ansb=0;
            break;
        case 1:
            ansb=db-'0';
            break;
        case 2:
            ansb=(db-'0')*11;
            break;
        case 3:
            ansb=(db-'0')*111;
            break;
        case 4:
            ansb=(db-'0')*1111;
            break;
        case 5:
            ansb=(db-'0')*11111;
            break;
        case 6:
            ansb=(db-'0')*111111;
            break;
        case 7:
            ansb=(db-'0')*1111111;
            break;
        case 8:
            ansb=(db-'0')*11111111;
            break;
        case 9:
            ansb=(db-'0')*111111111;
            break;
    }
    cout<<ansa+ansb<<endl;
    return 0;
}

