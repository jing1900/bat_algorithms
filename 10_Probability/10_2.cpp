/*
给定一个以p概率生成0，以1-p概率生成1的随机函数f(),p是固定的值，但不知道多少。除此之外也不能使用额外的随机机制，请用f()实现等概率随机
生成0和1的随机函数

思路：连续调用两次f(),则10 和01的概率都为p(1-p),即去除00 和11 ，即为等概率的了。
连续调用，如果产生00,11序列，则继续调用，直到产生10 or 01为止，即，将00,11的概率分摊到10 01 上了
然后最终的结果如果是01，则返回0，如果是10，则返回1.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int random_p()//以p的概率生成0,1-p的概率生成1
    {
        int r = rand()%10+1;//产生1-10的随机数
        if(r>6)
            return 1;//1的概率2/5
        else
            return 0;//0的概率3/5
    }

    int random_01()//用random_p()函数生成等概率生成0,1的随机函数
    {
        while(1)
        {
            int a = random_p();
            int b = random_p();//连续调用两次
            if(a!=b)//01 or 10的情况
            {
                return a>b?0:1;//分别返回0,1；终止while，否则相等，则继续产生，直到产生01，or10.
            }
        }

    }
};
int main()
{
    Solution s;
    for(int i = 0; i< 50;i++)
        cout<<s.random_01()<<" ";
    cout<<endl;
    return 0;
}