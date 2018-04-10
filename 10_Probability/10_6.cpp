/*问题：8只球队，有3个强队，其余都是弱队，随机把他们分成四组比赛
每组两个队，问两强相遇的概率。

首先计算8支球队组成4队的方法数：
首先任选一只队伍，有7种选择对手的方式，
再选一只队伍，有5种选择对手的方式
再选一只，有三种
最后一支，一种
共有7*5*3*1 = 105种

再计算没有两强相遇的概率：
从5支弱队选中三只与强者配对，剩下两只自行配对
c(5,3)*A(3,3) = 60 种
A(3,3)为三只强三只弱队彼此配对的方法数。

故两强相遇的概率为1- 60/105；

问题：有2k只球队，k-1个强队，其余都是弱队，随机把他们分成k组比赛，问两强相遇的概率。
给定一个数k，请返回一个数组，其中有两个元素，分别为最终分子分母，请化简成最简分数。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> calc(int k)//得到化简后的分子分母数组
    {
        vector<int> res;
        int up = 1;//这里初始化一定要为1，因为这里是累乘
        int down = 1;//分子分母，分别代表两强相遇的情况数，和所有组队情况数
        for(int i = 1;i<=k;i++)//组的第几队
        {
            down*=2*(k-i)+1;//根据上面找的规律公式
        }

        for(int i = k+1;i>0;i--)
        {
            up*=i;//根据上面分析找规律公式，用for循环计算出来即可
        }
        up = down - up/2;
        int comm = gcd(up,down);
        res.push_back(up/comm);
        res.push_back(down/comm);
        return res;
    }
    int gcd(int x,int y)//得到最大公约数
    {
        if(y==0)
            return x;
        else
        {
            return gcd(y,x%y);//这种情况，一旦找到最大公约数递归即可停止。
        }
    }
};
int main()
{
    int k = 4;
    Solution s;

    vector<int> res = s.calc(k);
    vector<int>::iterator iter;
    for(iter = res.begin();iter!=res.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    //cout<<s.gcd(3,21)<<endl;
    return 0;
}