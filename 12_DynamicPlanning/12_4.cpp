/*
问题：给定一个矩阵m，从左上角开始每次只能向右或往下走，最后到达右下角的位置，路径上的所有数字累加起来就是路径和，返回所有路径中最小的路径
和，如
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
路径1,3,1,0,6,1,0,是所有路径中最小的，所以返回12

思路：假如矩阵m的大小为M×N，那么生成一个一样大小的矩阵，dp[M][N],dp[i][j]的值表示从左上角0,0,走到i,j
位置的最小路径和（包含位置i，j）
首先dp矩阵的第一行，由于矩阵m每次只能往下or往右走，因此，第一行上dp值为m矩阵第一行不断累加的结果，同理
第一列上的也是。
而位置dp[i][j]处的值，一定是从dp[i-1][j]（上）,or dp[i][j-1]（左）处过来的，两者中的最小值，再加上m[i][j]此处的值。
即dp[i][j]= m[i][j]+min(dp[i-1][j],dp[i][j-1])*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(vector<vector<int> > map,int m,int n)//m行，n列
    {
        int dp[m][n];
        //初始化dp第一行第一列
        dp[0][0] = map[0][0];
        for(int i = 1;i<n;i++ )//第一行
            dp[0][i] = dp[0][i-1]+map[0][i];
        for(int i = 1;i<m;i++)//第一列
            dp[i][0] = dp[i-1][0]+map[i][0];
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                dp[i][j] = map[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    int m,n;
    cout<<"请输入矩阵行数："<<endl;
    cin>>m;
    cout<<"请输入矩阵列数："<<endl;
    cin>>n;
    vector<vector<int> > map;
    for(int i = 0;i<m;i++)
    {
        vector<int> v;
        int c;
        for(int i = 0;i<n;i++)
        {
            cin>>c;
            v.push_back(c);
        }
        map.push_back(v);
    }
    Solution s;
    long long res = s.solution(map,m,n);
    cout<<res<<endl;
    return 0;
}