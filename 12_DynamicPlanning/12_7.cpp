/*
问题：给定两个字符串str1和str2，再给定三个整数ic，dc和rc，分别代表插入删除和替换一个字符的代价，返回将str1编辑成str2
的最小代价。
如：str1 = abc，str2 = adc，ic = 5，dc = 3，rc = 2，那么将b替换为d，代价是最小的，为2
再如：str1 = abc，str2=adc，ic = 5，dc = 3,rc =100,那么先删除b，再插入d的代价是最小的，为8
思路：
如果str1的长度为N，str2的长度为M，定义dp[N+1][M+1]
dp[i][j]为将str1[0,...,i-1]编辑成str2[0,...,j-1]的最小代价
自然的，dp[0][0] = 0;
然后第一列，代表将str1[0,...,i-1]编辑成空串的最小代价，自然为i*dc(0-i-1是i个字符）;即dp[i][0] = i*dc
然后第一行，代表将空串编辑乘str2[0,...,j-1](0-j-1,j个字符)的代价，自然为j*ic;
然后dp[i][j]有四种情况
1，将str1[0,i-1],删除一个字符(代价：dc)，变成str1[0,i-2],再将str1[0,i-2]编辑成str2[0,j-1](代价：dp[i-1][j]),
    此时 dp[i][j] = dc + dp[i-1][j];
2,将str1[0,i-1]编辑成str2[0,j-2](代价为dp[i][j-1]),再插入一个字符，将str2[0,j-2]变成str2[0,j-1]
    此时dp[i][j] = ir+dp[i][j-1];
3,如果str1[i-1]!=str2[j-1],那么，先将str1[0,i-2]编辑成str2[0,j-2],然后再替换i-1处的值
    此时dp[i][j] = rc+dp[i-1][j-1];
4,如果str1[i-1] = str2[j-1],那么，将str1[0,i-2]编辑成str2[0,j-2]即可
    此时dp[i][j] = dp[i-1][j-1];
然后，我们选择以上四种情况下最小的值，作为dp[i][j]的值
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //串1，串2,串1的长，串2的长，插入代价，替换代价，删除代价
    int solution(string str1,string str2,int n,int m,int ic,int rc,int dc)
    {
        int dp[n+1][m+1];
        dp[0][0] = 0;
        for(int i = 1;i<=n;i++)//处理第一列,将str1[0,i-1]删除成空串，即dc*i
            dp[i][0] = i*dc;
        //处理第一行，即将空串插入成str2[0,i-1],即ic*i
        for(int i = 1;i<=m;i++)
            dp[0][i]= i*ic;
        //处理其他情况，四种情况取最小值
        for(int i =1 ;i<=n;i++)
        {
            int res;
            for(int j = 1;j<=n;j++)
            {
                //先取ic+dp[i][j-1],(先将str1[0,i-1]编辑成str2[i-2],再插入)
                //和dc+dp[i-1][j]，（先将str1删除字符变成str1[0,i-2],再编辑成str2[0,j-1]的最小值
                int temp1 = min(ic+dp[i][j-1],dc+dp[i-1][j]);

                //再看str1[i-1]和str2[j-1]是否相等，再分别取最小值
                if(str1[i-1] == str2[j-1])
                    res = dp[i-1][j-1];
                else
                    res = dp[i-1][j-1]+rc;

                dp[i][j] = min(res,temp1);
            }

        }
        return dp[n][m];
    }
};

int main()
{
    string str1 = "abc";
    string str2 = "adc";
    int ic = 5;
    int dc = 3;
    int rc = 100;
    Solution s;
    int res = s.solution(str1,str2,3,3,ic,rc,dc);
    cout<<res<<endl;
    return 0;
}