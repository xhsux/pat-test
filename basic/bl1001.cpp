#include<iostream>
using namespace std;
int main()
{
    int cnt,a;
    cnt=0;
    cin>>a;
    while(a!=1)
    {
        if(a%2==0)
        {
            a/=2;
            ++cnt;
        }
        else
        {
            a=(3*a+1)/2;
            ++cnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
