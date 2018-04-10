/*
问题：给定一个整形数组arr，其中只有一个数出现了奇数次，其他的数都出现了偶数次，要求打印这个数
时间复杂度要求o(n)，空间o(1)

解法：
由于任何数与0亦或是其本身，
任何数和其本身亦或为0.
定义一个额外变量oe = 0，遍历数组，将其中每个数与oe亦或，最后oe的值即为哪个单独出现的数
这是因为亦或运算，满足交换律和结合律
如 arr = cbdaabc
由于交换律和结合率，oe按从左到右的顺序亦或arr和直接亦或aabbbccd是没有区别的
也就是说，最后剩下的那个，肯定是出现奇数次的

拓展，如何设置一种加密过程，完成对明文的加解密工作？
答:这里可以用亦或，比如明文为text,密码为pw，即可对两者按位亦或得到密文，解密时再亦或密码即可
如果明文长，密码短，对密码重复使用即可。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(vector<int> arr,int n)
    {
        int oe = 0;
        for(int i = 0;i<n;i++)
            oe^=arr[i];
        return oe;
    }
};

int main()
{
    int n = 7;
    int a[7] = {1,1,1,2,1,5,5};
    vector<int> arr(a,a+n);
    Solution s;
    cout<<s.solution(arr,n)<<endl;
    return 0;
}
