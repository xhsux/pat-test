#include<iostream>
#include<string>
using namespace std;
int main()
{
    int len,min,max,a,b;
    void ismin(int num, int *p,int *q,int i);
    void ismax(int num, int *p,int *q,int i);
    min=max=0;
    a=-1;
    b=101;
    cin>>len;
    string **psa;
    int *pia;
    psa=new string*[len]; //psa 是指向指向string指针的指针
    pia=new int[len];
    for(int i=0;i<len;++i)
        psa[i]=new string[2];
    for(int i=0;i<len;++i)
        for(int j=0;j<3;++j)
            {
                if(j!=2)
                    cin>>psa[i][j];
                else
                    cin>>pia[i];
            }
    for(int i=0;i<len;++i)
        {
            ismin(pia[i],&min,&b,i);
            ismax(pia[i],&max,&a,i);
        }
    cout<<psa[max][0]<<' '<<psa[max][1]<<endl;
    cout<<psa[min][0]<<' '<<psa[min][1]<<endl;
    for(int i=0;i<len;++i)
        {
            delete []psa[i];
        }
    delete []pia;
    delete []psa;
    return 0;
}

void ismin(int num, int *p,int *q,int i)
{
    if(num<*q)
        {
            *q=num;
            *p=i;
        }
}

void ismax(int num, int *p,int *q,int i)
{
    if(num>*q)
        {
            *q=num;
            *p=i;
        }
}

