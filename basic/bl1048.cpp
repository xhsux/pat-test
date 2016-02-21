#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char dig[14] = "0123456789JQK";
    string s1, s2, sans;
    cin >> s1 >> s2;
    size_t sz1 = s1.size(), sz2 = s2.size();
    int off1 = 0, off2 = 0;
    bool isodd = true;
    int i = sz1 - 1, j = sz2 - 1;
    for(; i >= 0 && j >= 0; --i, --j)
    {
        int a = s2[j] - '0', b = s1[i] - '0';
        int bit;
        if(isodd)
            bit = (a + b) % 13;
        else
        {
            bit = a - b;
            if(bit < 0)
                bit += 10;
        }
        isodd = !isodd;
        sans += dig[bit];
    }
    while(j >= 0)
    {
        sans += s2[j--];
    }
    while(i >= 0)
    {
        int a = 0, b = s1[i--] - '0';
        int bit;
        if(isodd)
            bit = (a + b) % 13;
        else
        {
            bit = a - b;
            if(bit < 0)
                bit += 10;
        }
        isodd = !isodd;
        sans += dig[bit];
    }
    reverse(sans.begin(), sans.end());
    cout << sans << endl;
    return 0;
}
