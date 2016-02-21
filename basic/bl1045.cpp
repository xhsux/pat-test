#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int n, tmp, cnt = 0;
    vector<int> unsorted, sorted, pItem;
    cin >> n;
    while(n--)
    {
        cin >> tmp;
        unsorted.push_back(tmp);
        sorted.push_back(tmp);
    }
    sort(sorted.begin(), sorted.end());
    vector<int>::iterator u_it, s_it, p_it;
    int big = 0;
    for(u_it = unsorted.begin(), s_it = sorted.begin(); u_it != unsorted.end(); ++u_it, ++s_it)
    {
        if(*u_it > big)
            big = *u_it;
        if(*u_it == *s_it && *u_it == big)  //whether the current number is the biggest at present.
        {
            pItem.push_back(*u_it);
            cnt++;
        }
    }
    cout << cnt << endl;
    if(pItem.size())
    {
        p_it = pItem.begin();
        cout << *p_it;
        p_it++;
        for(; p_it != pItem.end(); ++p_it)
        {
            cout << ' ' << *p_it;
        }
    }
    cout << endl;   //line 2 need to have a new line no matter cnt = 0 or not.
    return 0;
}
