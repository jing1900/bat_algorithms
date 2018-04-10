/*
		问题：
			给定一个有序循环数组arr，返回arr中的最小值。有序循环数组是指，有序数组左边任意长度的部分放到右边去，右边的部分拿到左边来。比如 1 2 3 3 4，是有序循环数组。4 1 2 3 3也是。
		解题思路：
			元素位置从0-N-1，L初始为0，R初始为N-1，
			1，如果L处的值小于R处的值，说明从L到R这一段是有序的，直接返回L即可，即是最小值
			2，如果L处的值大于等于R处的值，说明这一段里面是有循环过的。此时，拿mid与L比较，如果L处的值》M处的值，那么最小值肯定在L，M这一段区间上。如果arr M > arr L,那么最小值只会出现在m，R这一段区间上。则在右半部分继续二分查找
			3，有一种特殊情况，L，M，R处的值相等，这种情况下，只能用遍历的方法找到数组的最小值。

*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class FindMinInOrderLoopArray
{
public:
	//传入向量和向量长度，返回最小值
	int getMin(vector<int> arr,int n)
	{
		//向量为空，没有最小值位置
		if(arr.empty())
			exit(-1);
		//如果长度为1，或者是没有循环过得有序数组，直接返回位置0处的元素
		if(n == 1 || arr[0] < arr[n-1])
			return arr[0];
		int low = 0,high = n-1,mid;
		while(low< high)
		{
			mid = low + (high - low)/2;
			//一定是循环过得，如果low处的值大于mid处的值，那么最小值在low，mid这一段内
			if(arr[low]>arr[mid])
				high = mid;
			//如果mid处的值大于high处的值，那么最小值一定出现在m，high,这段区间上
			else if(arr[mid]>arr[high])
				low = mid+1;
			//low = mid = high
			else
				break;
		}
		//最后区间low，high重合的情况，最小值在low或high处。		
		if(low == high)
			return arr[low];
		//处理low == mid == high这种特殊情况
		int min = arr[low];
		while(low <= high)
		{
			if(arr[low]<min)
				min = arr[low];
			low++;
		}
		return min;
		
		
	}
};

int main()
{
	int a[3] = {2,1,2};
	vector<int> arr(a,a+3);
	FindMinInOrderLoopArray F;
	cout<<F.getMin(arr,3)<<endl;
	return 0;
}
