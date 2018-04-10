/*问题：最长公共子序列
给定两个字符串str1，str2,返回两个字符串的最长公共子序列，
如，str1 = “1A2C3D4B56", str2 = "B1D23CA45B6A",最长公共子序列为123456or12C4B6,返回哪一个都行
解题思路：
如果str1长为n，str2长为m，那么定义一个dp[n+1][m+1]的数组
首先，第一行和第一列都初始化为0，然后dp[i][j]处代表的是str1[i-1],str2[j-1]处的最长公共子序列
dp[i][j]的值要怎么计算？
dp[i-1][j-1],if str1[i] = str2[j]
max(dp[i][j-1],dp[i-1,j]) ,if !=
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(string str1,string str2,int n,int m)
    {

        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)//初始化第一列
            dp[i][0] = 0;
        for(int i = 0; i<=m;i++)//初始化第一行
            dp[0][i] = 0;
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};

int main()
{
    string str1 = "1A2C3D4B56";
    string str2 = "B1D23CA45B6A";
    Solution s;
    int res = s.solution(str1,str2,str1.size(),str2.size());
    cout<<res<<endl;
    return 0;
}