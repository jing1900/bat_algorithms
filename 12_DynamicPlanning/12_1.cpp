/*
问题：0-1背包问题
一个背包有一定的承重M，有N件物品，每件都有自己的价值，记录在数组v中，也有自己的重量，记录在数组w中，每件物品可以选择
装入or不装入背包，在承重范围内，选出物品的总价值最大。

解题思路：
假设物品编号为1-n，一件件放入背包
dp[n][M+1];
第1列，表示重量上限为0，那么价值即dp[i][0] = 0;
第一行，重量上限>=w[0]的，价值dp[0][i] = v[0],其余也为0.
dp[x][y]表示前x件物品，不超过重量y的时候的最大价值
此时，如果放入了第x件物品，那么前x-1件物品的重量不大于y-w[x];
如果不选，那么前x-1件的物品重量可以达到y。
因此，
dp[x][y] = dp[x-1][y-w[x]] + v[x];//放入x
dp[x][y] = dp[x-1][y];//不放入x
选两者情况中dp最大的。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(int m,int n,vector<int> v,vector<int> w)//承重，物品数量，价值，物品重量
    {
        int dp[n][m+1];
        //初始化第一列，即重量为0，那么价值都为0
        for(int i = 0;i<n;i++)
            dp[i][0] = 0;
        //初始化第一行，重量上限 大于等于物品0的，价值为物品0的价值
        for(int i = 0;i<=m;i++)
        {
            if(i>=w[0])
            {
                dp[0][i] = v[0];
            }
            else
                dp[0][i]= 0;
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(j - w[i] >= 0)//当然，这里要判断下j的重量上限是否大于第i件物品的重量
                    dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);//放入第i件物品和不放第i件物品两种情况的最大值
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][m];
    }
};


int main()
{
    int m = 297;
    int n = 8;
    int w[n] = {42,25,30,35,42,21,26,28};
    int v[n]= {261,247,419,133,391,456,374,591};
    vector<int> w_arr(w,w+n);
    vector<int> v_arr(v,v+n);
    Solution s;
    int res = s.solution(m,n,v_arr,w_arr);
    cout<<res<<endl;
    return 0;
}
