#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 100010
int coin[MAXN] = { 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i != n; ++i)
	{
		int tmp;
		cin >> tmp;
		coin[i] = tmp;
	}
	sort(coin, coin + n);
	int bg = 0, ed = n - 1;
	int v1, v2;
	v1 = v2 = 0;
	bool isok = false, toosmall = false;
	for (;; bg++)
	{
		if (coin[bg] >= m)
			break;
		for (;ed > bg; ed--)
		{
			if (coin[bg] + coin[ed] <= m)
			{
				if (coin[bg] + coin[ed] == m)
					isok = true;
				break;
			}
		}
		if (isok)
		{
			v1 = coin[bg];
			v2 = coin[ed];
			break;
		}
	}
	if (isok)
		cout << v1 << " " << v2 << endl;
	else
		cout << "No Solution" << endl;
	//system("pause");
	return 0;
}