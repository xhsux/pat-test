#include<iostream>
#include<stack>
#include<string>
#define MOD 1000000007
using namespace std;
int CalcAT(int &T_saved, int &A_saved, int cnt_tmp, int &T_tmp, int &A_tmp)
{
    cnt_tmp += T_saved + T_tmp;
    T_saved += T_tmp;
    A_saved += A_tmp;
    T_tmp = A_tmp = 0;
    cnt_tmp = cnt_tmp % MOD;
    return cnt_tmp;
}

int PATCNT(stack<char> stk)
{
    int cnt, cnt_tmp;
    cnt = cnt_tmp = 0;
    int T_saved, A_saved;
    int T_tmp, A_tmp;
    T_saved = A_saved = T_tmp = A_tmp = 0;
    while(!stk.empty())
    {
        switch(stk.top()){
                case 'T':
                    ++T_tmp;
                    stk.pop();
                    break;
                case 'A':
                    ++A_tmp;
                    cnt_tmp = CalcAT(T_saved, A_saved, cnt_tmp, T_tmp, A_tmp);
                    stk.pop();
                    break;
                case 'P':
                    cnt += cnt_tmp;
                    cnt = cnt % MOD;
                    stk.pop();
                    break;
        }
    }
    return cnt;
}
int main()
{
    string StrPAT;  // 其实可以不用考虑栈存储，直接顺序检测PAT，方法同上面的函数倒置。
    stack<char> pat_stk;
    cin >> StrPAT;
    string::iterator itr = StrPAT.begin();
    while(itr != StrPAT.end())
    {
        pat_stk.push(*itr);
        ++itr;
    }
    int cnt = PATCNT(pat_stk);
    cout << cnt << endl;
    return 0;
}
