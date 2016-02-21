#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 105

int N;

bool isEqual(int a[], int b[])
{
    for(int i = 0; i != N; ++i)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

bool isInsert(int a[], int b[])
{
    for(int i = 2; i != N; ++i)
    {
        sort(a, a + i);     //sort·¶Î§×ó±ÕÓÒ¿ª
        if(isEqual(a, b))
        {
            printf("Insertion Sort\n");
            sort(a, a + i + 1);
            return true;
        }
    }
    return false;
}

bool isMerge(int a[], int b[])
{
    int i;
    int j = 2;
    bool flag = false;
    while(j <= N)
    {
        for(i = 0; i < N - j + 1; i += j)
        {
            sort(a + i, a + i + j);
        }
            sort(a + i, a + N);
        if(flag)
        {
            printf("Merge Sort\n");
            return true;
        }
            if(isEqual(a, b))
            {
                flag = true;
            }
            j *= 2;
    }
    return false;
}

void print(int a[])
{
    for(int i = 0; i != N - 1; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[N-1]);
}

int main()
{

    cin >> N;
    int input[MAX], temp[MAX], output[MAX];
    int i = 0;
    while(i != N)
    {
        scanf("%d",&input[i++]);
    }
    i = 0;
    while(i != N)
    {
        temp[i] = input[i];
        scanf("%d",&output[i++]);
    }
    if(isInsert(input, output))
    {
        print(input);
    }
    if(isMerge(temp, output))
    {
        print(temp);
    }
    return 0;
}
