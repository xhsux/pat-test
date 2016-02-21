#include<iostream>

using namespace std;
void BeadsCount(int cnt[], char c)
{
        if(c >= '0' && c <= '9')
            cnt[c - '0']++;
        else
        {
            if(c >= 'A' && c <= 'Z')
                cnt[c - 'A' + 10]++;
            else
                cnt[c - 'a' + 36]++;
        }
}

void CalcisEnough(int sold[], int need[], int &rmd, bool &enaf)
{
    int sold_cnt, need_cnt;
    sold_cnt = need_cnt = 0;
    int tmp;
    for(int i = 0; i != 62; ++i)
    {
        tmp = sold[i] - need[i];
        sold_cnt += sold[i];
        need_cnt += need[i];
        if(tmp < 0)
        {
            enaf = false;
            rmd -= tmp;
        }
    }
    if(enaf)
        rmd = sold_cnt - need_cnt;
}
int main()
{
    string Sold, Need;
    cin >> Sold >> Need;
    string::size_type ix = 0;
    int Sold_cnt[62] = {0};
    int Need_cnt[62] = {0};
    char tmp;
    while(Sold[ix])
    {
        BeadsCount(Sold_cnt, Sold[ix]);
        ix++;
    }
    ix = 0;
    while(Need[ix])
    {
        BeadsCount(Need_cnt, Need[ix]);
        ix++;
    }
    bool isEnough = true;
    int rmd = 0;
    CalcisEnough(Sold_cnt, Need_cnt, rmd, isEnough);
    if(isEnough)
        cout << "Yes " << rmd << endl;
    else
        cout << "No " << rmd << endl;
    return 0;
}
