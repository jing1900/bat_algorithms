/*问题：给定数组arr，其中所有的值都为正数且不重复，每个值代表一种货币，每种面值的货币可以使用任意张，再
给定一个整数aim代表要找的钱数，其换钱有多少种方法。

Arr = {5,10,25,1},aim = 1000

暴力枚举:49959s,142511
记忆搜索:269s,142511
动态规划:34s,142511,时间复杂度为n×aim^2，化简后，即将1-n张arr[i]的情况，合起来，合为dp[i]dp[j-arr[i]);
此时时间复杂度为N*aim

*/
#include<bits/stdc++.h>
using namespace std;
/*方法1：暴力搜索方法
1,用0张5元的货币，让{10,25,1}组成剩下的1000，此时所有的方法数记为res1；
2，用1张5元的货币，让{10，25,1}组成剩下的950，此时所有的的方法数记为res2；
3，..用200张5元的货币，让{10，25,1}组成剩下的0，此时方法数记为res201，

在计算每种方法数时，需要对{10,25,1}这个序列进行递归。

分析上面的递归过程，我们定义int p1（arr，index，aim）函数，它的含义是如果用arr[index,…N-1)的面值
的前组成aim，返回总的方法数。

存在的问题：有很多重复计算的情况
*/
class BaoliExchange{
public:
    int baoli(vector<int> arr,int n,int aim)
    {
        if(n == 0|| aim<0)
            return 0;
        return propress(arr, 0, aim);
    }

    int propress(vector<int> arr,int index,int aim)
    {
        int res;
        if(index == arr.size()-1)
        {
            res = (aim%arr[index])?0:1;///现在是到了最后一种货币，如果剩下的aim不能整除该货币，则返回0种方法
            return res;
        }
        else
        {
            res = 0;//计算每一种货币的累加情况，然后将每一种货币的返回值res累加
            for(int i = 0; arr[index]*i <= aim;i++)
                res+=propress(arr,index+1,aim-i*arr[index]);
        }
        return res;
    }
};

/*方法2，记忆搜索方法，我们注意到上面的方法中，arr是一直没变的，因此我们可以将递归函数
该为p1(int index,int aim).并记录下每次计算的结果，从而避免了大量的重复计算。

即构建一个表map，每计算完一个p（index，aim），都将结果放入map，idex和aim组成共同的key
然后每次递归过程前，先在map中查找是否计算过，否则再递归
*/

class RemerberExchange
{
public:
	int remerberfind(vector<int> arr,int n,int aim)
	{
	    if(n == 0 || aim<0)
	        return 0;
	    //定义二维动态数组
	    int **map = new int*[n];
	    for(int i = 0; i<n;i++)
	        map[i] = new int[aim+1];
	    //并初始化
	    for(int i = 0;i<n;i++ )
	        for(int j = 0; j< aim+1;j++)
	            map[i][j] = -1;
	    int res =  propress(arr,0,aim,map);
	    //释放内存，需多次析构
	    for(int i = 0;i<n;i++)
	        delete []map[i];
	    delete []map;
	    return res;

	}

	int propress(vector<int> arr,int index,int aim,int **map)
	{
	    int res;
	    if(index == arr.size()-1)
	    {
	        if(map[index][aim] ==-1)
	            map[index][aim] = (aim % arr[index])?0:1;
	        return map[index][aim];
	    }
	    else
	    {
	        res = 0;
	        for(int i = 0; arr[index]*i<=aim;i++ )
	        {
	            //存贮index+1，aim-i*arr[index]处的计算值。
	            if(map[index+1][aim-i*arr[index]] == -1)
	                map[index+1][aim-i*arr[index]] = propress(arr,index+1,aim-i*arr[index],map);
	            res+=map[index+1][aim-i*arr[index]];
	        }
	    }
	    return res;
	}
};
/*动态规划
生成dp[n][aim+1]矩阵，其中dp[i][j]表示在使用arr[0,i]货币的情况下，组成钱数j有多少种方法
首先初始化，第一列，第一列是指j为0的情况，即组成钱数为0的情况，明显只有一种方法，即不使用任何货币
然后初始化第一行，第一行中，只有aim值为arr[0]= 5的整数倍的地方才能被组成，因此只有这些位置的方法为1，其他为0.
那么dp[i][j]的值如何求呢
1，当完全不用arr[i]货币，只用arr[0,...,i-1]时，方法数为+dp[i-1][j];
2,如果用1张，那么方法数为+dp[i-1][j-1*arr[i]]

3,如果用n张，那么方法数为+dp[i-1][j-n*arr[i]]

用1-n张arr[i]的情况，合起来，即dp[i]dp[j-arr[i]);
*/
class DynamicExchange
{
public:
    int DynamicFind(vector<int> arr,int n,int aim)
    {
        if(n == 0 || aim<0)
            return 0;
        int dp[n][aim+1];
        for(int i = 0; i<n;i++)//初始化第一列
            dp[i][0] = 1;
        for(int i = 0;i<aim+1;i++)//初始化第一行
        {
            if(i % arr[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<aim+1;j++)
            {
                if(j-arr[i]<0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-arr[i]]+dp[i-1][j];
            }
        }
        return dp[n-1][aim];
    }

};


int main()
{
    int n = 4;
	int a[n] = {5,10,25,1};
	vector<int> arr(a,a+n);
	int aim = 1000;

	BaoliExchange b;
	clock_t starttime = clock();
	int num = b.baoli(arr,n,aim);
	clock_t endtime = clock();
	cout<<"暴力枚举:"<<endtime-starttime<<"s,"<<num<<endl;

	RemerberExchange r;
	starttime = clock();
	num = r.remerberfind(arr,n,aim);
	endtime = clock();
	cout<<"记忆搜索:"<<endtime-starttime<<"s,"<<num<<endl;

	DynamicExchange d;
	starttime = clock();
	num = d.DynamicFind(arr,n,aim);
	endtime = clock();
	cout<<"动态规划:"<<endtime-starttime<<"s,"<<num<<endl;


	return 0;
}
