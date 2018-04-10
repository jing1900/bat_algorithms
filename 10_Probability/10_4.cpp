/*
问题：假设函数f()等概率的返回一个在[0,1)之间的浮点数。那么我们知道，在[0,x)区间上的数出现的概率为x(0<x<=1).
给定一个大于0的整数k，并且可以使用f()函数，请实现一个函数依然返回在[0,1)范围的数，但在[0,x)区间上的数出现的概率为x的k次方。

先看如何得到x的二次方，很简单，调用两次f(),取较大的那个数，如果较大的落在【0，x）,那么较小的那个也肯定是。
同理，调用k次，取最大的数仍小于x即可。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double random_01()//等概率返回[0,1)上的浮点数，出现在[0,x)上的概率为x,注意这里返回的是都崩了类型
    {
        return rand() * (1.0 / RAND_MAX);
    }

    double rand_01(int k)//返回[0,1]上的浮点数，出现在[0,x]上的概率为x^k;
    {
        double res = -1;
        for(int i = 0;i<k;i++)
        {
            double d = random_01();
            res = max(res,d);

        }
        return res;
    }
};

int main()
{
    Solution s;
    for(int i = 0; i< 50;i++)
        cout<<s.rand_01(5)<<" ";
    cout<<endl;
    return 0;
}