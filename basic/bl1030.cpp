#include<iostream>
using namespace std;

int insertion(long long* a, long long p, int cur_low,int low, int high)
{
    int mid;
    mid = (low + high) / 2;
    if(low < high)
    {
        if(a[cur_low] * p < a[mid])
            return insertion(a, p, cur_low, low, mid);
        else
            if(a[cur_low] * p > a[mid])
                return insertion(a, p, cur_low, mid+1, high);
            else
                return mid-cur_low+1;
    }
    else
        if(a[cur_low] * p >= a[low])
            return low-cur_low+1;
        else
            return low-cur_low;
}

int main()
{
    void quicksort(long long *,int,int);
    int n,crt_max;
    long long p;
    crt_max=0;
    cin>>n>>p;
    long long *p_num=new long long[n];
    for(int i=0;i!=n;++i)
        cin>>p_num[i];
    quicksort(p_num,0,n-1);
    int i=0;
    while(crt_max+i <= n)
    {
        if(crt_max < insertion(p_num,p,i,i,n-1))
            crt_max=insertion(p_num,p,i,i,n-1);
        ++i;
    }
    if(crt_max==0)
        cout<<'1';
    else
        cout<<crt_max;
    delete [] p_num;
    return 0;
}

void quicksort(long long *v, int left, int right)
{
        if(left < right){
                long long key = v[left];
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
