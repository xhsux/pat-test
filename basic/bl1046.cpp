#include<iostream>
using namespace std;

int main()
{
    int numa, numb, a, b, rounds;
    cin >> rounds;
    int wina = 0, winb = 0;
    while(rounds--)
    {
        cin >> numa >> a >> numb >> b;
        int sum = numa + numb;
        if(sum == a && sum != b)
            wina++;
        if(sum != a && sum == b)
            winb++;
    }
    cout << winb << " " << wina << endl;
    return 0;
}
