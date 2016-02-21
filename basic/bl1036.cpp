#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
    int num;
    char c;
    scanf("%d %c",&num,&c);
    for (int i = 0; i != num; ++i)
        printf("%c",c);
    printf("\n");
    int clm = (num + 1) / 2 - 2;
    for (int i = 0; i != clm; ++i)
    {
        printf("%c",c);
        for(int j = 0; j != num - 2; ++j)
            printf(" ");
        printf("%c\n",c);
    }
    for (int i = 0; i != num; ++i)
        printf("%c",c);
    printf("\n");
    return 0;
}
