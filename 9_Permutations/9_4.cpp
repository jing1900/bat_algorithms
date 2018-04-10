/*
问题：n颗相同的糖果，分给m个人，每人至少一颗，问有多少种分法？
给定n，m，返回方案数，保证n<=12(是为了计算阶乘不溢出），且m<=n
如，现在有10颗糖，3个人。

解法：10颗糖中间有9个中间位置，现在我们只需要从中选出两个放隔板，分成的三部分刚好是每人至少一颗的分法，
此时，方法数有C（9,2） = 36种

拓展：10个不同的球放入3个不同的桶里有多少种方法？

解法：每个球都有3种选择，因此有3^10次方种选择

拓展2，有10颗糖，如果每天至少吃一颗，吃完为止，问有多少种不同的吃法？

解法：如果想一天吃完，只有1种吃法
如果两天，那么相当于9个间隔中放一个隔板，有c(9,1)种吃法
三天：c(9,2)

n天：c(9,n-1),n<=10

加起来就是c(9,0)+c(9,1)+..+c(9,9) = 2^9

这里有个很重要的公式

c(n,0)+c(n,1)+...+c(n,n) = (1+1)^n = 2^n; 二项式定理的内容。


*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long cald(int x)
    {
        if(x == 1)
            return 1;
        else
            return x*cald(x-1);
    }
    long long solution(int n,int m)
    {
        long long res;
        res = cald(n-1)/(cald(m-1)*cald(n-m));
        return res;
    }
};

int main()
{
    int n = 10;
    int m = 3;
    Solution s;
    cout<<s.solution(n,m)<<endl;
    return 0;
}