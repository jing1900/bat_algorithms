/*
问题：给定一个整形数组arr，其中只有两个数出现了奇数次，其他的数都出现了偶数次，要求打印这个数
时间复杂度要求o(n)，空间o(1)

同8_4的思路，定义一个额外变量eo，假设出现奇数次的数为a，b。

最终eo的值为a^b.然后遍历eo的每一位，找到第一个为1的位，自然可知，a，b在此位上定有一个为1，一个为0
不妨假设a在此位为1
再定义一个eo‘的变量，其亦或arr中所有此位为1的数，从而得到的值定位a
然后eo^eo',得到的值即为b。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solution(vector<int> arr,int n)
    {
        vector<int> res;

        int eo = 0;//找到两个奇数的亦或和
        for(int i = 0;i<n;i++)
            eo ^= arr[i];

        int flag = 0;//找到eo里第一位不是0的位置
        int temp = eo;
        for(int i = 0;i<32;i++)
        {
            if(((temp>>i )& 1) == 1)
            {
                flag = i;
                break;
            }
        }

        int eo1 = 0;
        //oe1只亦或flag位为1的数组元素
        for(int i= 0;i<n;i++)
        {
            if(((arr[i]>>flag)&1) == 1)
            {
                eo1^=arr[i];
            }
        }
        eo = eo^eo1;
        res.push_back(eo<eo1?eo:eo1);//按从小到大的顺序放
        res.push_back(eo>eo1?eo:eo1);
        return res;
    }
};

int main()
{
    int n = 8;
    int a[n] ={1,5,5,5,2,2,4,4};
    vector<int> arr(a,a+n);
    Solution s;
    vector<int> res = s.solution(arr,n);

    vector<int>::iterator iter;
    for(iter = res.begin();iter!=res.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}