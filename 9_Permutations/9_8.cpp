/*问题：假设有n对括号，求出合法的排列有多少个？合法是指每个括号都能找到与之配对的括号，比如n=1时，（）是合法的，)(是不合法的
给定一个整数n，求返回所求的合法排列数。保证结果在int范围内。

解法：
首先，左括号数为n，右括号数为n，总的排列数为c（2n，n）。
而不合法的排列，一定是出现了右括号比左括号多一个 的前缀。如())... 或）...
这里我们将(记为1，)记为-1，
如果括号对数为3，
那么())(() 为1 -1 -1 1 1 -1，明显前三个这个前缀是不合法的。
我们将不合法的部分符号颠倒，变成-1 1 1 1 1 -1 ，如此得到n-1个-1和n+1个1组成的排列
可以证明，每个非法的排列通过如上的变换，都可以得到唯一一个n+1个左括号和n-1个右括号组成的排列。证明略
因此，我们可以这样说，有且只有n-1个右括号和n+1个左括号组成的排列是非法的。

因此，合法的对数等于c(2n,n)- c(2n,n+1) = 1/(n+1)*c(2n,n) 这个公式是由卡特兰数重要公式得到的。
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cald(int x)//计算x的阶乘
    {
        if(x == 1)
            return 1;
        else
            return x*cald(x-1);
    }

    int solution(int n)
    {
        int res = cald(2*n)/(cald(n)*cald(n));//尽量避免长计算。
        return res/(n+1);
    }
};

int main()
{
    int n = 1;
    Solution s;
    cout<<s.solution(n)<<endl;
    return 0;
}