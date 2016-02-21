#include<cstdio>

int team[1010] = {0};
int main()
{
    int n;
    int mscore = 0, mteam = -1;
    scanf("%d", &n);
    while(n--)
    {
        int tmid, mbid, score;
        scanf("%d-%d %d", &tmid, &mbid, &score);
        team[tmid] += score;
        if(team[tmid] > mscore)
        {
            mteam = tmid;
            mscore = team[tmid];
        }
    }
    printf("%d %d", mteam, mscore);
    return 0;
}
