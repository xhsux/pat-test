#include<iostream>
#include<cstdio>
using namespace std;
void BiggerMinusSmaller(int &Exg_Gln, int &Exg_Skl, int &Exg_Knt, \
                       int BiggerGln, int BiggerSkl, int BiggerKnt, int SmallerGln, int SmallerSkl, int SmallerKnt)
{
        if(SmallerKnt > BiggerKnt)
        {
            Exg_Knt = BiggerKnt + 29 - SmallerKnt;
            BiggerSkl -= 1;
            if(SmallerSkl > BiggerSkl)
            {
                Exg_Skl = BiggerSkl + 17 - SmallerSkl;
                BiggerGln -= 1;
            }
            else
                Exg_Skl = BiggerSkl - SmallerSkl;
            Exg_Gln = BiggerGln - SmallerGln;
        }
        else
        {
            Exg_Knt = BiggerKnt - SmallerKnt;
            if(SmallerSkl > BiggerSkl)
            {
                Exg_Skl = BiggerSkl + 17 - SmallerSkl;
                BiggerGln -= 1;
            }
            else
                Exg_Skl = BiggerSkl - SmallerSkl;
            Exg_Gln = BiggerGln - SmallerGln;
        }
}

void CalcExg(int &Exg_Gln, int &Exg_Skl, int &Exg_Knt, int P_Gln, int P_Skl, int P_Knt, int A_Gln, int A_Skl, int A_Knt)
{
    bool isbigger = false;
    if(P_Gln < A_Gln)
       isbigger = true;
    else
    {
        if(P_Gln == A_Gln && (P_Skl * 29 + P_Knt <= A_Skl * 29 + A_Knt))
            isbigger = true;
    }
    if(isbigger)
        BiggerMinusSmaller(Exg_Gln, Exg_Skl, Exg_Knt, \
                           A_Gln, A_Skl, A_Knt, P_Gln, P_Skl, P_Knt);
    else{
        BiggerMinusSmaller(Exg_Gln, Exg_Skl, Exg_Knt, \
                           P_Gln, P_Skl, P_Knt, A_Gln, A_Skl, A_Knt);
        Exg_Gln = -Exg_Gln;
    }
}
int main()
{
    int P_Gln, P_Skl, P_Knt, A_Gln, A_Skl, A_Knt;
    scanf("%d.%d.%d %d.%d.%d", &P_Gln, &P_Skl, &P_Knt, &A_Gln, &A_Skl, &A_Knt);
    int Exg_Gln, Exg_Skl, Exg_Knt;
    CalcExg(Exg_Gln, Exg_Skl, Exg_Knt, P_Gln, P_Skl, P_Knt, A_Gln, A_Skl, A_Knt);
    printf("%d.%d.%d", Exg_Gln, Exg_Skl, Exg_Knt);
    return 0;
}
