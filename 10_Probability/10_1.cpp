/*
问题：三只蚂蚁从正三角形的三个顶点沿着边移动，速度是相同的，问它们碰头的概率多大
每只蚂蚁有两种选择，顺指针，逆时针。
因此，一共有2^3 = 8种，只有都顺or都逆才不会相遇

n只蚂蚁从正n边形的n个顶点沿着边移动，求碰头概率
给定一个整数n，返回一个数组，其中两个元素分别为分子，分母，请化为最简分数

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> calc(int n)
    {
        vector<int> res;
        int up = 0;
        int down = pow(2,n);//分子分母
        up = down - 2;
        int comm = gcd(up,down);
        res.push_back(up/comm);
        res.push_back(down/comm);
        return res;
    }
    int gcd(int x,int y)//计算最大公约数
    {
        if(y == 0)
            return x;
        else
        {
            return gcd(y,x%y);
        }
    }
};

int main()
{
    int n =3;
    Solution s;
    vector<int> res = s.calc(n);
    vector<int>::iterator iter;
    for(iter = res.begin();iter!=res.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}