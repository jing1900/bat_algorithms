/*问题：有n阶台阶，一个人每次往上走1or2阶，问有多少种走完的方法

思路，我们分析得知，走上第i阶台阶，只能有从第i-1处上一个台阶，or从i-2处上两个台阶。

因此有 f(i) = f(i-1)+f(i-2)

且易知，f1 = 1， f2 = 2;*/
#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;

//这里由于方法数很大，中间的结果也要mod
class Solution
{
public:
    int solution(int n)
    {
        int *dp = new int[n];
        dp[0]=1 ;//一阶台阶
        dp[1] =2; //2jie
        for(int i = 2;i<n;i++)
            dp[i] = (dp[i-1]+dp[i-1])%Mod;
        return dp[n-1];
    }
};
int main()
{
    int n = 100;//台阶数
    Solution s;
    long long  res = s.solution(n);//此外一定要注意对于结果数很大的情况，一定用longlong存贮
    cout<<res<<endl;
    return 0;
}
