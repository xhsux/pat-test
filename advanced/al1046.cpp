#include <iostream>

using namespace std;

#define MAXN 100010
int node[MAXN] = {0};
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        node[i] = tmp + node[i - 1];
        //node[i] stores the distance from exit 1 to exit i + 1 node[i]: the perimeter of the circle
    }
    int sum = node[n];
    int m;
    cin >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            int c = b;
            b = a;
            a = c;
        }
        int diff = node[b - 1] - node[a - 1];
        int dis = diff < (sum - diff) ? diff : (sum - diff);
        cout << dis << endl;
    }
    return 0;
}