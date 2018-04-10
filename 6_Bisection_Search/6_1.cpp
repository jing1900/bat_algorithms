/*

		问题：
			给定一个无序数组，已知任意相邻的两个元素，值都不重复，请返回任意一个局部最小的位置，
			所谓的局部最小位置是指，如果arr[0]<arr[1],那么位置0就是一个局部最下的位置。如果位置i既不是最左也不是最右位置，那么只要满足位置i处的内容同时小于它左右两侧的值，那么i也是个局部最小的位置。
		解题思路：
			这里解题的思路仍可以用二分搜索，其时间复杂度为O（logN），这里序列虽然不是有序的，但它相邻元素间有不重复的性质。
			1，如果arr为空，或者长度为0，直接返回-1即可。这种情况下，局部最小元素是不存在的。
			2，如果arr长度为1，那么直接返回位置0，因为0是局部最小位置。
			3，如果arr大于1，那么先比较位置0和位置1，如果0较小，直接返回即可。同样的，如果位置n-1,小于n-2，也可以直接返回。
			4，如果两头的都不是局部最小位置，则有arr0 》 arr1，arrn-1》arrn-2，所以从最左边的位置往右看，趋势是往下的，从最后边的位置往左看，趋势也是向下的。此时我们可以看下中间点mid的情况，如果mid即小于它左边的数，又小于它右边的数，直接返回即可
			5，否则，如果mid的值比其右边的值小，比左边的值大，那么从右往左看mid处，它是向下的。那么在mid位置的左边，必然存在局部最小值，然后对左部分继续进行同样的二分搜索。同理。如果mid的值比左边的小，比右边的大，则从左往后看，它是向下的，那么在mid的右边，必然存在局部最小
			6，如果mid处的值即大于左边位置，又大于右边位置，那么证明其左右两侧都有局部最小。任选一边即可。
7，这道题是为了说明，二分搜索不一定是要在有序的数组中进行，只要在进行搜索时，能淘汰一半，保留一半即可。
*/
#include<iostream>
#include<vector>
using namespace std;
class LocalMin
{
public:
	//返回任意一个局部最小值出现的位置
	int getLocalMin(vector<int> arr)
	{
		//如果向量为空，没有局部最小位置
		if(arr.empty())
			return -1;
		//如果有一个元素，或者0处元素小于1处的
		if(arr.size() == 1 || arr[0] < arr[1])
			return 0;
		//判断最后一个位置的元素是否小于倒数第二个，若是，返回倒数第一个位置
		if(arr[arr.size()-1] < arr[arr.size()-2])
			return arr.size()-1;
		//否则，定义二分搜索的起始位置：low：1，high：size-2，和mid
		int low = 1,high = arr.size()-2,mid;
		//终止条件
		while(low <= high)
		{
			mid = low +(high-low)/2;
			//如果mid处的值比mid-1处大，则根据下降趋势，low到mid-1处一定有局部最小
			if(arr[mid]>arr[mid-1])
				high = mid-1;
			//如果mid处的值比mid+1处大，根据趋势，mid+1到high之间一定有局部最小
			else if(arr[mid] > arr[mid+1])
				low = mid+1;
			//否则，即比左边小又比右边小，是局部最小位置
			else
				return mid;
		}
		return -1;
	}
};

int main()
{
	int a[30]={10,5,10,5,0,1,2,4,7,3,2,9,5,4,6,5,10,6,7,10,9,4,3,7,2,9,5,4,6,10};
	vector<int> arr(a,a+30);
	LocalMin L;
	cout<<L.getLocalMin(arr)<<endl;
	return 0;
}












