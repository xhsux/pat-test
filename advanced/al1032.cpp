#include <iostream>
#include <iomanip>
#include <cstring>
#define MAXN 100010
int alpha[MAXN];
int visited[MAXN] = {0};
using namespace std;

int main()
{
    memset(alpha, -1, sizeof(alpha));
    int adda, addb, n;
    cin >> adda >> addb >> n;
    while(n--)
    {
        int cur, nxt;
        char c;
        cin >> cur >> c >> nxt;
        alpha[cur] = nxt;
    }
    while(adda != -1)
    {
        visited[adda] = 1;
        adda = alpha[adda];
    }
    while(addb != -1)
    {
        if(visited[addb])
        {
            cout << setw(5) << setfill('0') << addb << endl;        //fill with zero
            break;
        }
        else
            addb = alpha[addb];
    }
    if(addb == -1)
        cout << -1 << endl;
    return 0;
}
