/*
问题：
	给定一个整形数组，返回如果排序之后，相邻两数的最大差值。比如某数组排好序之后为 1 2 3 4 7 8 9，那么最大差值来自7-4
解题思路：
	这道题的最优解可以做到时间复杂度为O(N)，空间复杂度为O(N)，它的思想来自于桶排序的思想，但又不是真实的桶排序。如果数组长度为N的话，其空间复杂度可以做到O(N),而根数组中数值的范围没有关系。
	a,首先我们遍历数组，找到其中的最小值和最大值。比如这里的1和9
	b,在最小值和最大值之间，我们根据数组长度N，将其等量的分为N个区间。这里有7个数，因此区间分别为，（1-15/7）…(55/7,9),7个。
	c,我们将每个数值放入对应范围的桶中，其中最大值放在第N+1号桶中。这样以来，1号桶中有最小值，第N+1号桶中有最大值。
	d，桶有N+1个，而数值只有N个，因此，1号桶和N+1号桶之间必定有空桶；我们知道，桶内数据的差值，不会大于桶区间的大小。而空桶两侧的值，肯定会大于桶区间。
	e,因此，我们完全不用考虑来自一个桶内元素的差值，只需要考虑不同桶之间元素的差值。也就是后一个桶的最小值减去前一个桶的最大值。然后我们记录下这个最大的差值即可。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class MaxGap
{
public:
	int maxGap(vector<int> A,int n)
	{
		//新建桶，n+1个
		vector<vector<int> > B(n+1);
		//最大最小值，索引，最大间隔
		int max,min,i,j,maxGap;
		for(i =1,max = min = A[0];i<n;i++)
		{
			if(A[i]>max)
				max = A[i];
			if(A[i]<min)
				min = A[i];
		}
		//桶宽度
		float gap = 1.0*(max-min)/n;
		//将元素放入对应范围的桶中，最大值放在N+1号桶。
		for(i =0;i < n;i++)
		{
			//元素A[i]应该放在第几号桶
			j = (int)((A[i]-min)/gap);
			//如果该号桶为空，随便放//？？
			if(B[j].empty())
			{
				//两个是为了等下替换掉一个值
				B[j].push_back(A[i]);
				B[j].push_back(A[i]);
			}
			//如果该桶非空，则需要判断下，将大的值放在桶顶，小的值放在桶底
			//注意，这里我们存贮的只是每个桶内元素的最大值和最小值，分别在位置1和0
			else
			{	//将小的值放在0位置
				if(B[j][0]>A[i])
					B[j][0] = A[i];
				//将大的值放在1位置
				if(B[j][1]<A[i])
					B[j][1] = A[i];
			}
		}
		//计算最大间隔,i为桶号
		for(i = j =0,maxGap = 0;i<n;i = j)
		{
			//如果空桶，则下一个
			while(B[i].empty())
				i++;
			//得到该桶的最大值，在桶顶的位置。
			max = B[i][1];
			//j为桶i接下来的桶的索引，之间可能有空桶
			j = i+1;
			if(j < n+1)
			{
				while(B[j].empty())
					j++;
				if(j >= n+1)
					break;
				//得到接下来一个桶的最小值
				min = B[j][0];
				if(min-max>maxGap)
					maxGap = min - max;
			}
		}
		return maxGap;
	}
};
int main()
{
	int a[5]={1,2,5,4,6};
	vector<int> arr(a,a+5);
	MaxGap m;
	int c=m.maxGap(arr,5);
	cout<<c<<endl;
	return 0;
}
