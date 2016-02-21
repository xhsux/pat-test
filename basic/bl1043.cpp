#include<cstdio>

void PrintAns(int ans[])
{
    bool flag[6] = {false};
    bool allflag = false;
    for(int i = 0; !allflag && i != 6; ++i)
    {
        if(!flag[i] && ans[i])
        {
            switch(i)
            {
                case 0: printf("P"); break;
                case 1: printf("A"); break;
                case 2: printf("T"); break;
                case 3: printf("e"); break;
                case 4: printf("s"); break;
                case 5: printf("t"); break;
            }
            ans[i]--;
        }
        else
            flag[i] = true;
        if(flag[0] && flag[1] && flag[2] && \
           flag[3] && flag[4] && flag[5])
            allflag = true;
        if(!allflag && i == 5)
            i = -1;
    }
    printf("\n");
}

int main()
{
    int charcnt[6] = {0}, flag = 6;
    char c;
    while(scanf("%c", &c) != EOF)
    {
        switch(c)
        {
            case 'P': charcnt[0]++; break;
            case 'A': charcnt[1]++; break;
            case 'T': charcnt[2]++; break;
            case 'e': charcnt[3]++; break;
            case 's': charcnt[4]++; break;
            case 't': charcnt[5]++; break;
        }
    }
    PrintAns(charcnt);
    return 0;
}
