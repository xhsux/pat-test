#include<cstdio>

void PrinttheMost(int ans[])
{
    int big = 0, cur;
    for(int i = 0; i != 26; ++i)
    {
        if(ans[i] > big)
        {
            big = ans[i];
            cur = i;
        }
    }
    char c = cur + 'a';
    printf("%c %d\n", c, big);
}

int main()
{
    int stats[26] = {0};
    char c;
    while(scanf("%c", &c) != EOF)
    {
        if(c >= 'a' && c <= 'z')
            stats[c - 'a']++;
        if(c >= 'A' && c <= 'Z')
            stats[c - 'A']++;
    }
    PrinttheMost(stats);
    return 0;
}
