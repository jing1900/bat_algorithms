/*
有n个信封，包含n封信，现在把信拿出来，再装回去，要求每封信不能装回它原来的信封，
问多少种装法？

解法：
这道题我们可以利用递归的解法，n封信假设有f(n)种装法，这里我们只考虑n>2的情况
首先，假设第n封信放入了第i个信封，那么有两种情况，
1，第i封信也放入了信封n，那么剩下的就是一个n-2的装信封问题，后续为f(n-2)
2.第i封信没放入信封n，那么就是一个n-1封信，对应的不放入各自信封问题。后续为f(n-1)
然后i的选择有n-1种（除了位置n），因此，总数为(n-1)*(f(n-1)+f(n-2))
f1 = 0,f2 = 1,
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(int n)
    {
        if(n == 1 || n == 2)
            return n-1;
        else
        {
            return (n-1)*(solution(n-1)+solution(n-2));
        }
    }
};

int main()
{
    int n = 4;//此时应该=9
    Solution s;
    cout<<s.solution(n)<<endl;
    return 0;

}