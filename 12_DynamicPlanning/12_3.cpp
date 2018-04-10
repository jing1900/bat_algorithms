/*
问题：最长递增子序列：给定数组arr，返回arr中最长递增子序列的长度，比如
2 1 5 3 6 4 8 9 7，最长递增子序列为1 3 4 8 9，故返回5
注意这里是子序列

解题思路：定义一个dp[n],其中dp[i]代表必须以arr[i]结尾的前提下，arr[0,...,i]中最大递增子序列长度
明显，dp[0] = 1;
其他情况，dp[i] = max(dp[j])+1,其中i>j>=0 && a[j]<a[i];
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(vector<int> arr,int n)
    {
        if(n <= 0)
            return 0;
        int *dp = new int[n];
        dp[0]= 1;
        int max_l = -1;//找最大的dp[i]
        for(int i = 1;i<n;i++)
        {
            int max_len= -1;//找j中最大的dp[j]
            for(int j = 0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    max_len = max(max_len,dp[j]);
                }

            }
            dp[i] = max_len+1;

            if(dp[i]>max_l)
                max_l = dp[i];

        }
        return max_l;
    }
};
int main()
{
    int n = 9;
    int a[n]={2, 1 ,5 ,3 ,6 ,4 ,8 ,9 ,7};
    vector<int> arr(a,a+n);
    Solution s;
    int res = s.solution(arr,n);
    cout<<res<<endl;
    return 0;
}