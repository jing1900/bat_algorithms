/*
		问题：
			如何更快的求一个整数k的N次方，如果两个整数相乘并得到结果的时间复杂度为O(1),得到整数k的N次方的过程请事先时间复杂度为O（logN）的方法。
		解题思路：
			1，普通的做法将k相乘N次，这种方法的时间复杂度是O（n）。
			2，最优解，假设做10^75,
			3，首先，我们将75拆解为二进制，1001011，= 10^64*10^8*10^2*10^1
			4,我们先求10^1,然后根据10^1求10^2,再求得10^4,依次这样下去，得到10^64.
			5,然后累乘该乘的值。

*/
#include<iostream>
#include<cmath>
#include<bitset>
#include<string>
#include<vector>
using namespace std;
class QuickNPower
{
public:
	//计算k的N次方
	int getPower(int k, int N)
	{
		if(k == 0)
			return 0;
		if(N == 0)
			return 1;
		//防止溢出
		if(k>1000000007)
			k = k%1000000007;
		//存放k的2次放，4次放，8次方。。
		vector<long> arr;
		//存放N转换为二进制的形式
		vector<int> bit;
		//m为N次放，temp为k
		long long m = N,temp = k,res;
		while(m)
		{
			//在arr中依次放入，k，k^2,(k^2)^2,....，m可以转换为多少位二进制，这个k就要^2多少次
			arr.push_back(temp);
			//temp变为k^2
			temp*=temp;
			//防止溢出
			if(temp>1000000007)
				temp = temp%1000000007;
			//将m转为2进制，存入bit
			if(m%2)
				bit.push_back(1);
			else
				bit.push_back(0);
			m = m/2;
		}
		
		//根据bit里是0是1，判断要不要累乘对应位数的k次方
		res = 1;
		for(int i = 0;i<bit.size();i++)
		{
			//cout<< bit[i] << " "<< arr[i] << endl;	
			if(bit[i])
			{
				res *= arr[i];
				//cout << res << endl;
				if(res > 1000000007)
					res = res%1000000007;
			}
		}
		return res%1000000007;
	}
};
int main()
{
	QuickNPower Q;
	cout<<Q.getPower(2,14876069)<<endl;
	return 0;
}
