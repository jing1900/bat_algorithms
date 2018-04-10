/*
		问题：
			给定一个有序数组arr，再给定一个整数Num，请在arr中找到num这个数出现的最左边位置
		解题思路：
			假设数组为1 2 3 3 3 3 4 4 4 4 4 4 4 4 4，num为3
			1，在进行二分搜索之前，先假设一个全局变量res，用来标识最后一个找到3的位置。初始时res=-1，如果在遍历的过程中，一直没找到，则最后返回-1即可、
			2，首先找到中间的数，4，然后比较中间的数和num的大小，发现num是在数组的左边的，
			3，再找到左边的中间位置，3，第一次找到3，将res更新为当前的位置，
			4，但我们要找的是3出现最左边的位置，所以，当第一次出现3之后，对其左边的部分，继续二分，找到中间位置2
			5，此时2左边的内容一定是小于3的，因此，处理右半部分，2 3，继续进行二分搜索，找到另一个3，位置更新为2，
			6，此时，区间只剩一个数了，这是最后一次更新res

*/
#include<iostream>
#include<vector>
using namespace std;
class LeftMostPosition
{
public:
	//传入向量，向量长度和要找的元素
	int findLeftPos(vector<int> arr, int n, int num)
	{
		if(!n)
			return -1;
		int low = 0,high = n-1,mid;
		int res = -1;
		while(low<=high)
		{
			mid = low+(high - low)/2;
			//数组是有序的，如果mid处的值小于待查找元素，则元素在右半区间
			if(arr[mid]<num)
				low = mid +1;
			//若大于，则在左边
			else if(arr[mid]>num)
				high = mid-1;
			//如果恰好等，那么因为要找的是最左位置，再去左边看看有没有更左的
			else
			{
				res = mid;
				high = mid-1;
			}
		}
		return res;
	}
};

int main()
{
	int a[5] = {1,2,3,3,4};
	vector<int> arr(a,a+5);
	LeftMostPosition L;
	cout<<L.findLeftPos(arr,5,3)<<endl;
	return 0;
}
