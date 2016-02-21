#include<iostream>
#include<algorithm>
#include<vector>
#define MAXNUM 100000
using namespace std;

int main()
{
    int num;
    int tmp;
    cin >> num;
    int score[101]={0};
    while(num--)
    {
        cin >> tmp;
        score[tmp]++;
    }
    int Knum;
    cin >> Knum;
    vector<int> Ansvec;
    Ansvec.reserve(MAXNUM);
    while(Knum--)
    {
        cin >> tmp;
        Ansvec.push_back(score[tmp]);
    }
    vector<int>::iterator itr = Ansvec.begin();
    cout << *itr;
    ++itr;
    for(; itr != Ansvec.end(); ++itr)
    {
        cout << ' ' << *itr;
    }
    return 0;
}
