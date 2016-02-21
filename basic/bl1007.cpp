#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int max,cnt=0;
    bool isprime(int);
    cin>>max;
    if(max<5)
        cout<<cnt<<endl;
    for(int i=3;i<=max;i+=2)
    {
        if(isprime(i))
            if(isprime(i+2)&&((i+2)<=max))
                ++cnt;
    }
    if(max>=5)
        cout<<cnt<<endl;
    return 0;
}

bool isprime(int a)
{
    for(int i=2;i<=(int)sqrt(a);++i)
    {
        if((a%i)==0)
            return false;
    }
    return true;
}
