/*
问题：在X*Y的方格中，以左上角格子为起点，右下角格子为终点，每次只能往下或往右走，请问
一共右多少种不同的走法？给定两个正整数int x，int y，返回走法数目，保证x+y <= 12

如：6*9的方格，每次都往下or往右走，一共有多少种走法？
首先，一共需要走5+8 = 13步，其中5步往下，8步往右(注意这里起点是在第一个格子里面）
答案是C(13,5) or C(13,8).

!!!此外，需注意的是，阶乘得到的结果很大，建议用longlong存

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long calc(int x)//计算x的阶乘
    {
        if(x == 1)
            return 1;
        else
            return x*calc(x-1);
    }
    long long solution(int x,int y)
    {
        long long res;
        res = calc(x+y-2)/(calc(x-1)*calc(y-1));
        return res;
    }
};
int main()
{
    int x = 6;
    int y = 9;
    Solution s;
    cout<<s.solution(x,y)<<endl;
    return 0;
}