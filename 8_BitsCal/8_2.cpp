/*
如何不用任何额外的变量，交换两个整数的值
a = a^b;
b = a^b;//a^b^b = a
a = a^b;//a^b^a = b
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solution(int &x,int &y)
    {
        x = x^y;
        y = x^y;
        x = x^y;
    }
};

int main()
{
    int x = 1;
    int y = 2;
    Solution s;
    s.solution(x,y);
    cout<<x<<" "<<y<<endl;
    return 0;
}