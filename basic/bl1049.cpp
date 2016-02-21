#include<cstdio>
#include<cstdlib>

int main()
{
    int n, i = 0, j = 0;
    scanf("%d", &n);
    double times = 0.0;
    double sum = 0.0;
    for(; i < n; ++i)
    {
        double tmp;
        scanf("%lf", &tmp);
        times = times - i + (n - i);
        sum = sum + tmp * times;
    }
    printf("%.2lf", sum);
    return 0;
}
