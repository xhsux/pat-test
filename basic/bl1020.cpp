#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    double need;
    cin>>n>>need;
    double total_price,cur_min;
    total_price=cur_min=0;
    double *pdt=new double[n];
    double *price=new double[n];
    for(int i=0;i!=n;++i)
        cin>>pdt[i];
    for(int i=0;i!=n;++i)
        cin>>price[i];
    for(int i=0;i!=n;++i)
        for(int j=i+1;j!=n;++j)
            if((price[i]/pdt[i])<(price[j]/pdt[j]))
            {
                double tmp1;
                tmp1=price[i];
                price[i]=price[j];
                price[j]=tmp1;
                tmp1=pdt[i];
                pdt[i]=pdt[j];
                pdt[j]=tmp1;
            }
    for(int i=0;i!=n;++i)
    {
        if(pdt[i]>=need)
        {
            cout<<fixed<<setprecision(2)<<total_price+need/pdt[i]*price[i]<<endl;
            need=0;
            break;
        }
        else
        {
            total_price+=price[i];
            need-=pdt[i];
        }
    }
    if(need>0)
         cout<<fixed<<setprecision(2)<<total_price<<endl;
    delete [] pdt;
    delete [] price;
    return 0;
}

