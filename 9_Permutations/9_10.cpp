/*
问题：n个人站队，他们编号从1到n，要求编号为a的人必须在编号为b的人左边，但不要求相邻，请问一共有多少种排法？
第二问：如果要求a必须在b的左边，且相邻，请问一共有多少种排法？
给定人数n和两个人的编号a，b，请返回一个两个元素的数组，其中两个元素依次为两个问题的答案，保证人数小于等于10.

首先问题1，n个人排队，一定有n！种站法，其中一半情况是A在B左边，另一半情况是B在A左边，因此，有n！/2种排法
第二问也很简单，A在B左边，可以将两者看做一个人，那么就是n-1个人的全排列。为（n-1）！


*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long cald(int x)//计算x的阶乘,虽说n<=10,但以防万一，还是用longlong存
    {
        if(x == 1)
            return 1;
        else
            return x*cald(x-1);
    }
    vector<long long> solution(int n,int a,int b)
    {
        long long res1 = cald(n)/2;
        long long res2 = cald(n-1);
        vector<long long> res;
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};
int main()
{
    int n = 7;
    int a = 1;
    int b = 2;
    Solution s;
    vector<long long> res = s.solution(n,a,b);
    vector<long long>::iterator iter;
    for(iter = res.begin();iter!= res.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}