/*
问题：
	给定一个数组 1 5 4 3 2 6 7，返回数组中需要排序的最短子数组长度。比如这里只有 5 4 3 2 需要排序，因此返回4
解题思路：
	这里的最优解时间复杂度为O(N)，空间复杂度为O（1）
	a,首先，从左到右遍历数组，同时，用一个额外的变量记录下遍历过程中遇到的最大值，
	b，然后我们只关注一种情况，就是记录的最大值大于当前遍历值得情况。然后记录下发生这种情况最右的位置。
	c，接下来，从右往左遍历数组，同时，用一个额外的变量记录下遍历过程中遇到的最小值，
	d，然后我们也只关注一种情况，就是记录的最小值小于当前遍历值得情况。然后记录下发生这种情况下最左的位置。
	e，然后最左，左右区间的这个范围，就是数组中需要排序的最短子数组
*/

#include<iostream>
#include<vector>
using namespace std;
class SubSequence
{
public:
	int shortSubSequence(vector<int> A,int n)
	{
		//初始化最大值为A[0],最小值为A[n-1],rd1为从左到右遍历，最大值大于当前值的最右位置
		//rd2为从右往左遍历，记录的最小值小于当前遍历值的情况的最左位置
		int max = A[0],min = A[n-1],i,rd1,rd2;
		//从位置1开始（0已经初始化为最大值），从左往后，找最大值，
		for(i = 1,rd1 =0;i<n;i++)
		{
			//找最大值
			if(A[i]>=max)
				max = A[i];
			//否则的话是，最大值大于当前值，最右位置索引挪至这里
			else
				rd1 = i;
		}
		//从位置n-2开始（n-1已经初始化为最小值），从右往左，找最小值
		for(i = n-2,rd2 = n-1;i>=0;i--)
		{
			//如果当前值比min小，则min替换为当前值
			if(A[i]<= min)
				min = A[i];
			//否则，min比当前小，最左索引挪至这里
			else
				rd2 =i;
		}
		//如果最右索引为0
		if(!rd1)
			return 0;
		else
			return rd1-rd2+1;
	}
};

int main()
{
	int a[6]={1,4,6,5,9,10};
	vector<int> b(a,a+6);
	SubSequence s;
	int d=s.shortSubSequence(b,6);
	cout<<d<<endl;
	return 0;
}
