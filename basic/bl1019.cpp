#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    void quicksort(short *, int, int);
    int num,diff;
    diff=-1;
    short dgt[4];
    cin>>num;
    for(int i=0,tmp=num;i!=4;++i)
    {
        dgt[i]=tmp%10;
        tmp/=10;
    }
    if(!(num-(dgt[0]*1111)))
        cout<<num<<" - "<<num<<" = 0000"<<endl;
    while((num-(dgt[0]*1111))&&diff!=6174)
        {
            quicksort(dgt,0,4);
            diff=dgt[3]*1000+dgt[2]*100+dgt[1]*10+dgt[0]-(dgt[0]*1000+dgt[1]*100+dgt[2]*10+dgt[3]);
            cout<<dgt[3]<<dgt[2]<<dgt[1]<<dgt[0]<<" - "\
            <<dgt[0]<<dgt[1]<<dgt[2]<<dgt[3]<<" = "\
            <<setw(4)<<setfill('0')<<diff<<endl;
            for(int j=0,tmp=diff;j!=4;++j)
            {
                dgt[j]=tmp%10;
                tmp/=10;
            }
        }
    return 0;
}

void quicksort(short *v, int left, int right)
{
        if(left < right){
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && v[high] >= key){
                                high--;
                        }
                        v[low] = v[high];
                        while(low < high && v[low] < key){
                                low++;
                        }
                        v[high] = v[low];
                }
                v[low] = key;
                quicksort(v,left,low-1);
                quicksort(v,low+1,right);
        }
}
