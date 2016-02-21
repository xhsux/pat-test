#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a,b,hr,mn,sd;
    cin>>a>>b;
    double c;
    c=(b-a)/100.0;
    hr=c/3600;
    mn=(c-hr*3600)/60;
    sd=c-hr*3600-mn*60+0.5;
    cout<<setw(2)<<setfill('0')<<hr;
    cout<<':';
    cout<<setw(2)<<setfill('0')<<mn;
    cout<<':';
    cout<<setw(2)<<setfill('0')<<sd<<endl;
    return 0;
}
