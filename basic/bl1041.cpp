#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

typedef struct STU
{
    string ID;
    int test;
    int real;
};

class isSeat
{
    public:
        isSeat(int test_seat): cur_seat(test_seat) {}
        bool operator()(const vector<STU>::value_type &a)
        {
            return a.test == cur_seat;
        }
    private:
        int cur_seat;
};

int main()
{
    int cnt, check, test_seat;
    vector<STU> students;
    STU stu_tmp;
    cin >> cnt;
    while(cnt--)
    {
        cin >> stu_tmp.ID >> stu_tmp.test >> stu_tmp.real;
        students.push_back(stu_tmp);
    }
    cin >> check;
    vector<STU>::iterator it;
    while(check--)
    {
        cin >> test_seat;
        it = find_if(students.begin(), students.end(), isSeat(test_seat));
        cout << it->ID << ' ' << it->real << endl;
    }
    return 0;
}
