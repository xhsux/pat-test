#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
#define N 100010

struct STU{
    int No;
    int DScore;
    int CScore;
} stu[N];

bool isBigger(STU a, STU b)
{
    if((a.DScore + a.CScore) > (b.DScore + b.CScore))
        return true;
    else if((a.DScore + a.CScore) == (b.DScore + b.CScore))
         {
                if(a.DScore > b.DScore)
                    return true;
                else if(a.DScore == b.DScore)
                     return a.No < b.No;
                     else
                     return false;
         }
         else
            return false;
}

int whichClass(int Hi, int Lo, int DScore, int CScore) // CLASSIFY STUDENTS BY DScore and CScore
{
    int SumScore = DScore + CScore;
    if(DScore >= Hi)
    {
        if(CScore >= Hi)
            return 1;
        else if(CScore >= Lo)
                return 2;
             else
                return 0;
    }
    else if(DScore >= Lo)
    {
        if(CScore >= Lo)
        {
            if(DScore >= CScore)
                return 3;
            else
                return 4;
        }
        else
            return 0;
    }
        else
            return 0;
}

void output(vector<STU> STUClass)
{
    vector<STU>::iterator iter;
    for(iter = STUClass.begin(); iter != STUClass.end(); ++iter)
    {
        printf("%d %d %d\n", iter->No, iter->DScore, iter->CScore);
    }
}
int main()
{
    int n, Lo, Hi;
    cin >> n >> Lo >> Hi;
    vector<STU> AClass, BClass, CClass, DClass;
    for(int i = 0; i != n; ++i)
    {
        cin >> stu[i].No >> stu[i].DScore >> stu[i].CScore;
        switch(whichClass(Hi, Lo, stu[i].DScore, stu[i].CScore))
        {
            case 1:
                AClass.push_back(stu[i]);
                break;
            case 2:
                BClass.push_back(stu[i]);
                break;
            case 3:
                CClass.push_back(stu[i]);
                break;
            case 4:
                DClass.push_back(stu[i]);
                break;
            default:
                break;
        }
    }
    sort(AClass.begin(), AClass.end(), isBigger);
    sort(BClass.begin(), BClass.end(), isBigger);
    sort(CClass.begin(), CClass.end(), isBigger);
    sort(DClass.begin(), DClass.end(), isBigger);
    cout << AClass.size() + BClass.size() + CClass.size() + DClass.size() << endl;
    output(AClass);
    output(BClass);
    output(CClass);
    output(DClass);
    return 0;
}
