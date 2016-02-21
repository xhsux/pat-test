#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    int n, **p;
    cin >> n;
    vector<int> ivec;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        ivec.push_back(tmp);
    }
    sort(ivec.rbegin(), ivec.rend());
    int col, row, maxcol = 0, minrow = INT_MAX;
    for(col = 1; col * col <= n; ++col)
    {
        if(n % col == 0)
        {
            row = n / col;
            if(row < minrow)
            {
                maxcol = col;
                minrow = row;
            }
        }
    }
    p = new int*[minrow];
    for(int i = 0; i < minrow; ++i)
    {
        p[i] = new int[maxcol];
    }
    for(int i = 0; i < minrow; ++i)
        for(int j = 0; j < maxcol; ++j)
            p[i][j] = 0;
    int ix = 1;
    p[0][0] = ivec[0];
    int i = 0, j = 0;
    while(ix < n)
    {
        while(j + 1 < maxcol && !p[i][j + 1]) {p[i][j + 1] = ivec[ix]; ++j; ++ix;}
        while(i + 1 < minrow && !p[i + 1][j]) {p[i + 1][j] = ivec[ix]; ++i; ++ix;}
        while(j > 0 && !p[i][j - 1]) {p[i][j - 1] = ivec[ix]; --j; ++ix;}
        while(i > 0 && !p[i - 1][j]) {p[i - 1][j] = ivec[ix]; --i; ++ix;}
    }
    for(i = 0; i < minrow; ++i)
    {
        for(j = 0; j < maxcol; ++j)
        {
            cout << p[i][j];
            if(j == maxcol - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    for(i = 0; i < minrow; ++i)
        delete[] p[i];
    delete[] p;
    return 0;
}
