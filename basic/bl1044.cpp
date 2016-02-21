#include<cstdio>
#include<cstring>

int main()
{
    char highdigit[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", \
                             "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    char lowdigit[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", \
                            "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    int n;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        char inpt[10];
        gets(inpt);
        if(inpt[0] >= '0' && inpt[0] <= '9')
        {
            int sum = 0;
            for(int i = 0; inpt[i] != '\0'; ++i)
                sum = sum * 10 + (inpt[i] - '0');
            if(sum / 13)
            {
                if(sum % 13)
                {
                    printf("%s ", highdigit[sum / 13]);
                    printf("%s\n", lowdigit[sum % 13]);
                }
                else
                    printf("%s\n", highdigit[sum / 13]);
            }
            else
                printf("%s\n", lowdigit[sum % 13]);
        }
        else
        {
            int sum = 0;
            for(int i = 0; i != 13; ++i)
                if(strstr(inpt, highdigit[i])){
                    sum += 13 * i;
                    break;
                }
            for(int i = 0; i != 13; ++i)
                if(strstr(inpt, lowdigit[i])){
                    sum += i;
                    break;
                }
            printf("%d\n", sum);
        }
    }
    return 0;
}
