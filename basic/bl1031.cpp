#include<iostream>
using namespace std;
bool is_valid(string id)
{
    int sum,i;
    sum=i=0;
    int wt[]={7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    string chk("10X98765432");
    while(id[i]>='0' && id[i]<='9' && i!=17)
    {
        sum+=(id[i]-'0')*wt[i];
        ++i;
    }
    if(i==17)
    {
        int z;
        z=sum%11;
        if(id[i] == chk[z])
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int num;
    bool flag=true;
    cin >> num;
    string *pid = new string [num];
    for(int i=0; i!=num; ++i)
    {
        cin>>pid[i];
    }
    for(int i=0; i!=num; ++i)
    {
        if(!(is_valid(pid[i])))
            {
                cout<<pid[i]<<endl;
                flag=false;
            }
    }
    if(flag)
        cout<<"All passed"<<endl;
    delete [] pid;
    return 0;
}
